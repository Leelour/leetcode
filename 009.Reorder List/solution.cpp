class Solution {
public:
    void reorderList(ListNode *head)
    {
        //find mid
        if(head == NULL || head->next == NULL)
            return;
        ListNode *fast = head, *slow = head, *ptr,*pre, *mid, *tmp;
        while(true)
        {
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            if(fast == NULL)
                break;
            slow = slow->next;
        }
        
        //reverse second half
        mid = slow;
        ptr = slow->next;
        slow->next = NULL;
        while(ptr)
        {
            tmp = slow->next;
            slow->next = ptr;
            ptr = ptr->next;
            slow->next->next = tmp;
        }
        
        //mix
        slow = slow->next;
        mid->next = NULL;
        for(pre = head; slow;)
        {
            tmp = pre->next;
            pre->next = slow;
            slow = slow->next;
            pre->next->next = tmp;
            pre = tmp;
        }
    }
};