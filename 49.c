class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> hashtable;
        vector<vector<string>> ret;
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            hashtable[key].push_back(s);
        }

        for (auto obj : hashtable)
            ret.push_back(obj.second);
        return ret;
    }
};
