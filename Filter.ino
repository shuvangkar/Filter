#include "MedianFilter.h"

void bufPrint(uint16_t *ptr, uint8_t N);
#define SAMPLES 7
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
  Serial.print(F("Unsorted : "));
  bufPrint(_buf,SAMPLES);
  uint16_t med = medFilterOut();
  //  Serial.print(F("Sorted : "));
//  medFilterPrint(tempBuf);
  Serial.print(F("Median : "));Serial.println(med);
  delay(2000);
}

void bufPrint(uint16_t *ptr, uint8_t N)
{
  for (uint8_t i = 0; i < N; i++)
  {
    Serial.print(ptr[i]); Serial.print(' ');
  }
  Serial.println();
}
