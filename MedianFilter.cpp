#include "MedianFilter.h"

uint16_t *_buf;
uint8_t _N;
uint8_t _index;
void medFilterSet(uint16_t *buf, uint8_t N)
{
  _bufPtr = buf;
  _N = N;
  _index = 0;
}

void medFilterPrint()
{
  Serial.print(F("Samples : "));
  for(uint8_t i = 0; i< _N; i++)
  {
    Serial.print(_buf[i]); Serial.print(' ');
  }
  Serial.println();
}

void medFilterPush(uint16_t point)
{
  if(_index < _N)
  {
    _buf[_index] = point;
    _index++;
  }
  
  uint8_t lastIndex = _N-1;
  for(uint8_t i = 0; i< lastIndex; i++)
  {
    _buf[i] = _buf[i+1];
  }
  _buf[lastIndex] = point;
}

uint16_t medFilterGet(void)
{
  
}
