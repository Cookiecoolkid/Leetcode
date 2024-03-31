class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        vector<int> preSum(nums.size(), 0);
        unordered_map<int, int> hashTable;
        hashTable[0] = 1;
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.find(preSum[i] - k) != hashTable.end())
                ret += hashTable[preSum[i] - k];
            hashTable[preSum[i]]++;
        }
        return ret;
    }
};
