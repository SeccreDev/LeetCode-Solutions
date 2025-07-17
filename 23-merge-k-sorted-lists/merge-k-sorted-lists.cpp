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
        ListNode* mergetwolist(ListNode* h1,ListNode* h2)
        {
            ListNode* t1 = h1;
            ListNode* t2 = h2;
            ListNode* dummy = new ListNode(-1);
            ListNode* t3 = dummy;
            while(t1 && t2)
            {
                if(t1->val >t2->val)
                {
                    t3->next = t2;
                    t3 = t3->next;
                    t2 = t2->next;
                }
                else
                {
                    t3->next=t1;
                    t3 = t3->next;
                    t1 = t1->next;
                }
            }
            if(t2)
            {
                t3->next = t2;
            }
            if(t1)
            {
                t3->next = t1;
            }
            return dummy->next;
        }
        
        ListNode* mergeKLists(vector<ListNode*>& lists)
        {
            if(lists.size()==0)
                return NULL;
            while(lists.size()>1)
            {
                auto x = lists.front();
                lists.erase(lists.begin());
                auto y = lists.front();
                lists.erase(lists.begin());
                lists.push_back(mergetwolist(x,y));
            }
            return lists[0];
        }
};