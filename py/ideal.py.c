#include <Python/Python.h>
#include <stdio.h>



static PyObject *ideal_py(PyObject *self, PyObject *args){ 
	double intemp;
	if (!PyArg_ParseTuple(args, "d", &intemp)) 
		return NULL;
	double out = ideal_pressure(.temp=intemp);
	return Py_BuildValue("d", out); 
}
