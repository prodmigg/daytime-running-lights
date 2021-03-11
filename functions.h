void drl(){
  for(int i=0; i<=19; i++){
    //led frontali
    leds[i] = CRGB::White;  
    
    //led posteriori, rosso meno luminoso
    leds[20+i] = CRGB::Red;
  }
  FastLED.show();
}

void accensione(){
  // gioco di luci alla prima accensione del sistema

  for(int i = 0; i<=9; i++){
    leds[9-i] =  CRGB::White;
    leds[10+i] = CRGB::White;
    leds[30+i] = CRGB::Red;
    leds[29-i] = CRGB::Red;
    FastLED.show();
    FastLED.delay(40);
    leds[9-i] =  CRGB::Black;
    leds[10+i] = CRGB::Black;
    leds[30+i] = CRGB::Black;
    leds[29-i] = CRGB::Black;
    FastLED.delay(40);
  }

  for(int i = 0; i<=9; i++){
    leds[i]    = CRGB::White;
    leds[19-i] = CRGB::White;
    leds[39-i] = CRGB::Red;
    leds[20+i] = CRGB::Red;
    FastLED.show();
    FastLED.delay(40);
    leds[i]    = CRGB::Black;
    leds[19-i] = CRGB::Black;
    leds[39-i] = CRGB::Black;
    leds[20+i] = CRGB::Black;
    FastLED.delay(40);
  }

  for(int i = 0; i<=9; i++){
    leds[9-i]  = CRGB::White;
    leds[10+i] = CRGB::White;
    leds[30+i] = CRGB::Red;
    leds[29-i] = CRGB::Red;
    FastLED.show();
    FastLED.delay(40);
  }
}

void freccia(int sxdx){
   //freccia a scorrimento, si indica la direzione con una variabile e viene
   //riprodotto il corrispondente gioco di luci (frecce dinamiche a scorrimento)
  
  switch(sxdx){
    case 1: for(int i=0; i<=9; i++){        //freccia sinistra
              leds[9-i] =  CRGB(255,70,0);
              leds[30+i] = CRGB(255,70,0);
              FastLED.show();
              FastLED.delay(30);

            if(i==9){
              delay(100);
              for(int i=0; i<=9; i++){
                leds[i] =    CRGB::Black;
                leds[30+i] = CRGB::Black;
              }
            FastLED.show();
            FastLED.delay(350);
            }
            }
            break;
            
    case 2: for(int i=10; i<=19; i++){      //freccia destra
            leds[i] =    CRGB(255,70,0);
            leds[39-i] = CRGB(255,70,0);
            FastLED.show();
            FastLED.delay(30);
   
            if(i==19){
              delay(100);
              for(int i=10; i<=19; i++){
                leds[i] =    CRGB::Black;
                leds[39-i] = CRGB::Black;
              }
            FastLED.show();
            FastLED.delay(350);
            }
            }
            break;
            
    default:break;
  }
}

/*
void freno(){
  //luci posteriori più luminose per indicare la frenata
  
  for(int i=20; i<=39; i++){
    leds[i] = CRGB(255,0,0);
    FastLED.show();
  }
}

 void lampeggiante(){
  //lampeggianti di emergenza arancioni
  
   for(int j = 0; j<=3; j++){
      for (int i = 0; i<9 ; i++){
        leds[i] =    CRGB::Orange;
        leds[20+i] = CRGB::Orange;
      }
      FastLED.show();
      delay(10);
    
      for(int i = 0; i<9; i++){
        leds[i] =    CRGB::Black;
        leds[20+i] = CRGB::Black;
      }
      FastLED.show();
      delay(10);
    }
   for(int j = 0; j<=3; j++){
      for(int i = 0; i<=9; i++){
        leds[10+i] = CRGB::Orange;
        leds[30+i] = CRGB::Orange;
      }
      FastLED.show();
      delay(10);
    
      for(int i = 0; i<=9; i++){
        leds[10+i] = CRGB::Black;
        leds[30+i] = CRGB::Black;
      }
      FastLED.show();
      delay(10);
    }
      
}                                         */
