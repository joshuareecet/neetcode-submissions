#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams {};
        anagrams.reserve(strs.size());
        
        for (const string& s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            string t = to_string(count[0]);
            for (int i {0}; i < 26; ++i){
                t += ',' + to_string(count[i]);
            }
            anagrams[t].push_back(std::move(s));
        }
        
        vector<vector<string>> res {};
        res.reserve(anagrams.size());

        for (const auto& [key, val] : anagrams){
            res.push_back(std::move(val));
        }
        
        return res;
    }
};
