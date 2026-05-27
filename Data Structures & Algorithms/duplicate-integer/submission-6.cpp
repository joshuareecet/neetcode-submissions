class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> numbers {};
        for (int i: nums){
            if (numbers.contains(i)){
                return true;
            }
            else{
                numbers.insert(i);
            }
        }
        return false;
    }
};