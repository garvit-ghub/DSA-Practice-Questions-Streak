class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> allSubsets;
        vector<int> ans;

        sort(nums.begin(), nums.end());

        solve(nums, ans, 0, allSubsets);

        return allSubsets;
    }

private:
    void solve(vector<int>& arr,
               vector<int>& ans,
               int i,
               vector<vector<int>>& allSubsets) {

        if (i == arr.size()) {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(arr[i]);

        solve(arr, ans, i + 1, allSubsets);

        ans.pop_back();

        while (i < arr.size() - 1 && arr[i] == arr[i + 1])
            i++;

        solve(arr, ans, i + 1, allSubsets);
    }
};