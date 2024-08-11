class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    ListNode* partitionAndMerge(int s, int e, vector<ListNode*>& lists) {
        if(s == e) return lists[s];
        int mid = s + (e - s) / 2;
        ListNode* l1 = partitionAndMerge(s, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, e, lists);
        return mergeTwoLists(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return partitionAndMerge(0, lists.size()-1, lists);
    }
};