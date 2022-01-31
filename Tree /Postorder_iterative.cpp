/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// POST ORDER IS VERY SIMILAR TO PRE ORDER IN THE SENSE THAT:
// since it is difficult to acheive left->right->root
// we do root->right->left and then reverse to get the result;
vector<int> Solution::postorderTraversal(TreeNode* root) {

    // list<int> l;
    vector<int> order;
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()){

        root = stk.top();
        stk.pop();
        order.push_back(root->val);
        if(root->left != nullptr) stk.push(root->left); 
        if(root->right != nullptr) stk.push(root->right);
    }

    reverse(order.begin(),order.end());

    return order;
}
