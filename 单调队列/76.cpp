// CORRECT CODE
class Solution {
public:
    string minWindow(string s, string t) {
        // string ret = "";
        int left = 0, right = 0;
        int counter = t.size();
        int minlen = INT_MAX;
        int ans_l = 0;
        unordered_map<char, int> count;
        for (int i = 0; i < t.size(); i++) {
            count[t[i]]++;
        }
        while (right < s.size()) {
            if (count[s[right]] > 0) {
                counter--;
            }
            count[s[right]]--;
            right++;
            while (counter == 0) {
                if (right - left < minlen) {
                    minlen = right - left;
                    //ret = s.substr(left, minlen);
                    ans_l = left;
                }
                count[s[left]]++;
                if (count[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(ans_l, minlen); 
        //return ret;
    }
};
