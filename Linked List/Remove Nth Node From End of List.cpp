class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while(n--) {
            temp = temp->next;
        }
        if (!temp) {
            ListNode* ans = head->next;
            delete(head);
            return ans;
        }
        ListNode* prev = head;
        while(temp && temp->next) {
            temp = temp->next;
            prev = prev->next;
        }
        ListNode* delNode = prev->next;
        prev->next = prev->next->next;
        delete(delNode);
        return head;
    }
};