class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0, area = 0;
        stack<int> st;
        
        //Calculdate PSE on the fly
        for(int i = 0; i < n; i++){
            //Here we get the right boundary(smaller elements) for current bar(st.top())
            while(!st.empty() && heights[i] < heights[st.top()]){
                int rB = i;
                int currentBar = st.top();
                st.pop();//we remove to get PSE of current bar
                //we check  after pop if stack is empty means no PSEs for current bar
                int lB = st.empty() ? -1 : st.top();
                area = heights[currentBar] * (rB - lB - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        //Now any elements are present in the stack it means they do not have
        //any NSEs, so we have to also calculate the area where nse becomes n.
        //as from those bars, width becomes n - st.top() - 1, we extend upto n
        //as if no NSE, we can take full width
        while(!st.empty()){
            int barHeight = heights[st.top()];
            st.pop(); //=> as we got the bar for we calculate area
            int lB = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, barHeight * (n - lB - 1));
        }

        return maxArea;
    }
};