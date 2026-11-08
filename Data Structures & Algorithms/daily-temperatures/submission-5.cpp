class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; //next greater temperature; stores indices
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int ind = st.top();
                st.pop();
                ans[ind] = i - ind;
            }
            //we store indices
            st.push(i);
        }
        return ans;
    }
};
