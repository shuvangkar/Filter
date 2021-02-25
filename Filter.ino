#include "MedianFilter.h"
#define SAMPLES 5
uint16_t data[SAMPLES];

void setup() 
{
  Serial.begin(9600);
  medFilterSet(data,SAMPLES);
  Serial.println(F("Setup done"));
}

void loop() 
{
  medFilterPush(random(1,30));
  delay(2000);
  medFilterPush(random(1,30));
  delay(2000);
  medFilterPush(random(1,30));
  delay(2000);
  medFilterPush(random(1,30));
  delay(2000);
  medFilterPush(random(1,30));
  delay(2000);
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(2000);
  
  medFilterPush(random(1,30));
  medFilterOut();
  delay(20000);
}
