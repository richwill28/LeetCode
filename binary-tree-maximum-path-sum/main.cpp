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
    // DFS solution
    // O(n) time and O(n) space complexity
    // Actually, the runtime space complexity is O(r) (where r = number of recursion stack)
    // Therefore, best case = O(log n) space and worst case = O(n) space
    int recursiveMaxPathSum(int& globalMax, TreeNode* root, int depth) {
        if (root == nullptr) {
            return INT_MIN;
        }

        int leftMax = recursiveMaxPathSum(globalMax, root->left, depth + 1);
        int rightMax = recursiveMaxPathSum(globalMax, root->right, depth + 1);
        int localMax = root->val;
        if (depth == 0) {   // node does not have parent
            localMax += (leftMax >= 0) ? leftMax : 0;
            localMax += (rightMax >= 0) ? rightMax : 0;
        } else {    // node has parent
            // update global max in case root of max path ends here
            // e.g. [-10,9,20,null,null,15,7] -> root of max path = 20
            int tempMax = localMax;
            tempMax += (leftMax >= 0) ? leftMax : 0;
            tempMax += (rightMax >= 0) ? rightMax : 0;
            globalMax = max(tempMax, globalMax);

            int childMax = max(leftMax, rightMax);
            localMax += (childMax >= 0) ? childMax : 0;
        }

        globalMax = max(localMax, globalMax);
        cout << localMax << " " << globalMax << endl;
        return localMax;
    }

public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        recursiveMaxPathSum(globalMax, root, 0);
        return globalMax;
    }
};
