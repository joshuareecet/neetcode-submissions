class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left {0};
        int right = heights.size()-1;
        
        int max_vol {0};
        int curr_vol {0};

        int l_h {heights[left]};
        int r_h {heights[right]};

        while (left < right){
            l_h = heights[left];
            r_h = heights[right];
            
            curr_vol = min(l_h, r_h) * (right - left);
            if (curr_vol > max_vol){
                max_vol = curr_vol;
            }
            
            if (l_h < r_h){
                left++;
            }
            else if (r_h < l_h){
                right--;
            }
            else{
                left++;
            }
            std::cout << "l_h: " << l_h << std::endl;
            std::cout << "r_h: " << r_h << std::endl;
            std::cout << "curr_vol: " << curr_vol << std::endl;
            std::cout << std::endl;
        }
        return max_vol;
    }
};
