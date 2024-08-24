class Node {
public:
    int k;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        next->prev = node;
        node->next = next;
        node->prev = prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            delete(mp[key]);
        }
        mp[key] = new Node(key, value);
        insert(mp[key]);
        if (mp.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->k);
            delete(lru);
        }
    }
};