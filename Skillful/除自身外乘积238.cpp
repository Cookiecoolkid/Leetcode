class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        vector<int> ret;
        int pre = 1;
        int suf = 1;
        prefix.push_back(1);
        suffix.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            pre *= nums[i];
            prefix.push_back(pre);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suf *= nums[i];
            suffix.push_back(suf);
        }
        for (int i = 0;  i < nums.size(); i++) {
            ret.push_back(prefix[i] * suffix[nums.size() - i - 1]);
        }
        return ret;
    }
};

// O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};
