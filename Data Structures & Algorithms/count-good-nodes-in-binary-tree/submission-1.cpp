class Solution {
public:

void countNodes(TreeNode*root,int maxValue,int & count){
    if(root==NULL){
        return;
    }
    if(root->val>=maxValue){
        count++;
        maxValue=root->val;
    }
    countNodes(root->left,maxValue,count);
    countNodes(root->right,maxValue,count); 

}

    int goodNodes(TreeNode* root) {
        int count=0;

        countNodes(root,root->val,count);

        return count;

    }
};