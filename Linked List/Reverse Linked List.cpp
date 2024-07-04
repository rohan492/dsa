class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head) {
            next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }
        return prev;
    }
};