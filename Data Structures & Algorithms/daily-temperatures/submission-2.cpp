class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
 // for each day i, we want the next warmer temperature
// we keep indices in a monotonic decreasing stack,
// meaning temperatures in the stack are waiting for a warmer day
// when a new temperature is higher than the stack top,
// we’ve found the answer for that earlier day,
// so we pop it and record the distance
// each index is pushed once and popped once → O(n)
//days sit in the stack waiting… a warmer day arrives… we resolve them.

        //we store days(indices), as we want to recall them while finding the distance
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++)
        {
            //we start getting warmer day(s) than prev day(s)
            //whenever we get top < current temp, ofc, thats immediate greater
            //and we keep comparing it until current temp becomes lesser or 
            //stack become empty
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                //assining the distance at respective elements index
                ans[st.top()] = i - st.top();
                //we now alredy resolve top element, so pop it out
                st.pop(); 
            }
            st.push(i); //push the day into stack for future comparisons
        }
        return ans;
    }
};