def binarySearch(l, value):
    low = 0
    high = len(l) - 1
    while low <= high:
        mid = (low + high) / 2
        if l[mid] > value: high = mid-1
        if l[mid] < value: low = mid+1
        else: return mid
    return -1

print binarySearch([3,4,1,2,98], 1)