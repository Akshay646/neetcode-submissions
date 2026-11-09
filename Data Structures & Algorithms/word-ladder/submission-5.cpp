class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int ladderLen = 1;
        queue<string> q;
        if(!st.count(endWord)){return 0;}

        q.push(beginWord);
        st.erase(beginWord);

        while(!q.empty()){
            // traverse level by level
            //the total no.of elements in queue at this point are
            //the total no. elements at that level as per BFS
            int lSize = q.size();
            for(int i = 0; i < lSize; i++){
                //get the current Word
                string curWord = q.front();
                q.pop();

                //check whether we reach the endWord
                if(curWord == endWord){
                    return ladderLen;
                }
                //try forming the other words, check if exists in
                //dict. if so, remove the from set so we don't
                //visit them again and add it to queue to process
                for(int j = 0; j < curWord.size(); j++){
                    //retain the og char which we gonna change
                    //we'll need it back when trying other
                    //formations
                    char ogChar = curWord[j];
                    for(int k = 'a'; k <= 'z'; k++){
                        curWord[j] = (char)k;
                        if(st.count(curWord)){
                            q.push(curWord);
                            st.erase(curWord);
                        }
                    }
                    //restore ith word back to original form
                    curWord[j] = ogChar;
                }
            }
            ladderLen++;
        }
        return 0;
    }
};
