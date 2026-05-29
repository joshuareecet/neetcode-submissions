class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1){
            return 0;
        }
        
        int day {0};
        int buy_val {prices[0]};
        int profit {0};
        int res {0};

        while (day < static_cast<int>(prices.size())){
            if (prices[day] <= buy_val){
                buy_val = prices[day];
            }
            
            profit = prices[day] - buy_val;

            if (profit > res){
                res = profit;
            }
            ++day;
        }
        return res;
    }
};
