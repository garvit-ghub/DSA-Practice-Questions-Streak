/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode *ptr = root;
        while(ptr->right!=nullptr){
            ptr=ptr->right;
        }
        ptr->right = temp;
        flatten(root->right);
    }
};