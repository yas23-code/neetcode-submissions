class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL || q == NULL) {
            return p == q;
        }

        bool isLeft = isSameTree(p->left, q->left);
        bool isRight = isSameTree(p->right, q->right);

        return isLeft && isRight && (p->val == q->val);
    }
};