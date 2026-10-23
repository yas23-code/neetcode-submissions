class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int maxValue) {

        if (root == NULL)
            return;

        if (root->val >= maxValue)
            count++;

        maxValue = max(maxValue, root->val);

        dfs(root->left, maxValue);
        dfs(root->right, maxValue);
    }

    int goodNodes(TreeNode* root) {

        dfs(root, root->val);

        return count;
    }
};