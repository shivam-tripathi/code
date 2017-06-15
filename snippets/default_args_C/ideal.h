#ifndef __IDEAL_H_ 
#define __IDEAL_H_ 

#include <stdio.h>

typedef struct {
	double pressure, moles, temp; 
} ideal_struct;

double ideal_pressure_base(ideal_struct);

#define ideal_pressure(...) ideal_pressure_base((ideal_struct) {.pressure=1, \
		.moles=1, .temp=273.15, __VA_ARGS__})

#endif // __IDEAL_H_
