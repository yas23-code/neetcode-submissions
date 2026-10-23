class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if (root == NULL)
            return true;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) &&
               isBalanced(root->right);
    }
};