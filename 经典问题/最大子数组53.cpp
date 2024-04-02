class Solution {
public:
    struct interval{
        int left;
        int right;
        int sum;
    };
    int maxSubArray(vector<int>& nums) {
        interval cur = {0, 0, nums[0]};
        interval r = {0, 0, nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            if (r.sum < 0 && nums[i] > r.sum) {
                r.left = r.right = i;
                r.sum = nums[i];
            }
            else {
                r.right++;
                r.sum += nums[i];
            }
            if (cur.sum < r.sum) {
                cur.left = r.left;
                cur.right = r.right;
                cur.sum = r.sum;
            }
        }
        return cur.sum;
    }
};
