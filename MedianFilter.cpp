#include "MedianFilter.h"

uint16_t *_buf;
uint8_t _N;
uint8_t _index;
void medFilterSet(uint16_t *buf, uint8_t N)
{
  _buf = buf;
  _N = N;
  _index = 0;
}

void medFilterPrint()
{
  for (uint8_t i = 0; i < _N; i++)
  {
    Serial.print(_buf[i]); Serial.print(' ');
  }
  Serial.println();
}

void medFilterPush(uint16_t point)
{
  if (_index < _N)
  {
    _buf[_index] = point;
    _index++;
  }
  else
  {
    uint8_t lastIndex = _N - 1;
    for (uint8_t i = 0; i < lastIndex; i++)
    {
      _buf[i] = _buf[i + 1];
    }
    _buf[lastIndex] = point;
  }
  medFilterPrint();
}


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
uint16_t medFilterOut()
{
  qsort(_buf,_N,sizeof(uint16_t),cmpfunc);
  Serial.print(F("Sorted : "));
  medFilterPrint();
  uint16_t medIndex = (_N-1)/2;
  Serial.print(F("Median : "));Serial.println(_buf[medIndex]);
  return  _buf[medIndex];
}
