#include <Python/Python.h>
#include "ideal.h"

int main() {
	double t = 999999999.0; //ideal_pressure(.temp=100);
	printf("\n%f", ideal_pressure(.temp=t));
}
