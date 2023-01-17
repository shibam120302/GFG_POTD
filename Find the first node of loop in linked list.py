class Solution:
    def findFirstNode(self, head):
        slow = head
        fast = head
    
        isCycle = False
        while slow and fast:
            slow=slow.next
            if not fast.next:
                return -1
            fast=fast.next.next
            if slow == fast :
                isCycle = True
                break
        if not isCycle:
            return -1
        slow = head
        while slow!=fast:
            fast = fast.next
            slow = slow.next
       
        return fast.data
