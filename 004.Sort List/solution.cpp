/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solve the problem by quicksort instead of merge sort.
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *lHead = NULL, *rHead = NULL, *lTail = NULL, *rTail = NULL, *mHead = NULL, *mTail = NULL, *ptr = head, *retHead;
        if(head)
        {
            //partition
            mHead = mTail = head;
            for(ptr = ptr->next; ptr; ptr = ptr->next)
            {
                if(ptr->val > head->val)
                {
                    if(rHead)//there is some elements in right list
                    {
                        rTail->next = ptr;
                    }
                    else// no element in right list
                    {
                        rHead = ptr;
                    }
                    rTail = ptr;
                }
                else if(ptr->val < head->val)
                {
                    if(lHead)
                    {
                        lTail->next = ptr;
                    }
                    else
                    {
                        lHead = ptr;
                    }
                    lTail = ptr;
                }
                else// pre->val == head->val
                {
                    mTail->next = ptr;
                    mTail = ptr;
                }
            }
            //initialize return head
            retHead = mHead;
            mTail->next = NULL;
            //if there is element in left list
            if(lHead)
            {
                lTail->next = NULL;
                lHead = sortList(lHead);
                //traverse to the end of the left list
                for(ptr = lHead; ptr->next; ptr=ptr->next);
                //update return head
                retHead = lHead;
                //add the head after the list
                ptr->next = mHead;
            }
            //if there is element in right list
            if(rHead)
            {
                rTail->next = NULL;
                mTail->next = sortList(rHead);
            }
            return retHead;
        }
        else//in case of a null pointer
        {
            return NULL;
        }
    }
};