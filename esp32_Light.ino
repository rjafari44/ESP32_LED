#include "myheader.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    switch(currentMode) {
        case MENU: {
            if (!menuDisplayed) {
                showMenu();
                menuDisplayed = true;
            }

            getUserInput();
            break;
        }
        
        case BLINK: {
            if (!modeInitialized[0]) {
                blink_setup();
                modeInitialized[0] = true;
            }

            blink_loop();
            break;
        }

        case DIM_BASIC: {
            if (!modeInitialized[1]) {
                // dimLED_setup();
                modeInitialized[1] = true;
            }

            // dimLED_loop();
            break;
        }

        case DIM_RGB: {
            if (!modeInitialized[2]) {
                // dimRGB_setup();
                modeInitialized[2] = true;
            }

            // dimRGB_loop();
            break;
        }

        default: {
            currentMode = 0;
            menuDisplayed = false;
            break;
        }
    }
}
