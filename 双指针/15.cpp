class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if (nums[j] == nums[j - 1] && j != i + 1) continue;
                while (k > j && nums[j] + nums[k] + nums[i] > 0) k--;
                if (nums[j] + nums[k] + nums[i] == 0 && i != j && j != k)
                    s.insert({nums[i], nums[j], nums[k]});
            }
        }
        for (auto obj : s) ret.push_back(obj);
        return ret;
    }
};
