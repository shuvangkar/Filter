#ifndef _MEDIAN_FILTER_H
#define _MEDIAN_FILTER_H
#include <stdint.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
void medFilterSet(uint16_t *buf, uint8_t N);
void medFilterPush(uint16_t point);
uint16_t medFilterOut();

extern uint16_t *_buf;
#ifdef __cplusplus
}
#endif

#endif
