class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height[height.size() - 1];
        while (left < right) {
            if (height[left] < height[right]) {
                ret += leftMax - height[left];
                left++;
                leftMax = max(leftMax, height[left]);
            }
            else {
                ret += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }
        return ret;
    }
};
