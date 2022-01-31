#include<bits/stdc++.h>
using namespace std;




//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };




// Iterative inorder traversal
vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> order;
        if(root == nullptr) return order;
        stack<TreeNode*> stk;
        
        // INORDER 
        // LEFT -> ROOT -> RIGHT
        while( root != nullptr or !stk.empty()){
            

            // LEFT
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            
            // ROOT
            root = stk.top();
            stk.pop();
            order.push_back(root->val);

            // RIGHT
            root = root->right;

        }
        
        return order;        
}


int main(){

    // driver code..

    return 0;
}