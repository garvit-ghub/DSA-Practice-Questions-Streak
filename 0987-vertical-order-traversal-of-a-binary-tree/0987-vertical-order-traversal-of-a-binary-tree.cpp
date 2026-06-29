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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()) {

            int n = q.size();

            while(n--) {

                auto p = q.front();
                q.pop();

                TreeNode* curr = p.first;
                int col = p.second.first;
                int row = p.second.second;

                nodes[col][row].insert(curr->val);

                if(curr->left)
                    q.push({curr->left, {col - 1, row + 1}});

                if(curr->right)
                    q.push({curr->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto i : nodes) {

            vector<int> temp;

            for(auto j : i.second) {

                for(auto k : j.second)
                    temp.push_back(k);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};