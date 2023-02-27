class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *pre = NULL;
        Node *next = NULL;
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    Node *reverse(Node *head, int k)
    {
        Node *ptr = head;

        for (int i = 0; i < k - 1; i++)
        {
            ptr = ptr->next;
        }

        Node *secondPart = reverseList(ptr->next);
        ptr->next = NULL;
        Node *firstPart = reverseList(head);
        ptr = firstPart;
        while (ptr->next)
        {
            ptr = ptr->next;
        }

        ptr->next = secondPart;

        return firstPart;
    }
};
