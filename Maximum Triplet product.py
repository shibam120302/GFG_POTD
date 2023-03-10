class Solution:
    def maxTripletProduct (self, arr,  n): 
        # Initialize Maximum, second
        # maximum and third maximum
        # element
        maxA = -sys.maxsize - 1
        maxB = -sys.maxsize - 1
        maxC = -sys.maxsize - 1
     
        # Initialize Minimum and
        # second mimimum element
        minA = sys.maxsize
        minB = sys.maxsize
     
        for i in range(n):
     
            # Update Maximum, second
            # maximum and third maximum
            # element
            if (arr[i] > maxA):
                maxC = maxB
                maxB = maxA
                maxA = arr[i]
                 
            # Update second maximum and
            # third maximum element
            elif (arr[i] > maxB):
                maxC = maxB
                maxB = arr[i]
                 
            # Update third maximum element
            elif (arr[i] > maxC):
                maxC = arr[i]
     
            # Update Minimum and second
            # mimimum element
            if (arr[i] < minA):
                minB = minA
                minA = arr[i]
     
            # Update second mimimum element
            elif (arr[i] < minB):
                minB = arr[i]
     
        return max(minA * minB * maxA,
                   maxA * maxB * maxC)
