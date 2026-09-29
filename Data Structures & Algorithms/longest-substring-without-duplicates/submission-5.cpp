class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> uniqueChars;
        int l = 0; 
        int r = 0;
        int max_size{0};

        if (s.size() <= 1)
        {
            return static_cast<int>(s.size());
        }

        while (r < static_cast<int>(s.length()))
        {
            char currChar = s[r];
            int currSize = r-l+1;
            if (uniqueChars.contains(currChar))
            {
                while (s[l] != currChar){
                    uniqueChars.erase(s[l]);
                    ++l;
                }
                uniqueChars.erase(currChar);
                ++l;
                currSize = r-l+1;
                if (currSize >= max_size){
                    max_size = currSize;
                }
                continue;
            }


            uniqueChars.insert(currChar);
            if (currSize >= max_size){
                max_size = currSize;
            }
            ++r;
        }
        return max_size;
    }
};
