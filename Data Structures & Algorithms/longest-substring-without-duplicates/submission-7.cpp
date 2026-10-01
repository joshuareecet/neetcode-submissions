class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int,256> seen{};
        int left {0};
        int right {0};
        int maxSize = 0;

        if (s.size() <= 1){
            return static_cast<int>(s.size());
        }
        
        while (right < static_cast<int>(s.size()))
        {
            int rightChar = static_cast<int>(s[right]);
            while (seen[rightChar] != 0)
            {
                int leftChar = static_cast<int>(s[left]);
                seen[leftChar] = 0;
                left++;
            }
            seen[rightChar] = 1;
            auto curr_size = right-left+1;
            maxSize =  curr_size > maxSize ? curr_size : maxSize;
            right++;
        };

        return maxSize;
    }
};
