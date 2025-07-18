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
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            if (!head || k == 1)
                return head;

            ListNode* curr = head;
            ListNode* newHead = nullptr;
            ListNode* tail = nullptr;

            while (curr)
            {
                // Step 1: Check if at least k nodes remain
                ListNode* temp = curr;
                int count = 0;
                while (temp && count < k)
                {
                    temp = temp->next;
                    count++;
                }

                if (count < k)
                {
                    // Not enough nodes, link remaining as-is
                    if (tail) tail->next = curr;
                    break;
                }

                // Step 2: Reverse k nodes
                ListNode* groupHead = curr;
                ListNode* prev = nullptr;
                ListNode* nextNode = nullptr;
                count = 0;

                while (curr && count < k)
                {
                    nextNode = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextNode;
                    count++;
                }

                // Step 3: Connect reversed group
                if (!newHead) newHead = prev;
                if (tail) tail->next = prev;
                tail = groupHead;
            }

            return newHead ? newHead : head;
        }
};