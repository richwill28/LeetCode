/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* buildTree(deque<string>& nodes) {
        string node = nodes[0];
        nodes.pop_front();
        if (node == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(node));
        root->left = buildTree(nodes);
        root->right = buildTree(nodes);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> nodes;
        string s = "";
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                nodes.push_back(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if (s != "") {
            nodes.push_back(s);
        }
        return buildTree(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
