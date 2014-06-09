/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //the prime of this question is how to copy the random pointers correctly
    RandomListNode *copyRandomList(RandomListNode *head) {
        //in case of NULL list
        if(head == NULL) return NULL;
        
        RandomListNode *tmp = NULL;
        for(RandomListNode *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            tmp = ptr->next;
            ptr->next = new RandomListNode(ptr->label);
            ptr = ptr->next;
            ptr->next = tmp;
        }
        
        //synchronize random pointer
        for(RandomListNode *ptr = head; ptr != NULL;ptr = ptr->next->next)
        {
            if(ptr->random)
                ptr->next->random = ptr->random->next;
        }
        
        //break one lists into 2 lists
        RandomListNode * ret = head->next;
        for(RandomListNode *first = head, *second; first;)
        {
            second = first->next;
            first->next = second->next;
            first = second->next;
            second->next = first ? first->next : NULL;
        }
        return ret;
    }
};