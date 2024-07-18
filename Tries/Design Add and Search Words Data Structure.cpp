class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }

    void addWordUtil(string word, TrieNode* root) {
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

        addWordUtil(word.substr(1), child);
    }
    void addWord(string word) {
        addWordUtil(word, root);
    }

    bool searchUtil(string word, TrieNode* root) {
        if (word.size() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    if (searchUtil(word.substr(1), root->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                return false;
            }
        }

        return searchUtil(word.substr(1), child);
    }
    bool search(string word) {
        return searchUtil(word, root);
    }
};