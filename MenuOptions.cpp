#include "myheader.h"

void showMenu() {
        Serial.println("***** Mode Menu System *****\n");
        Serial.println("Enter mode of choice:");
        Serial.println("1. Blink LED Mode");
        Serial.println("2. LED Dimmer");
        Serial.println("3. RGB Dimmer");
    }

void getUserInput() {
    char userInput = {};

    if (Serial.available() > 0) {
        userInput = Serial.read();
        if (userInput == '\n' || userInput == '\r') {
            return;
        }

        switch(userInput) {
            case '1': {
                currentMode = 1;
                menuDisplayed = false;
                break;
            }
            case '2': {
                currentMode = 2;
                menuDisplayed = false;
                break;
            }
            case '3': {
                currentMode = 3;
                menuDisplayed = false;
                break;
            }
            default: {
                Serial.println("Invalid input! Enter 1, 2, or 3.");
                break;
            }
        }

        while (Serial.available() > 0) {
            Serial.read(); // flush the extra characters.
        }
    }
}