class Solution {
public:
    int evaluateExp(int a, int b, string& op){
        switch(op[0]){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '/':
                return a / b;
            case '*':
                return a * b;
            default:
                return 0;
        }
    }
    bool IsOperator(string& s){
        return s == "*" || s == "+" || s == "/" || s == "-";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(IsOperator(tokens[i])){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int eval = evaluateExp(first, second, tokens[i]);
                //now push back to stack again as it will be one of the
                //operands for next evaluation as shown in problem
                //statement
                st.push(eval);
                continue;
            }
            //At this point, calling stoi on tokens[i] is safe, because
            //in above if, if its operator,we anyway continue
            st.push(stoi(tokens[i]));
        }

        return st.empty() ? 0 : st.top();

    }
};
