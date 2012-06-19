# Copyright (c) 2012 Russell Heilling
# See LICENSE for details
from _qselect import qselect

def percentile(tosort, percentile=95):
    length = len(tosort)
    pct_index = length*percentile//100
    return qselect(tosort, pct_index)
