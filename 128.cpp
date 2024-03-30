class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) s.insert(nums[i]);

        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i] - 1)) continue;
            int len = 1;
            while(true) {
                if (s.count(nums[i] + len)) len++;
                else break;
            }
            ret = max(ret, len);
        }
        return ret;
    }
};
