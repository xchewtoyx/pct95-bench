from random import randint

def partition(a, start, end, pivot_index):
    low = start
    high = end -1
    pivot_value = a[pivot_index]
    a[pivot_index] = a[end]
    while True:
        while low <= high and a[low] < pivot_value:
            low = low + 1
        while low <= high and a[high] >= pivot_value:
            high = high - 1
        if low > high:
            break
        a[low], a[high] = a[high], a[low]
    a[end] = a[low]
    a[low] = pivot_value
    return low

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

def qselect(tosort, target):
    qselect_range(tosort, 0, len(tosort)-1, target)
    return tosort[target]

def percentile(tosort, percentile=95):
    length = len(tosort)
    pct_index = length*percentile//100
    return qselect(tosort, pct_index)

