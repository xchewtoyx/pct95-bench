def percentile(tosort, percentile=95):
    length = len(tosort)
    pct_index = (length*percentile)//100
    tosort.sort()
    return tosort[pct_index]

        
