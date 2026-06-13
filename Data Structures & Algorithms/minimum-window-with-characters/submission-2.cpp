class Solution {
public:
    string minWindow(string s, string t) {
        //Brute force approach 2:
        int minWin = INT_MAX;
        int startInd = -1;
        //generate all valid substrings
        for(int i = 0; i < s.size(); i++){
            //we keep creating new freq map as we generate all substrings starting
            //from i everytime
            vector<int> freq(256, 0);
            int count = 0;
            for(char c : t){freq[c]++;} //preinserting helps track count variable
            //try every substring startign from i;
            for(int j = i; j < s.size(); j++){
                //if s[j] is preinsert it means it will have count > 0
                if(freq[s[j]] > 0){count++;};
                //decrement the freq count for current element, helps tracks if we process
                //all the elements from t
                freq[s[j]]--;
                //if count == t.size(), the current substring has all chars from c
                if(count == t.size()){
                    if(j - i + 1 < minWin){
                        minWin =  j - i + 1;
                        startInd = i;
                    }
                    //we have found a subsring for current traversal(i to j)
                    break;
                }
            }
        }
         return startInd == -1 ? "" : s.substr(startInd, minWin);
    }
};
