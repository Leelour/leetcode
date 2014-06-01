#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//without helper pointer solution
class Solution {
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *cur = head, *pivot, *prepivot, *pre, *ptr, *precur = NULL;
        while(cur)
        {
            pivot = cur->next;
            prepivot = cur;
            //find the minimum pointer behind cursor
            for(ptr = cur->next, pre = cur; ptr; pre = ptr, ptr = ptr->next)
            {
                if(ptr->val < pivot->val)
                {
                    pivot = ptr;
                    prepivot = pre;
                }
            }
            //update cursor
            if(pivot && pivot->val < cur->val)
            {
                if(cur == head)
                {
                    head = pivot;
                }
                prepivot->next = pivot->next;
                pivot->next = cur;
                
                //update pre cursor pointer
                if(precur)
                    precur->next = pivot;
                precur = pivot;
            }
            else
            {
                precur = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[])
{
    Solution sol;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head = sol.insertionSortList(head);
    while(head)
    {
        printf("%d,", head->val);
        head = head->next;
    }
    return 0;
}