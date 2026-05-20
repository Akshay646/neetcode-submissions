class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //decide which map to insert a number
        //left(maxHeap) = first sorted oprtion ; top is max of first half
        //right(minHeap) = second sorted portion ; top is min of second half
        //l=[1,3,5] r=[7,8,11]
        
        //1. check if  we can insert in left or right
        if(maxHeap.empty() || num <= maxHeap.top()){ //=>left
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);//=> right
        }
        //2. validate if diff between two heaps is <= 1
        if(maxHeap.size() > minHeap.size() + 1){//=> maxHeap has >= 2 extra elements
            //insert extra to minHeap
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size() + 1){//=> minHeap has >= 2 extra elements
            //insert extra to maxHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        double median = 0.0;

        //A. whichever heap has extra elements, the top is always a medium
        //i.e. [1,2,3,4], [6,7,8], hence median = maxHeap.top() = 4
        if(maxHeap.size() > minHeap.size()){
            median = maxHeap.top();
        }
        else if(minHeap.size() > maxHeap.size()){
            median =  minHeap.top();
        }
        //B. if both heaps has same number of elements
        //then median = maxHeap.top() + minHeap.top() / 2;
        else{
            //maxHeap.size() == minHeap.size())
            median = (double)(maxHeap.top() + minHeap.top()) / 2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */