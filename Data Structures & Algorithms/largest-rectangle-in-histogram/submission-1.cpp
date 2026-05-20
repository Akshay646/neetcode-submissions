class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        //if no smaller element exists to the right, we pretend there's a boundary at
        //index n
        vector<int> nse(n, n);//next smaller elements indices
        //if no smaller element exists to the left, we pretend there's a boundary at
        //index -1. it means: The rectangle can extend all the way to index 0.
        vector<int> pse(n, -1);//previous smaller elements indices

        //1. Next smaller elements
        for(int i = 0; i < n; i++){
            //we keep resolving the condition(heights[i] < st.top()) until
            //no more lesser elements than heights[i] => refer daily temp problem
            while(!st.empty() && heights[i] < heights[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //Empty whole stack for fresh pses
        while(!st.empty()) st.pop();

        //2. Previous smaller elements
        for(int i = n - 1; i >= 0; i--){
            //we keep resolving the condition(heights[i] < st.top()) until
            //no more lesser elements than heights[i] => refer daily temp problem
            while(!st.empty() && heights[i] < heights[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //now we have NSEs and PSEs
        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            //formula of area l * w
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};