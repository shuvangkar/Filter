#ifndef _MEDIAN_FILTER_H
#define _MEDIAN_FILTER_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

typedef enum filter_type_t
{
	MEDIAN,
	DECIMATION
}filter_type_t;

#ifdef __cplusplus
extern "C" {
#endif
void medFilterSet(uint16_t *buf, uint8_t N);
void medFilterPush(uint16_t point);
uint16_t medFilterOut(filter_type_t type);
void medPrintSamples(uint16_t *data, uint8_t samples);

extern uint16_t *_buf;
#ifdef __cplusplus
}
#endif

#endif
