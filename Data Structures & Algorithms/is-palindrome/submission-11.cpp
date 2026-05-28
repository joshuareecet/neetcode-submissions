class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1){
            return true;
        }

        int left = 0;
        int right = s.size()-1;

        while (left <= right){
            while (!isalnum(s[left])){
                left += 1;
            }
            while (!isalnum(s[right])){
                right -= 1;
            }
            if (left > right){
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;
            left +=1;
            right -=1;
        }
        return true;
    }
};
