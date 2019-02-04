///DIoT Skillsdev 2

// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

#define PIXEL_PIN A5                                        // IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 16
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int neoPixel = A5;
int buttonPin = D3;
unsigned long lastPublish = 0;

void setup() {
    
    pinMode( buttonPin , INPUT_PULLUP); // sets pin as input
    pinMode( neoPixel , OUTPUT );
  
    strip.begin();
    strip.show();   // Initialize all pixels to 'off'
    strip.numPixels();  // find the number of pixels
}

void loop() {

int buttonState = digitalRead( buttonPin );
    uint16_t i;
    uint32_t c = strip.Color(0, 255 , 255);
    uint32_t a = strip.Color(0, 0, 0);

// unsigned long now = millis();
// 	if ((now - lastPublish) >= 1000) {
// 		lastPublish = now;
// 		Particle.publish( "new-event", String(now) );

 if( buttonState == LOW )    // turn the LED On
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
    //for(i=strip.numPixels(); i >= 0 && i <=7;  --i) {
        strip.setPixelColor((16-i), a );
		    strip.show();
		    delay( 100 );
    }

}
}
