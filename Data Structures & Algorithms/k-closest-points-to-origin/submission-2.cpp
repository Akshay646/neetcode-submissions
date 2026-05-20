class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>>> minHeap;
        for(auto point : points){
            double distance = sqrt((point[0] * point[0]) + (point[1] * point[1]));
            minHeap.push({distance, point});
            if(!minHeap.empty() && minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            auto res = minHeap.top();
            minHeap.pop();
            ans.push_back({res.second[0], res.second[1]});
        }
        return ans;
    }
};
