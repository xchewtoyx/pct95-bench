/* from random import randint */

#include "Python.h"

/******************************************************
 * def partition(a, start, end, pivot_index):
 *   low = start
 *   high = end -1
 *   pivot_value = a[pivot_index]
 *   a[pivot_index] = a[end]
 *   while True:
 *       while low <= high and a[low] < pivot_value:
 *           low = low + 1
 *       while low <= high and a[high] >= pivot_value:
 *           high = high - 1
 *       if low > high:
 *           break
 *       a[low], a[high] = a[high], a[low]
 *   a[end] = a[low]
 *   a[low] = pivot_value
 *   return low
 ******************************************************/
Py_ssize_t
partition(PyListObject *list, Py_ssize_t start, Py_ssize_t end, 
	  Py_ssize_t pivot_pos)
{
  PyObject *pivot_value, *low_value;
  Py_ssize_t low, high;
  low = start;
  high = end - 1;
  pivot_value = PyList_GET_ITEM(list, pivot_pos);
  Py_INCREF(pivot_value);
  PyList_SET_ITEM(list, pivot_pos, PyList_GET_ITEM(list, end));
  for (;;) {
    while (low <= high && PyObject_RichCompareBool(PyList_GET_ITEM(list, low),
						   pivot_value, Py_LT) > 0)
      low++;
    while (low <= high && PyObject_RichCompareBool(PyList_GET_ITEM(list, high),
						   pivot_value, Py_GE) > 0)
      high--;
    if (low > high)
      break;
    low_value = PyList_GET_ITEM(list, low);
    Py_INCREF(low_value);
    PyList_SET_ITEM(list, low, PyList_GET_ITEM(list, high));
    PyList_SET_ITEM(list, high, low_value);
    Py_DECREF(low_value);
  }
  PyList_SET_ITEM(list, end, PyList_GET_ITEM(list, low));
  PyList_SET_ITEM(list, low, pivot_value);
  Py_DECREF(pivot_value);
  return low;
}

/*
def qselect_range(tosort, start, end, target):
    if end - start > 0:
        pivot_index = partition(tosort, start, end, randint(start, end))
        if target == pivot_index:
            return pivot_index
        if (target < pivot_index):
            return qselect_range(tosort, start, pivot_index -1, target)
        if (target > pivot_index):
            return qselect_range(tosort, pivot_index +1, end, target)
    return start

*/

Py_ssize_t
qselect_range(PyListObject *list, Py_ssize_t start, Py_ssize_t end, 
	      Py_ssize_t target)
{
  Py_ssize_t pivot_index, randint;
  if (end - start > 0) {
    randint = rand()%(end-start);
    pivot_index = partition(list, start, end, start+randint);
    if (target == pivot_index)
      return pivot_index;
    if (target < pivot_index)
      return qselect_range(list, start, pivot_index-1, target);
    if (target > pivot_index)
      return qselect_range(list, pivot_index+1, end, target);
  }
  return start;
}

PyObject *
qselect(PyObject *self, PyObject *args)
{
  PyObject *list, *target, *target_value;
  Py_ssize_t target_pos;

  if (!PyArg_UnpackTuple(args, "qselect", 2, 2, &list, &target))
    return NULL;
  
  if (!PyList_Check(list)) {
    PyErr_SetString(PyExc_TypeError, "List Argument must be a list");
    return NULL;
  }

  if (!PyInt_Check(target)) {
    PyErr_SetString(PyExc_TypeError, "target argument must be an integer");
    return NULL;
  }
  target_pos = PyInt_AsSsize_t(target);

  qselect_range((PyListObject *)list, (Py_ssize_t)0, 
		PyList_GET_SIZE(list)-1, target_pos);
  target_value = PyList_GET_ITEM(list, target_pos);
  Py_INCREF(target_value);
  return target_value;
}

PyDoc_STRVAR(qselect_doc, "Find the 'target'th largest value in the list");

static PyMethodDef qselect_methods[] = {
  {"qselect", (PyCFunction)qselect,
   METH_VARARGS, qselect_doc },
  {NULL, NULL}
};

PyMODINIT_FUNC
init_qselect(void)
{
  PyObject *m;
  m = Py_InitModule("_qselect", qselect_methods);
  if (m == NULL)
    return;
}
