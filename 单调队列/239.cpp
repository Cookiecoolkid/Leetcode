class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        deque<int> idx;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i - idx.front() == k) q.pop_front(), idx.pop_front();
            while (!q.empty() && q.back() < nums[i]) q.pop_back(), idx.pop_back();
            q.push_back(nums[i]), idx.push_back(i);
            if (i >= k  - 1) ret.push_back(q.front());
        }
        return ret;
    }
};
