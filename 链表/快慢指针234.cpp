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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void debug(ListNode* head) {
        int idx = 0;
        ListNode* p = head;
        while (p) {
            printf("Node[%d] = %d\n", idx++, p->val);
            p = p->next;
        }
    }

    bool isPalindrome(ListNode* head) {
        bool ret = true;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* part2_start = reverseList(slow->next);
        ListNode* part1 = head;
        ListNode* part2 = part2_start;

        while (part1 && part2) {
            if (part1->val != part2->val)
                ret = false;
            part1 = part1->next;
            part2 = part2->next;
        }
        slow->next = reverseList(part2_start);

        return ret;
    }
};
