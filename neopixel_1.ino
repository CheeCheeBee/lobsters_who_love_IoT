// SKILLS DEV 3 
// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

#define PIXEL_PIN A5   // IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 29
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int neoPixel = A5;
int buttonPin = D3;


void setup() {
    
    pinMode( buttonPin, INPUT_PULLUP);
    pinMode( neoPixel, OUTPUT );
  
    strip.begin();
    strip.show();
    strip.numPixels();
}

void loop() {

int buttonState = digitalRead( buttonPin );
    uint16_t i;
    uint32_t c = strip.Color(0, 0, 255);
    uint32_t a = strip.Color(0, 0, 0);

 if( buttonState == LOW )
 {
    digitalWrite( neoPixel, HIGH);

    for(i=0; i < strip.numPixels(); ++i)
    {
        strip.setPixelColor(i, c );
		    strip.show();
		    delay( 100 );
		    
    }
    }else if(buttonState == HIGH)
    {
    
    for(i=0; i < strip.numPixels(); ++i) {
        strip.setPixelColor((29-i), a );
		    strip.show();
		    delay( 100 );
    }

}
}
