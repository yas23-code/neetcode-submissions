class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};