class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        unordered_map<char, int> tMap;
        int minLen = INT_MAX;
        int startInd = -1;
        //calculate the freq of t
        for(char c : t){
            tMap[c]++;
        }

        //now start building all possible substrings and check,
        //whether all chars in it has ame freq as in t
        for(int i = 0; i < s.size(); i++){
            //init a map everytime for every substring
            unordered_map<char, int> sMap;
            for(int j = i; j < s.size(); j++){
                sMap[s[j]]++;
            
                //now check if current substring of s chars has same freq as t
                bool isSameFreq  = true;
                for(auto& [c, freq] : tMap){
                    if(sMap[c] < freq){
                        isSameFreq = false;
                        break;
                    }
                }

                //We set flag becuase,if it's false means for one of the chars
                //in sMap, did not have same freq as tMap
                if(isSameFreq && (j - i + 1) < minLen){
                    minLen = j - i + 1;
                    startInd = i;
                }
            }
        }

        //now check if startInd has never set, means t does not appear in s
        return startInd == -1 ? "" : s.substr(startInd, minLen);
    }
};
