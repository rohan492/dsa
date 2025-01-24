#include<string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    void insertUtil(string word, TrieNode* root) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(word.substr(1), child);
    }
    void insert(string word) {
        insertUtil(word, root);
    }
    bool searchUtil(string word, TrieNode* root) {
        if (word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(word.substr(1), child);
    }
    bool search(string word) {
        return searchUtil(word, root);
    }
    bool startsWithUtil(string word, TrieNode* root) {
        if (word.size() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return startsWithUtil(word.substr(1), child);
    }
    bool startsWith(string word) {
        return startsWithUtil(word, root);
    }
};