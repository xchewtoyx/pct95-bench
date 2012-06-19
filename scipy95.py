from scipy.stats import scoreatpercentile

def percentile(tosort, percentile=95):
    return scoreatpercentile(tosort, percentile)       
