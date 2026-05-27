class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> mapper;
        mapper.reserve(nums.size());
        
        
        int desired_num {};
        for (int i {}; i < nums.size(); ++i){
            desired_num = target - nums[i];
            if (mapper.find(desired_num) != mapper.end()){
                return {mapper[desired_num], i};
            }
            mapper[nums[i]] = i;
        }
        return {};
    }
};
