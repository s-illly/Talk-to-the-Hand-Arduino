#include <Adafruit_NeoPixel.h>

#define LED_STRIP_1_DI_PIN 3 // Digital pin connected to the LED strip
#define PIN_1 3 
#define LEDS_STRIP1 7

#define LED_STRIP_2_DI_PIN 5
#define PIN_2 5
#define LEDS_STRIP2 7

#define LED_STRIP_3_DI_PIN 4
#define PIN_3 4
#define LEDS_STRIP3 7

#define LED_STRIP_4_DI_PIN 2
#define PIN_4 2
#define LEDS_STRIP4 7

#define LED_STRIP_5_DI_PIN 7
#define PIN_5 7
#define LEDS_STRIP5 4

#define LED_STRIP_6_DI_PIN 6
#define PIN_6 6
#define LEDS_STRIP6 8


Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LEDS_STRIP1, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(LEDS_STRIP2, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(LEDS_STRIP3, PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(LEDS_STRIP4, PIN_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(LEDS_STRIP5, PIN_5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(LEDS_STRIP6, PIN_6, NEO_GRB + NEO_KHZ800);

String fullWord;

const int motorPin = 9;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);

  strip1.begin();
  strip1.show(); // Initialize to 'off'

  strip2.begin();
  strip2.show(); 

  strip3.begin();
  strip3.show(); 

  strip4.begin();
  strip4.show(); 

  strip5.begin();
  strip5.show();

  strip6.begin();
  strip6.show();
  
  pinMode(motorPin, OUTPUT);

}

void turnOffStrip(Adafruit_NeoPixel &strip) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // Set color off
  }
  strip.show();
}

// Function to turn on a specific LED in a NeoPixel strip
void turnOnLED(Adafruit_NeoPixel &strip, int index) {
  if (index >= 0 && index < strip.numPixels()) {
    strip.setPixelColor(index, strip.Color(255, 0, 0)); 
    strip.show();
  }
}

void  loop() {
  while (!Serial.available());
  fullWord = Serial.readString();
  fullWord.toLowerCase();
  Serial.print(fullWord);
  for(int i = 0; i < fullWord.length(); i++){
    char currentChar = fullWord[i];

    if (currentChar == 'a') {
      turnOnLED(strip5, 0);
      delay(2000);
      turnOffStrip(strip5);
          
          }    
    else if (currentChar == 'b') {
      turnOnLED(strip2, 1);
      turnOnLED(strip2, 2);
      turnOnLED(strip2, 3);
      turnOnLED(strip3, 2);
      delay(2000);
      turnOffStrip(strip2);
      turnOffStrip(strip3);

          }
    else if (currentChar == 'c') {
      for (int i = 0; i < 8; i++) {
        turnOnLED(strip6, i);
        delay(400); 
        turnOffStrip(strip6);
        delay(25);  
        }
    }
    else if (currentChar == 'd') {
      turnOnLED(strip1, 4);
      turnOnLED(strip1, 6);
      delay(2000);
      turnOffStrip(strip1);

    }
    else if (currentChar == 'e') {
      turnOnLED(strip1, 6);
      delay(2000);
      turnOffStrip(strip1);

    }
    else if (currentChar == 'f') {
      turnOnLED(strip6, 5);
      turnOnLED(strip6, 6);
      delay(2000);
      turnOffStrip(strip6);

    }
    else if (currentChar == 'g') {
      turnOnLED(strip2, 1);
      turnOnLED(strip2, 2);
      turnOnLED(strip2, 3);
      turnOnLED(strip3, 1);
      turnOnLED(strip3, 2);
      turnOnLED(strip3, 3);
      turnOnLED(strip4, 1);
      turnOnLED(strip4, 2);
      turnOnLED(strip4, 3);
      delay(2000);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'h') {
      for (int i = 0; i < 7; i++) {
        turnOnLED(strip1, i);
        turnOnLED(strip2, i);
        turnOnLED(strip3, i);
        turnOnLED(strip4, i);
        
        delay(400); 

        turnOffStrip(strip1);
        turnOffStrip(strip2);
        turnOffStrip(strip3);
        turnOffStrip(strip4);

        delay(25); 
      }

    }
    else if (currentChar == 'i') {
      turnOnLED(strip2, 6);
      delay(2000);
      turnOffStrip(strip2);

    }
    else if (currentChar == 'j') {
      for (int i = 7; i >= 0; i--) {
        turnOnLED(strip2, i);
        
        delay(400); 

        turnOffStrip(strip2);

        delay(25); 
      }
      turnOnLED(strip1, 0);
      delay(400);
      turnOffStrip(strip1);
      delay(25);
            
      for (int j = 3; j >= 0; j--) {
        turnOnLED(strip5, j);
        
        delay(400);

        turnOffStrip(strip5);

        delay(25); 
      }         
    }
    else if (currentChar == 'k') {
      turnOnLED(strip1, 4);
      delay(2000);
      turnOffStrip(strip1);

    }
    else if (currentChar == 'l') {
      turnOnLED(strip1, 1);
      turnOnLED(strip2, 1);
      turnOnLED(strip3, 1);
      turnOnLED(strip4, 1);
      delay(2000);
      turnOffStrip(strip1);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'm') {
      turnOnLED(strip1, 1);
      turnOnLED(strip1, 2);
      turnOnLED(strip1, 3);
      turnOnLED(strip2, 1);
      turnOnLED(strip2, 2);
      turnOnLED(strip2, 3);
      turnOnLED(strip3, 1);
      turnOnLED(strip3, 2);
      turnOnLED(strip3, 3);
      turnOnLED(strip4, 1);
      turnOnLED(strip4, 2);
      turnOnLED(strip4, 3);
      delay(2000);
      turnOffStrip(strip1);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'n') {
      turnOnLED(strip1, 1);
      turnOnLED(strip1, 2);
      turnOnLED(strip2, 1);
      turnOnLED(strip2, 2);
      turnOnLED(strip3, 1);
      turnOnLED(strip3, 2);
      turnOnLED(strip4, 1);
      turnOnLED(strip4, 2);
      delay(2000);
      turnOffStrip(strip1);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'o') {
      turnOnLED(strip3, 6);
      delay(2000);
      turnOffStrip(strip3);

    }
    else if (currentChar == 'p') {
      turnOnLED(strip1, 6);
      turnOnLED(strip6, 7);
      delay(2000);
      turnOffStrip(strip1);
      turnOffStrip(strip6);
    }
    else if (currentChar == 'q') {
      turnOnLED(strip5, 3);
      turnOnLED(strip6, 2);
      delay(2000);    
      turnOffStrip(strip5);
      turnOffStrip(strip6);
    }
    else if (currentChar == 'r') {
      turnOnLED(strip3, 1);
      turnOnLED(strip3, 2);
      turnOnLED(strip3, 3);
      turnOnLED(strip4, 3);
      delay(2000);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 's') {
      
      digitalWrite(motorPin, HIGH);
      turnOnLED(strip4, 4);
      delay(2000);
      turnOffStrip(strip4);
      digitalWrite(motorPin, LOW);

    }
    else if (currentChar == 't') {
      turnOnLED(strip4, 2);
      delay(2000);
      turnOffStrip(strip4);
    }
    else if (currentChar == 'u') {
      turnOnLED(strip4, 6);
      delay(2000);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'v') {
      turnOnLED(strip2, 1);
      turnOnLED(strip3, 1);
      turnOnLED(strip4, 1);
      turnOnLED(strip2, 3);
      turnOnLED(strip3, 3);
      turnOnLED(strip4, 3);
      delay(2000);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }
    else if (currentChar == 'w') {
      turnOnLED(strip1, 4);
      turnOnLED(strip1, 5);
      turnOnLED(strip1, 6);
      turnOnLED(strip2, 4);
      turnOnLED(strip2, 5);
      turnOnLED(strip2, 6);
      turnOnLED(strip3, 4);
      turnOnLED(strip3, 5);
      turnOnLED(strip3, 6);
      turnOnLED(strip4, 4);
      turnOnLED(strip4, 5);
      turnOnLED(strip4, 6);
      turnOnLED(strip6, 5);
      turnOnLED(strip6, 6);
      turnOnLED(strip6, 7);

      delay(2000);

      turnOffStrip(strip1);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);
      turnOffStrip(strip6);

    }
    else if (currentChar == 'x') {
      turnOnLED(strip6, 6);
      delay(2000);
      turnOffStrip(strip6);

    }
    else if (currentChar == 'y') {
      turnOnLED(strip1, 1);
      delay(2000);
      turnOffStrip(strip1);

    }
    else if (currentChar == 'z') {
      turnOnLED(strip1, 3);
      turnOnLED(strip2, 3);
      turnOnLED(strip3, 3);
      turnOnLED(strip4, 3);
      delay(2000);
      turnOffStrip(strip1);
      turnOffStrip(strip2);
      turnOffStrip(strip3);
      turnOffStrip(strip4);

    }                    
    delay(1000);
            
  }        
}