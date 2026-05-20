class Solution {
public:
    bool isValid(string s) {
        string st; //=> string itself behaves like stack mechanically
        //store closing parentheses for opened one
        //why? becuase current element at stack presents opening parentheses
        //now we wanna check if current char in string is actually closing to it
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for(char c : s)
        {
            if(!st.empty() && st.back() == closeToOpen[c])
            {
                st.pop_back();
                continue; //go to next char now
            }
            st.push_back(c);
        }

        //now if string is empty, we got all the matching braces
        return st.empty();
    }
};
