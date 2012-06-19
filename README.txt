The files in this package form a very basic benchmarks of several methods 
to calculate the 95th percentile value of an unsorted list.

To compile the C extension _gselect.c use the following:

gcc -c -fPIC -O3 -I/usr/share/include -o _gselect.o _gselect.c
gcc -shared _gselect.o _gselect.so

Russell Heilling <russell@heilling.net>
