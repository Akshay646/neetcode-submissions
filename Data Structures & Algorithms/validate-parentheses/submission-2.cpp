class Solution {
public:
    bool IsClosingB(char c){
        return c == ')' || c == ']' || c == '}';
    }
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracks ={
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        for(char c : s){
            if(IsClosingB(c)){
                if(!st.empty() && c == bracks[st.top()]){
                    st.pop();
                    continue;//no need to nadd closing brack in stack
                }
            }
            st.push(c);
        }

        return st.size() <= 0;
    }
};
