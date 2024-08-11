class Codec {
private:
    void encode(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "N ";
            return;
        }
        out << root->val << " ";
        encode(root->left, out);
        encode(root->right, out);
    }
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value;
        if (value == "N") {
            return NULL;
        }
        TreeNode* newNode = new TreeNode(stoi(value));
        newNode->left = decode(in);
        newNode->right = decode(in);
        return newNode;
    }
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
};