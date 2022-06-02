def binarySearch(low,high,Array,item):
    mid = (low+high)//2
    if mid<0 or mid>=len(Array):
        return None
    if Array[mid]==item:
        return mid
    elif Array[mid]>item:
        return binarySearch(low,mid-1,Array,item)
    else:
        return binarySearch(mid+1,high,Array,item)

A = [1,3,5,6,7,9]
print(binarySearch(0,len(A),A,0))
