class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>>> maxHeap;
        for(auto point : points){
            double distance = sqrt((point[0] * point[0]) + (point[1] * point[1]));
            maxHeap.push({distance, point});
            if(!maxHeap.empty() && maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()){
            auto res = maxHeap.top();
            maxHeap.pop();
            ans.push_back({res.second[0], res.second[1]});
        }
        return ans;
    }
};
