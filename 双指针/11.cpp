class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            ret = max(ret, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--; 
        }
        return ret;
    }
};
