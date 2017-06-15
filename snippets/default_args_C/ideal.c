#include "ideal.h"

double ideal_pressure_base(ideal_struct in){ 
	printf("Pressure: %f Moles: %f Temp: %f", in.pressure, in.moles, in.temp);
	return 8.314 * in.moles*in.temp/in.pressure;
}
