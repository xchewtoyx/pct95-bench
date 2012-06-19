The files in this package form a very basic benchmarks of several methods 
to calculate the 95th percentile value of an unsorted list.

To compile the C extension _qselect.c use the following (replacing
your python header files location appropriately):

gcc -c -fPIC -O3 -I/usr/include/python2.7 -o _qselect.o _qselect.c
gcc -shared _qselect.o -o _qselect.so

Russell Heilling <russell@heilling.net>
