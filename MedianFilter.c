#include "MedianFilter.h"
#include "Serial.h"

uint16_t *_buf;
uint8_t _N;
uint8_t _index;

uint16_t average(uint16_t *samples, uint8_t N);

void medFilterSet(uint16_t *buf, uint8_t N)
{
  _buf = buf;
  _N = N;
  _index = 0;
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
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void medPrintSamples(uint16_t *data, uint8_t samples)
{
	for (uint8_t i = 0; i< samples; i++)
	{
		SerialPrintU16(data[i]); SerialPrintF(P("  "));
	}
	SerialPrintF(P("\r\n"));
	
}

uint16_t average(uint16_t *samples, uint8_t N)
{
	uint16_t sum = 0;
	for(uint8_t i = 0; i<N; i++)
	{
		sum += samples[i];
	}
	sum = sum/N;
	return sum;
}

uint16_t medFilterOut(filter_type_t type)
{

  //medPrintSamples(_buf,_N);
  uint16_t tempBuf[_N];
  memcpy(tempBuf,_buf,_N*sizeof(uint16_t));
  
  uint16_t out = 0;
  switch(type)
  {
	  case MEDIAN:
		qsort(tempBuf,_N,sizeof(uint16_t),cmpfunc);
		out = tempBuf[(_N-1)/2];
	  break;
	  case DECIMATION:
		out = average(tempBuf,_N);
	  break;
  } 
  //SerialPrintF(P("Filter out : ")); SerialPrintlnU16(out);
  return out;
  
  /*
  qsort(tempBuf,_N,sizeof(uint16_t),cmpfunc);
  //medPrintSamples(tempBuf,_N);
  uint16_t medIndex = (_N-1)/2;
  uint16_t avg = average(tempBuf,_N);
  SerialPrintF(P("Avg : ")); SerialPrintlnU16(avg);
  return  tempBuf[medIndex];
  */
}
