class Solution():
    def no_of_subarrays(self, n, arr):
        count = 0
        answer = 0
        for i in range(n):
            if arr[i] == 0:
                count += 1
            else:
                answer += int((count*(count+1))/2)
                count = 0
        answer += int((count*(count+1))/2)
        return answer
