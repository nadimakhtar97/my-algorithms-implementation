/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// pre-order is root->left->right;
vector<int> Solution::postorderTraversal(TreeNode* root) {

    vector<int> order;
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()){
        root = stk.top();
        stk.pop();
        order.push_back(root->val);
        if(root->right != nullptr) stk.push(root->right);
        if(root->left != nullptr) stk.push(root->left);
    }

    return order;
}
