class Solution:
    def checkAnagram(self, A, B):
        for i in range(26):
            if A[i] != B[i]:
                return False
        return True
    def checkAndPush(self, isAnagram, n, ptr1, ptr2, res, freq1):
        if (isAnagram == False):
            return
        prev = None
        res.append(ptr1)
        temp = ptr2
        ptr2 = ptr2.next
        if temp != None:
            temp.next = None
        ptr1 = ptr2
        for i in range(26):
            freq1[i] = 0
        for i in range(n):
            if ptr2 != None:
                freq1[ord(ptr2.data) - ord('a')] += 1
                prev = ptr2
                if ptr2 != None:
                    ptr2 = ptr2.next
        ptr2 = prev

    def findAnagrams(self, head, s):
        # Code here
        n = len(s)
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1
        freq1 = [0] * 26
        ptr1 = head
        ptr2 = head
        prev = None
        for i in range(n):
            if ptr2 != None:
                freq1[ord(ptr2.data) - ord('a')] += 1
                prev = ptr2
                ptr2 = ptr2.next
        ptr2 = prev
        res = []
        while (ptr2.next != None):
            ok = self.checkAnagram(freq1, freq)
            if (ok):
                if (ok == False):
                    return
                prev = None
                res.append(ptr1)
                temp = ptr2
                ptr2 = ptr2.next
                if temp != None:
                    temp.next = None
                ptr1 = ptr2
                for i in range(26):
                    freq1[i] = 0
                for i in range(n):
                    if ptr2 != None:
                        freq1[ord(ptr2.data) - ord('a')] += 1
                        prev = ptr2
                        if ptr2 != None:
                            ptr2 = ptr2.next
                ptr2 = prev
                # self.checkAndPush(ok, n, ptr1, ptr2, res, freq1)
            else:
                freq1[ord(ptr1.data) - ord('a')] -= 1
                ptr1 = ptr1.next
                ptr2 = ptr2.next
                freq1[ord(ptr2.data) - ord('a')] += 1
        ok = self.checkAnagram(freq1, freq)
        if (ok):
            res.append(ptr1)
        return res
