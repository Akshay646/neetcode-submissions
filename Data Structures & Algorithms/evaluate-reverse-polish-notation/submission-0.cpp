class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> results;
        for(string t : tokens)
        {
            //if its operator, off course perfrom operations
            if(t == "+" || t == "-" || t == "*" || t == "/")
            {
                int right = results.top(); results.pop();
                int left = results.top(); results.pop();

                if(t == "+"){results.push(left + right);}
                if(t == "-"){results.push(left - right);}
                if(t == "*"){results.push(left * right);}
                if(t == "/"){results.push(left / right);}
            }
            else//else just add it to stack to perform operations
            {
                results.push(stoi(t));
            }
        }

        //now the result will always on the top(stack will finally contains only an element)
        return results.top();
    }
};
