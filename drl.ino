/* Luci a led per fanali composti da 10 led ciascuno
 * written by: Davide Maggini
 * dado.maggio44@gmail.com
 */
 
#include <FastLED.h>
#define LED_PIN     7 
#define NUM_LEDS    40
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define BRIGHTNESS  240

CRGB leds[NUM_LEDS]; 

#include "functions.h"


void setup() {
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalPixelString);
    FastLED.setBrightness(BRIGHTNESS);
    pinMode(2, INPUT_PULLUP);  //freccia sinistra
    pinMode(6, INPUT_PULLUP);  //freccia destra
    accensione();
}

void loop()
{   
    int a;
    
    if(digitalRead(6) == HIGH)
    a = 0;
    
    if(digitalRead(2) == HIGH)
    a = 1;
    

    switch(a){

      case 0: freccia(2);
                break;

      case 1: freccia(1);
                break;

      default:  drl();
                break;
    }
}
