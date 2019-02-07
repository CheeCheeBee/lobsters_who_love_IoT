// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

long lastPublished=0;
long lastPublishedAt=0;
int publishAfter=10000;
int neoPixel = A5;
int buttonPin = D3;
uint16_t i;
uint32_t c = strip.Color(0, 0, 255);
uint32_t a = strip.Color(0, 0, 0);


#define PIXEL_PIN A5   // IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 29
#define PIXEL_TYPE WS2812

 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


void setup()
{
    
    pinMode( buttonPin, INPUT_PULLUP);
    pinMode( neoPixel, OUTPUT );
  
    strip.begin();
    strip.show();
    strip.numPixels();

    Particle.subscribe(  "plantr/team10/2019/" , handleSharedEvent );
    
}

void loop()
{   
    int buttonState = digitalRead( buttonPin );
    if(buttonState == LOW)
    {
    publishMyEvent();
    }
    delay(100);
}

void publishMyEvent()
{
    if( lastPublishedAt + publishAfter < millis() )
    {
    String eventName = "plantr/team10/2019/" + System.deviceID();
    Particle.publish( eventName, "data goes here" );
    lastPublishedAt = millis();
  }

}

void handleSharedEvent(const char *event, const char *data)
{
    String eventName = String( event );
    String deviceID = System.deviceID();
    
    
    if( eventName.indexOf( deviceID ) != -1 ){
    return;
    
    }
    else
    {

    digitalWrite( neoPixel, HIGH);

    for(i=0; i < strip.numPixels(); ++i)
    {
        strip.setPixelColor(i, c );
		    strip.show();
		    delay( 100 );
		    
    }
    for(i=0; i < strip.numPixels(); ++i) {
    strip.setPixelColor((29-i), a );
    strip.show();
    delay( 100 );

 }
    

}
}
