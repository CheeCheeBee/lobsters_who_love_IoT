// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

#define PIXEL_PIN A5                                          
#define PIXEL_COUNT 1
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int flexPin = A0;                                            
int flex = 0;                                         
int ledBrightness = 0;
int bright = 0;


void setup() 
{
    pinMode(flexPin, INPUT);                                 
 
    strip.begin();                                          
    strip.show();                                            
    delay( 100 );  
    
    Particle.variable("force", &flex, INT);

}

void loop()
{
    flex = analogRead(flexPin);
    
    if (flex < 500 && flex > 300) {
        strip.setPixelColor(0, 0, 0, 127);
        bright=0;
    } else if (flex > 500 && bright != 1) {
        brighten();
    } else if (flex < 300 && bright !=-1) {
        darken();
    }

}

void darken() 
{
    uint16_t i, j;
    
        for (j = 127; j > 25; j--) 
        {
        for (i = 0; i < strip.numPixels(); i++) 
        {
        strip.setPixelColor(i, 0, 0, j);
        }
        strip.show();
        delay(10);
        }
        delay(1500);
        bright = -1;
}

void brighten()
{
    uint16_t i, j;

        for (j = 127; j < 255; j++) 
        {
        for (i = 0; i < strip.numPixels(); i++) 
        {
        strip.setPixelColor(i, 0, 0, j);
        }
        strip.show();
        }
        delay(1500);
        bright=1;
}
