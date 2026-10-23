class Solution {
public:

    TreeNode* getInorderSuccessor(TreeNode* root) {
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val) {

            root->left = deleteNode(root->left, key);

        }
        else if (key > root->val) {

            root->right = deleteNode(root->right, key);

        }
        else {

            // No left child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // No right child
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Two children
            else {
                TreeNode* IS = getInorderSuccessor(root->right);

                root->val = IS->val;

                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
    }
};