class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //why max heap? we maintain max attop always
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() > 1){
            //Suppose the heaviest two stones have weights x and y with x <= y.
            int y = maxHeap.top();
            maxHeap.pop();// to find second largest
            int x = maxHeap.top();
            maxHeap.pop();
            
            //Above we remove both stones, as in given both of conditions,
            //both stones anyway gets removed. And may benew weight gets inserted for y
            if(y != x){
                maxHeap.push(y - x);
            }
        }

        return maxHeap.size() > 0 ? maxHeap.top() : 0;
    }
};
