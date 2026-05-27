class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> mapper;
        mapper.reserve(nums.size());
        int desired_num {};
        for (int i {}; i < nums.size(); ++i){
            desired_num = target - nums[i];
            if (mapper.find(desired_num) != mapper.end()){
                if (i == mapper[desired_num]) continue;
                return {mapper[desired_num], i};
            }
            else{
                mapper[nums[i]] = i;
            }
        }
        throw std::invalid_argument("no pair found");
    }
};
