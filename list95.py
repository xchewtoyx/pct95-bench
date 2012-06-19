# Copyright (c) 2012 Russell Heilling
# See LICENSE for details
def percentile(tosort, percentile=95):
    length = len(tosort)
    pct_index = (length*percentile)//100
    tosort.sort()
    return tosort[pct_index]

        
