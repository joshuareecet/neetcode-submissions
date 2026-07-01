class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(),nums.end()-k,nums.end());
        for (auto num : nums){
            std::cout << num;
        }
        return nums[nums.size()-k];
    }
};
