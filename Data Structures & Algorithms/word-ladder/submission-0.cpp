class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //we're using unordered set for avg O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end()), visited;

        int lLen = 1;
        //queue to process the words level wise
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            //Since each level can have multiple valid formations, process
            //all/complete formations of the current level
            int levelSize = q.size();

            while(levelSize--){
                string curr = q.front();
                q.pop();

                if(curr == endWord) {
                    return lLen;
                }

                //try replacing each position/char in curr with a to z
                for(int i = 0; i < curr.size(); i++){
                    //i represents each position in curr
                    char ogChar = curr[i];

                    for(int j = 'a'; j <= 'z'; j++){
                        //keep replacing current position with a to z
                        curr[i] = (char)j;

                        //only add formations which exist in wordList
                        //and have never been generated before
                        if(st.count(curr) && !visited.count(curr)){
                            q.push(curr);

                            //mark the used formation as visited
                            visited.insert(curr);
                        }
                    }

                    //bring back the original char before moving to next position
                    curr[i] = ogChar;
                }
            }

            //queue processes one complete level at a time
            lLen = lLen + 1;
        }

        return 0;
    }
};