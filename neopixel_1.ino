// SKILLS DEV 3 
// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

#define PIXEL_PIN A5                                        // IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 29
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int neoPixel = A5;
int buttonPin = D3;
int brightness = 0;
unsigned long now = 0;
unsigned long lastPublish = 0;
unsigned long lastFade = 0;

int ledsHalfOff = 1 * 60 * 1000; // 1 minute
int ledsRed = 30 * 1000; // 30 seconds
int ledsFlash15s = 15 * 1000; // 15 seconds
int ledsFlashFiveTimes = 0 * 1000;  // Zero seconds

uint16_t i;
uint32_t c = strip.Color( 255, 0, 0 ); 
uint32_t d = strip.Color( 0, 0, 0 ); 

void setup()
{
    
    pinMode( buttonPin, INPUT_PULLUP); // sets pin as input
    pinMode( neoPixel, OUTPUT );
  
    strip.begin();
    strip.show();   // Initialize all pixels to 'off'
    strip.numPixels();  // find the number of pixels
    
}

void loop() {
    
    int buttonState = digitalRead( buttonPin );
    brightness = strip.Color(255, 255, 255); 
    
    unsigned long now = millis();
	if ((now - lastPublish) >= 1000) 
	{
		lastPublish = now;
		Particle.publish( "start", String(now));
	}

    if( buttonState == LOW && ((now - lastPublish) >= 10000))   
    {
    
        lastPublish = now;
		Particle.publish( "brightness", String(now));
    
        digitalWrite( neoPixel, HIGH);  // turn the LED On
        for(i=0; i < strip.numPixels(); ++i) // incrememnt up
        {
        strip.setPixelColor(i, c ); // pixel number, brightness
		strip.show();
		delay( 100 );
        }
    }
    

    if ((now + ledsHalfOff) >= 6000)
	{
		lastPublish = now;
		Particle.publish( "leds half off", String(now));
	
    for(i=0; i < strip.numPixels(); ++i) // incrememnt up
    {
        strip.setPixelColor((29-14), c );
		strip.show();
		delay( 100 );
		
		strip.setPixelColor((13-0), d ); 
		strip.show();
		delay( 100 );
    }
	}
    

    if((now + ledsRed) >= 9000)
	{
		lastPublish = now;
		Particle.publish( "leds red", String(now));
	
    for(i=0; i < strip.numPixels(); ++i)
    {
        strip.setPixelColor(i, c ); // pixel number, brightness
		strip.show();
		delay( 0 );
    }
	}

    if ((now + ledsFlash15s) >= 10500)
	{
		lastPublish = now;
		Particle.publish( "flash 15", String(now));
   
   for(i=0; i < 5; ++i)
    {	
        digitalWrite( neoPixel, HIGH);
        strip.show();
	    delay( 50 );

        digitalWrite( neoPixel, LOW);
        strip.show();
	    delay( 50 );
    }
	}
}
      
        
    
