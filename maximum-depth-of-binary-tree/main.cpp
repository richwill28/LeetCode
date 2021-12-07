/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // recursive solution
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // BFS solution
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left != nullptr) {
                    q.push(front->left);
                }

                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            depth++;
        }

        return depth;
    }

    // DFS solution
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        stack<TreeNode*> s;
        s.push(root);

        stack<int> depths;
        depths.push(1);

        int maxSoFar = 1;
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();

            int depth = depths.top();
            depths.pop();

            maxSoFar = max(depth, maxSoFar);

            if (top->left != nullptr) {
                s.push(top->left);
                depths.push(depth + 1);
            }

            if (top->right != nullptr) {
                s.push(top->right);
                depths.push(depth + 1);
            }
        }

        return maxSoFar;
    }
};
