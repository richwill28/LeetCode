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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // BFS solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        queue<TreeNode*> qp;
        qp.push(p);

        queue<TreeNode*> qq;
        qq.push(q);

        while (!qp.empty() && !qq.empty()) {
            TreeNode* pf = qp.front();
            qp.pop();

            TreeNode* qf = qq.front();
            qq.pop();

            if (pf->val != qf->val) {
                return false;
            }

            // Traverse p neighbors
            if (pf->val != INT_MIN) {
                if (pf->left == nullptr) {
                    qp.push(new TreeNode(INT_MIN));
                } else {
                    qp.push(pf->left);
                }
                if (pf->right == nullptr) {
                    qp.push(new TreeNode(INT_MIN));
                } else {
                    qp.push(pf->right);
                }
            }

            // Traverse q neighbors
            if (qf->val != INT_MIN) {
                if (qf->left == nullptr) {
                    qq.push(new TreeNode(INT_MIN));
                } else {
                    qq.push(qf->left);
                }
                if (qf->right == nullptr) {
                    qq.push(new TreeNode(INT_MIN));
                } else {
                    qq.push(qf->right);
                }
            }
        }

        if (qp.empty() && qq.empty()) {
            return true;
        }
        return false;
    }
};
