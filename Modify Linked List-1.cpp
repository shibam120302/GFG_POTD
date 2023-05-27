class Solution{
    public:
    struct Node* reverse(Node *head)
    {
        Node *prev=NULL,*nxt,*curr=head;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        if(!head->next)
            return head;
        Node *slow=head,*fast=head,*mid;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        mid=slow;
        Node *reversedList=mid->next;
        mid->next=NULL;
        reversedList=reverse(reversedList);
        Node *temp2=reversedList,*temp=head;
        while(temp2)
        {
            int x=temp->data;
            temp->data=temp2->data-x;
            temp2->data=x;
            temp=temp->next;
            temp2=temp2->next;
        }
        mid->next=reverse(reversedList);
        return head;
    }
};
