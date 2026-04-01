/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxSum;

int maxGain(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = maxGain(root->left);
    int right = maxGain(root->right);

    if (left < 0) left = 0;
    if (right < 0) right = 0;

    int currentPath = root->val + left + right;

    if (currentPath > maxSum) {
        maxSum = currentPath;
    }

    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    maxSum = INT_MIN;
    maxGain(root);
    return maxSum;
}