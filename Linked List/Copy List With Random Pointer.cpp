class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* ptr = head;
        while(ptr) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = ptr->next->next;
        }
        ptr = head;
        while(ptr && ptr->next) {
            if (!ptr->random) {
                ptr->next->random = NULL;
            } else {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        Node* newHead = head->next;
        Node* newCurr = head->next;
        Node* curr = head;
        while(curr && newCurr) {
            curr->next = curr->next ? curr->next->next : NULL;
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};