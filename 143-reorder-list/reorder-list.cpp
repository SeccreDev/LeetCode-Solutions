/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    public:
        void reorderList(ListNode* head)
        {    
            ListNode *tail = head;
            ListNode *half = head;
            ListNode *prev = nullptr;

            while(tail->next && tail->next->next)
            {
                tail = tail->next->next;
                half = half->next;
            }
            if (tail->next)
            {
                half = half->next;
            }

            while(half)
            {
                tail = half->next;
                half->next = prev;
                prev = half;
                half = tail;
            }
            half = prev;
            

            while(head && half)
            {
                tail = head->next;
                prev = half->next;
                head->next = half;
                half->next = tail;
                head = tail;
                half = prev;
            }

            if (head && head->next)
            {
                head -> next->next = nullptr;
            }
        }
};