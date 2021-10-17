/* Luci a led per fanali composti da 10 led ciascuno
 * written by: Davide Maggini
 * dado.maggio44@gmail.com
 */
 
#include <FastLED.h>
#define LED_PIN     3 
#define NUM_LEDS    40
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define SX          11
#define DX          9
#define BRIGHTNESS  253

CRGB leds[NUM_LEDS]; 

#include "functions.h"

void setup() {
    delay(1000);
    Serial.begin(9600);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalPixelString);
    FastLED.setBrightness(BRIGHTNESS);
    pinMode(SX, INPUT_PULLUP);  //freccia sinistra
    pinMode(DX, INPUT_PULLUP);  //freccia destra
    accensione();
}

void loop()
{  
    
    if(digitalRead(SX) == LOW){
      Serial.println("Sinistra");
    freccia(1);
    }
    
    else if(digitalRead(DX) == LOW){
      Serial.println("Destra");
    freccia(2);
    }

    else{drl();}
    
    
}
