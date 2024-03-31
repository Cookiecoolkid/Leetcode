class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0, ret = 0;

        while (right < s.size()) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            right++;
            ret = max(ret, right - left);
        }
        return ret;
    }
};
