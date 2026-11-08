class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> dict = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        stack<char> st;
        for(char c : s){
            if(!st.empty() && dict[st.top()] == c){
                st.pop();
                continue;
            }
            st.push(c);
        }

        return st.empty();
    }
};
