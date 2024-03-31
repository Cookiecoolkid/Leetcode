class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        unordered_set<char> window;
        unordered_map<char, int> counts;
        for (char c : p) counts[c]++;

        int left = 0, right = 0, counter = p.size();
        while (right < s.size()) {
            if (counts[s[right++]]-- >= 1) counter--; // right 滑入窗口
            if (counter == 0) ret.push_back(left);
            if (right - left == p.size() && counts[s[left++]]++ >= 0) counter++; // 当 size 达到 p.size()时 left 滑出窗口
        }
        return ret;
    }
};
