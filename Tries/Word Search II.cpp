class TrieNode {
public:
    string word;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode() {
        word = "";
        isTerminal = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insertUtil(string& word, int index, TrieNode* root) {
        if (index >= word.size()) {
            root->isTerminal = true;
            root->word = word;
            return;
        }
        int idx = word[index] - 'a';
        TrieNode* child;
        if (root->children[idx] != NULL) {
            child = root->children[idx];
        } else {
            child = new TrieNode();
            root->children[idx] = child;
        }
        insertUtil(word, index+1, child);
    }
    void insert(string& word) {
        insertUtil(word, 0, root);
    }
};

class Solution {
public:
    int m, n;
    vector<string> result;
    vector<vector<int>> directions {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j) {
        if (i == m || i == -1 || j == n || j == -1 || board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL) {
            return;
        }
        root = root->children[board[i][j] - 'a'];
        if (root->isTerminal) {
            result.push_back(root->word);
            root->isTerminal = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            dfs(board, root, new_i, new_j);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        m = board.size();
        n = board[0].size();
        for (string& word : words) {
            trie->insert(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, trie->root, i, j);
            }
        }
        return result;
    }
};