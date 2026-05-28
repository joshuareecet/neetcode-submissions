class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product {1};
        int zero_count {0};
        vector<int> res(nums.size(),0);

        for (auto num : nums){
            if (num == 0){
                zero_count += 1;
                if (zero_count == 2){
                    return res;
                }
                continue;
            }
            product *= num;
        }
        
        for (int i {0}; i < nums.size(); ++i){
            if (nums[i] == 0){
                res[i] = product;
                continue;
            }
            if (zero_count > 0){
                res[i] = 0;
                continue;
            }
            res[i] = product / nums[i];
        }

        return res;
    }
};
