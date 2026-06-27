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
    TreeNode* binarysearch(vector<int> &arr, int low, int high) {
        if(low>high)
            return nullptr;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode (arr[mid]);
        root->left = binarysearch(arr,low,mid-1);
        root->right = binarysearch(arr,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return binarysearch(nums,0,nums.size() -1);
    }
};