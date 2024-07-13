class Solution {
public:
    ListNode* leftNode;
    void solve(ListNode* rightNode) {
        if (!rightNode) return;
        solve(rightNode->next);

        ListNode* temp = leftNode->next;
        if (!temp) return;
        else if (leftNode == rightNode) {
            rightNode->next = NULL;
            return;
        }

        leftNode->next = rightNode;
        rightNode->next = (temp == rightNode) ? NULL : temp;

        leftNode = temp;
    }
    void reorderList(ListNode* head) {
        leftNode = head;
        solve(leftNode);
    }
};