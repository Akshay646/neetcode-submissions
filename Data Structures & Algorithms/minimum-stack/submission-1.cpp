class MinStack {
public:
    vector<int> _stack;
    deque<int> minTracker;
    MinStack() {
    
    }
    
    void push(int val) {
        _stack.push_back(val);//O(1)
        if(minTracker.empty() || val <= minTracker.back())
        {
            minTracker.push_back(val);
        }
    }
    
    void pop() {
        //assuming pop will be called on non empty stack given problem statement
        int currentElement = _stack.back();
         _stack.pop_back();//O(1)
         //Now you remove back from deque if and only if its equal to last
         //element in stack, becuase then you'll keep rmeoving elements
         //unnecessarily, becuase minTrcake only store miniums milestone
         //not every elements
        if(currentElement == minTracker.back()){
            minTracker.pop_back();
        }
    }
    
    int top() {
        //assuming top will be called on non empty stack given problem statement
        return _stack.back(); //O(1)
    }
    
    int getMin() {
        return minTracker.back(); //O(1)
    }
};
