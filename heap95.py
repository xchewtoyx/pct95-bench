import heapq

def percentile_sliced(tosort, percentile=95):
    length = len(tosort)
    heapmax = length - (length*percentile)//100
    heap = tosort[:heapmax+1]
    heapq.heapify(heap)
    for item in tosort[heapmax+1:]:
        if item > heap[0]:
            heapq.heapreplace(heap, item)
    if len(heap) < heapmax:
        return 0
    else:
        return heap[0]
         
def percentile_simple(tosort, percentile=95):
    length = len(tosort)
    heapmax = length - (length*percentile)//100
    heaplen = 0
    heap = []
    for item in tosort:
        if heaplen < heapmax:
            heap.append(item)
            heaplen += 1
            if heaplen == heapmax:
                heapq.heapify(heap)
        elif item > heap[0]:
            heapq.heapreplace(heap, item)
    if heaplen < heapmax:
        return 0
    else:
        return heap[0]
