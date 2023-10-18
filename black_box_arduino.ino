const byte MODE_BUTTON = 3;
const byte BUTTON_TIMEOUT = 30;

const byte LED1 = 6;
const byte LED2 = 7;
const byte LED3 = 11;
const byte LED4 = 10;
const byte LED5 = 9;
const byte LED6 = 8;
const byte SPK = 4;

bool flag = false;
uint32_t btnTimer = 0;
byte currentMode = 0;
byte currentModeState = 0;
uint32_t lastStateChange = 0;

void turnLedOn(byte ledId) {
  byte brightness = 0;
  // if(ledId == LED3) {
  //   brightness = 1;
  // } 
  if(ledId == LED4) {
    brightness = 220;
  } 

  analogWrite(ledId, brightness);
}

void ledShine(byte ledId, byte brightness)
{
  int correctedBrightness = brightness;
  // if(ledId == LED1) {
  //   // correctedBrightness = 255 - pow(brightness, 2)/100;
  //   correctedBrightness = 170 + brightness;
  //   if(correctedBrightness > 255) {
  //     correctedBrightness = 255;
  //   }
  // }
  // if(ledId == LED2) {
  //   correctedBrightness = 50 + brightness;
  //   if(correctedBrightness > 120) {
  //     correctedBrightness = 120;
  //   }
  // }
  analogWrite(ledId, correctedBrightness);
}



void turnLedOff(byte ledId) {
  // Serial.println("led off:" + ledId);
  analogWrite(ledId, 255);
}

void updateLedsProgramm(byte currentMode) {
  Serial.print(currentMode);
  tone(SPK, 100, 50);
  currentModeState = 254;
  if(currentMode == 1) {
    turnLedOn(LED1);
    turnLedOn(LED2);
    turnLedOn(LED3);
    turnLedOn(LED4);
    turnLedOn(LED5);
    turnLedOn(LED6);
    return;
  }
  if(currentMode == 0 || currentMode == 2 || currentMode == 3 || currentMode == 4 || currentMode == 5) {
    turnLedOff(LED1);
    turnLedOff(LED2);
    turnLedOff(LED3);
    turnLedOff(LED4);
    turnLedOff(LED5);
    turnLedOff(LED6);
    lastStateChange = millis();
    if(currentMode == 1) {
      currentModeState = 210;
    }
    // if(currentMode == 4) {
    //   currentModeState = 2;
    // }
    return;
  }
}

void continueLedsProgramm(byte currentMode) {
  if(currentMode == 0) {
    if(millis() - lastStateChange < 30) {
      return;
    }
    lastStateChange = millis();

    currentModeState = currentModeState + 1;
    if(currentModeState > 254) {
      currentModeState = 210;
    }

      ledShine(LED1, currentModeState);
      // ledShine(LED2, currentModeState);
      // turnLedOff(LED2);
      // turnLedOn(LED3);
      // turnLedOff(LED4);
      // turnLedOn(LED5);
      // turnLedOff(LED6);    
    // if(random(1,3) == 2) {
    //   tone(SPK, 500, 60);
    //   turnLedOn(random(6, 11));
    // } else {
    //   tone(SPK, 100, 50);
    //   turnLedOff(random(6, 11));
    // }
  }

  if(currentMode == 2) {
    if(millis() - lastStateChange < 800) {
      return;
    }
    lastStateChange = millis();

    currentModeState = currentModeState + 1;
    if(currentModeState > 1) {
      currentModeState = 0;
    }
    if(currentModeState == 0) {
      turnLedOn(LED1);
      turnLedOff(LED2);
      turnLedOn(LED3);
      turnLedOff(LED4);
      turnLedOn(LED5);
      turnLedOff(LED6);
      tone(SPK, 800, 25);
    } else {
      turnLedOff(LED1);
      turnLedOn(LED2);
      turnLedOff(LED3);
      turnLedOn(LED4);
      turnLedOff(LED5);
      turnLedOn(LED6);
      tone(SPK, 400, 25);
    }
    return;
  }
  if(currentMode == 3) {
    if(millis() - lastStateChange < 180) {
      return;
    }
    lastStateChange = millis();

    currentModeState = currentModeState + 1;
    if(currentModeState > 5) {
      tone(SPK, 100, 30);
      currentModeState = 0;
    }

    if(currentModeState == 0) {
      tone(SPK, 150, 30);
      turnLedOn(LED1);
      turnLedOff(LED6);
    }

    if(currentModeState == 1) {
      tone(SPK, 200, 30);
      turnLedOn(LED2);
      turnLedOff(LED1);
    }

    if(currentModeState == 2) {
      tone(SPK, 250, 30);
      turnLedOn(LED3);
      turnLedOff(LED2);
    }

    if(currentModeState == 3) {
      tone(SPK, 300, 30);
      turnLedOn(LED4);
      turnLedOff(LED3);
    }

    if(currentModeState == 4) {
      tone(SPK, 350, 30);
      turnLedOn(LED5);
      turnLedOff(LED4);
    }

    if(currentModeState == 5) {
      tone(SPK, 400, 30);
      turnLedOn(LED6);
      turnLedOff(LED5);
    }

    return;
  }

  if(currentMode == 4) {
    if(millis() - lastStateChange < 250) {
      return;
    }
    lastStateChange = millis();

    currentModeState = currentModeState + 1;
    if(currentModeState > 3) {
      currentModeState = 0;
    }

    if(currentModeState == 0) {
      tone(SPK, 300, 50);
      turnLedOn(LED3);
      turnLedOn(LED4);
    }

    if(currentModeState == 1) {
      tone(SPK, 400, 50);
      turnLedOn(LED2);
      turnLedOn(LED5);
    }

    if(currentModeState == 2) {
      tone(SPK, 500, 50);
      turnLedOn(LED1);
      turnLedOn(LED6);
    }

    if(currentModeState == 3) {
      turnLedOff(LED1);
      turnLedOff(LED2);
      turnLedOff(LED3);
      turnLedOff(LED4);
      turnLedOff(LED5);
      turnLedOff(LED6);
    }

    return;
  }

  if(currentMode == 5) {
    if(millis() - lastStateChange < 200) {
      return;
    }
    lastStateChange = millis();

    currentModeState = currentModeState + 1;
    if(currentModeState > 11) {
      currentModeState = 0;
    }

    if(currentModeState == 0) {
      tone(SPK, 150, 30);
      turnLedOn(LED1);
    }

    if(currentModeState == 1) {
      tone(SPK, 200, 30);
      turnLedOn(LED2);
    }

    if(currentModeState == 2) {
      tone(SPK, 250, 30);
      turnLedOn(LED3);
    }

    if(currentModeState == 3) {
      tone(SPK, 300, 30);
      turnLedOn(LED4);
    }

    if(currentModeState == 4) {
      tone(SPK, 350, 30);
      turnLedOn(LED5);
    }

    if(currentModeState == 5) {
      tone(SPK, 400, 30);
      turnLedOn(LED6);
    }

    if(currentModeState == 6) {
      tone(SPK, 450, 30);
      turnLedOff(LED6);
    }

    if(currentModeState == 7) {
      tone(SPK, 400, 30);
      turnLedOff(LED5);
    }

    if(currentModeState == 8) {
      tone(SPK, 300, 30);
      turnLedOff(LED4);
    }

    if(currentModeState == 9) {
      tone(SPK, 250, 30);
      turnLedOff(LED3);
    }

    if(currentModeState == 10) {
      tone(SPK, 200, 30);
      turnLedOff(LED2);
    }

    if(currentModeState == 11) {
      tone(SPK, 150, 30);
      turnLedOff(LED1);
    }

    return;
  }
  
}

void setup() {

  Serial.begin(9600);
  pinMode(MODE_BUTTON, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);   
  pinMode(LED2, OUTPUT);   
  pinMode(LED3, OUTPUT);   
  pinMode(LED4, OUTPUT);   
  pinMode(LED5, OUTPUT);   
  pinMode(LED6, OUTPUT);  
  pinMode(SPK, OUTPUT); 

}

void loop() {
  // читаем инвертированное значение для удобства
  bool modeChanged = false;
  bool btnState = !digitalRead(MODE_BUTTON);
  if (btnState && !flag && millis() - btnTimer > BUTTON_TIMEOUT) {
    flag = true;
    btnTimer = millis();
    Serial.println("press");
    currentMode = currentMode + 1;
    if(currentMode > 5) {
      currentMode = 0;
    }
    modeChanged = true;
  }
  if (!btnState && flag && millis() - btnTimer > BUTTON_TIMEOUT) {
    flag = false;
    btnTimer = millis();
    //Serial.println("release");
  }

  if(modeChanged) {
    updateLedsProgramm(currentMode);
  } else {
    continueLedsProgramm(currentMode);
  }
  
  // if(btnState == false) {
  //   digitalWrite(LED1, HIGH);
  // } else {
  //   digitalWrite(LED1, LOW);
  // }




  // analogWrite(11, 255);



}