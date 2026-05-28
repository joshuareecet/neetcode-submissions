class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count {};

        for (auto num : nums){
            count[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap {};
        for (auto& entry : count ){
            heap.push({entry.second, entry.first});
            if (heap.size() > k){
                heap.pop();
            }
        }
        vector<int> res {};
        for (int i {}; i < k; ++i){
            auto entry = heap.top();
            res.push_back(entry.second);
            heap.pop();
        }
        return res;
    }
};
