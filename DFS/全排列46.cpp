class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> permutation;
        vector<bool> vis(nums.size(), false);
        permute(nums, vis, permutation, ret);
        return ret;
    }

private:
    void permute(vector<int>& nums, vector<bool>& vis, vector<int>& permutation, vector<vector<int>>& ret) {
        if (permutation.size() == nums.size()) {
            ret.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                permutation.push_back(nums[i]);
                permute(nums, vis, permutation, ret);
                vis[i] = false;
                permutation.pop_back();
            }
        }
    }
};
