class Solution
{
    public:
    //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        Node *fast = head;
        Node *slow = head;
        
        if(head == NULL || head->next == NULL) return -1;
        bool isCycle = false;
        while(fast && slow){
            slow = slow->next;
            if(fast->next == NULL)return -1;
            fast = fast->next->next;
            if(fast==slow){
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle) return -1;
        slow=head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast->data;
    }
};
