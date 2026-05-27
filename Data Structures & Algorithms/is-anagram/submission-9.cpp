class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        
        std::unordered_map<char,int> s_m {};
        std::unordered_map<char,int> t_m {};

        for (int i {}; i < s.length(); ++i){
            s_m[s[i]] += 1;
            t_m[t[i]] += 1;
        }

        return s_m == t_m;
    }
};
