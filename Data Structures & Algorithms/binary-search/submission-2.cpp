class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;
        int curr = left + ((right-left)/2);
        while (left <= right){
            std::cout << "curr: " << curr << std::setw(10) << "\tCurrent num: " << nums[curr] << "\n";
            std::cout << "left: " << left << std::setw(10) << "\tright: " << right << "\n";
            
            if (nums[curr] == target) return curr;
            else if (nums[curr] < target){
                left = curr + 1;
                curr = left + ((right-left)/2);
            }
            else if (nums[curr] > target){
                right = curr - 1;
                curr = left + ((right-left)/2);
            }
        }
        return -1;
    }
};
