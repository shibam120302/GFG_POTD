def getSize(head):
    ret = 0
    while head is not None:
        head = head.next
        ret+=1
    return ret

#Function to find intersection point in Y shaped Linked Lists.
class Solution:
    
    def intersetPoint(self,head1,head2):
        
        #finding length of list1.
        n1 = getSize(head1)
        
        #finding length of list2.
        n2 = getSize(head2)
        
        #if list1 is longer, we ignore some of its starting
        #elements till it has as many elements as list2.
        while n1>n2:
            head1 = head1.next
            n1-=1
        
        #similarly, if list2 is longer, we ignore some of its starting
        #elements till it has as many elements as list1.
        while n2>n1:
            head2 = head2.next
            n2-=1
        
        
        #now we simply traverse ahead till we get the intersection point, if there 
        #is none, this loop will break when both pointers point at NULL.
        while head1 != head2:
            head1 = head1.next
            head2 = head2.next
    
        # if head1 is not NULL, we return its data otherwise we return -1.
        if head1 is not None:
            return head1.data
        return -1
