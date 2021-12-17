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
private:
    void recursiveDFS(vector<vector<int>>& solution, TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (solution.size() == depth) {
            solution.push_back(vector<int>());
        }

        solution[depth].push_back(root->val);
        recursiveDFS(solution, root->left, depth + 1);
        recursiveDFS(solution, root->right, depth + 1);
    }

public:
    // BFS solution
    // O(n) time and O(n) size complexity
    // Disregarding the solution array, the runtime size complexity is O(l) (where l = number of leaf nodes)
    // Therefore, best case = O(1) size and worst case = O(n/2) size
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> solution;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            while (size--) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);

                if (front->left != nullptr) {
                    q.push(front->left);
                }

                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            solution.push_back(level);
        }

        return solution;
    }

    // DFS solution
    // O(n) time and O(n) size complexity
    // Disregarding the solution array, the runtime size complexity is O(r) (where r = number of recursion stack)
    // Therefore, best case = O(log n) size and worst case = O(n) size
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        recursiveDFS(solution, root, 0);
        return solution;
    }
};
