class Solution {
public:
    void backtrack(int i, string& digits,
                   unordered_map<char, string>& mp,
                   vector<string>& ans,
                   string& path) {

        // Base Case:
        // Once we've processed all digits, we've formed one valid combination.
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }

        // j ALWAYS starts from 0.
        //
        // Why?
        // Because j is NOT part of the recursion state.
        // It is just a local iterator over all possible letters
        // of the CURRENT digit.
        //
        // i is the actual recursion state.
        // It tells us WHICH digit we're currently processing.
        //
        // Example:
        // digits = "279"
        //
        // i = 0 -> choices: a b c
        // i = 1 -> choices: p q r s
        // i = 2 -> choices: w x y z
        //
        // Whenever we arrive at i = 0, we ALWAYS want to explore
        // ALL letters (a, b, c), irrespective of how we reached here.
        // Hence j always starts from 0.
        //
        // After picking one letter, our work for this digit is done.
        // The recursion state now moves to the NEXT digit (i + 1).
        //
        // Notice that recursion DOES NOT depend on j.
        // j only helps us iterate over the available choices.

        for (int j = 0; j < mp[digits[i]].size(); j++) {

            // Choose one letter for the current digit.
            path += mp[digits[i]][j];

            // Move to the next digit.
            backtrack(i + 1, digits, mp, ans, path);

            // Undo the choice so that the next iteration
            // can explore the remaining letters.
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans;
        string path;

        backtrack(0, digits, mp, ans, path);

        return ans;
    }
};