# Copyright (c) 2012 Russell Heilling
# See LICENSE for details
from scipy.stats import scoreatpercentile

def percentile(tosort, percentile=95):
    return scoreatpercentile(tosort, percentile)       
