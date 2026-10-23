class Solution {
public:
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {

        if (root == NULL)
            return -1;

        int leftAns = kthSmallest(root->left, k);

        if (leftAns != -1)
            return leftAns;

        count++;

        if (count == k)
            return root->val;

        int rightAns = kthSmallest(root->right, k);

        if (rightAns != -1)
            return rightAns;

        return -1;
    }
};