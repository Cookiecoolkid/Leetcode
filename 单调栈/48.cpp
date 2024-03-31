class Solution {
public:
/*
    vector<int> NextGreaterElement(const vector<int>& height) {
        vector<int> ret(height.size(), -1);
        stack<int> s;
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] < height[i]) {
                ret[s.top()] = i;
                s.pop(); 
            }
            s.push(i);
        }
        return ret;
    }
    vector<int> LastGreaterElement(const vector<int>& height) {
        vector<int> ret(height.size(), -1);
        stack<int> s;
        for (int i = height.size() - 1; i >= 0; i--) {
            while (!s.empty() && height[s.top()] < height[i]) {
                ret[s.top()] = i;
                s.pop(); 
            }
            s.push(i);
        }
        return ret;
    }
    */
    int trap(vector<int>& height) {
        int ret = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                ret += (i - left - 1) * (min(height[i], height[left]) - height[top]);
            }
            stk.push(i);
        }
        return ret;
    }
};
