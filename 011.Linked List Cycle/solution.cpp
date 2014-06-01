class Solution {
    bool iterate(ListNode *&pointer)
    {
        if(pointer->next)
        {
            pointer = pointer->next;
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if(!head)
            return false;
        while(true)
        {
            if(!(iterate(fast) && iterate(fast)))//can not move twice
            {
                return false;
            }
            if(iterate(slow))
            {
                if(slow == fast)
                    return true;
            }
            else// unlikely happen
            {
                return false;
            }
            
        }
    }
};