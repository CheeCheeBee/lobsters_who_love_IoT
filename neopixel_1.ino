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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VISUALLY, CONCEPTUALLY WHAT I WANT TO HAVE HAPPEN, doesn't work >> WILL PUT IN TIME (MILLIS) SOON

void loop(){

	// declare color variables	
	// check time (is the timer a count down or timer up?)


////////////////////////////////////////////////////////////////////////////////////////////////

// TURN ON ALL COLOR STRIP FOR 2 MINUTES

if (currentTime < 120000){  // 120 seconds
	digital Write (neoPixlel, HIGH);

		for(i=0; i < strip.numPixels(); ++i) 
    	{
        	strip.setPixelColor(i, c );
		strip.show();
		delay( 0 );
	}


////////////////////////////////////////////////////////////////////////////////////////////////

// AFTER 1 MINUTE, TURN HALF OF THE PIXELS TO RED

} else if (currentTime < 60000 && currentTime > 15000){ 	// 60s-15 seconds	
		for(i=0; i < 29 && > 14; --i) // increment up
	{
		strip.setPixelColor( i, a ); 
		strip.show();
		delay( 0 );
	}
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////

// AFTER

} else if (currentTime < 15000){ 		// 30-15 seconds
	digitalWrite( neoPixel, HIGH);  // turn the LED On
		
		for(i=0; i < strip.numPixels(); ++i) // incrememnt up
	{
	strip.setPixelColor(i, a ); // pixel number, brightness
		 strip.show();
		delay( 0 );
	}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////

}else if (currentTime <=1500 && current = 0){
	digitalWrite( neoPixel, HIGH);  // turn the LED On
		    strip.show();
		    delay( 5000 );
	digitalWrite( neoPixel, LOW);  // turn the LED off
		    strip.show();
		    delay( 5000 );
