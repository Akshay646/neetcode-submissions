class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>> maxHeap;

        for(auto point : points){
            //calculate euclidean distance
            int x1 = point[0], y1 = point[1];
            int x2 = 0, y2 = 0;
            int d = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
            //push it to max heap always
            maxHeap.push({d, {x1, y1}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};