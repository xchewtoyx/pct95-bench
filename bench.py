#!/usr/bin/env python
# Copyright (c) 2012 Russell Heilling
# See LICENSE for details
import heap95
import list95
import scipy95
import qsel95
import qselect
import random
import time

METHODS = { 
    'heap_sliced': heap95.percentile_sliced,
    'heap_simple': heap95.percentile_simple,
    'builtin': list95.percentile,
    'scipy': scipy95.percentile,
    'qselect_c': qsel95.percentile,
    'qselect_py': qselect.percentile,
}

def time_reps(pct_func, input_list):
    elapsed = 0
    for repeat in range(1000):
        random.shuffle(input_list)
        start = time.time()
        value = pct_func(input_list)
        elapsed += time.time() - start
    return(elapsed, value)
    
def main():
    times = {}
    input_list = [random.random() for r in range(8000)]
    for name, method in sorted(METHODS.items()):
        times[name] = time_reps(method, input_list)
        print name, times[name]

if __name__ == "__main__":
    main()
