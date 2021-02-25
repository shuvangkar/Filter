#ifndef _MEDIAN_FILTER_H
#define _MEDIAN_FILTER_H
#include <Arduino.h>

void medFilterSet(uint16_t *buf, uint8_t N);
void medFilterPush(uint16_t point);
uint16_t medFilterOut();
void medFilterPrint();

#endif
