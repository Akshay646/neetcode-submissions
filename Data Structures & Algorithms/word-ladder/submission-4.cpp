class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //this act as a visited set for us and helps lookup in avg O(1)
        unordered_set<string> visited(wordList.begin(), wordList.end());
        queue<string> q;//helps to execute BFS
        int ladderLen = 0;
        //if endWord is itself not in worList, its impossible to reach it
        if(!visited.count(endWord)){return 0;}

        //since we start with beginWord, add it in queue and mark visited
        //we mark it as visited by removing it from visited set
        q.push(beginWord);
        visited.erase(beginWord);

        while(!q.empty()){
            //get the level size so we process all elements form that level
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                //get the current word node to process where to find its matching
                //words
                //in wordList by resetting each char to char from 'a-z'
                string curWord = q.front();
                q.pop();

                //you can early return if you reach endWord already
                if(curWord == endWord){return ladderLen + 1;}

                //now try replacing each char in curWord to 'a-z'
                for(int i = 0; i < curWord.size(); i++){
                    char ogChar = curWord[i];
                    for(int c = 'a'; c <= 'z'; c++){
                        curWord[i] = (char)c;
                        cout << curWord << ", ";
                        //visited.count helps to know if its already visited
                        //if count return true means yet to be visited, if removed
                        //means already visited
                        if(visited.count(curWord)){
                            q.push(curWord);
                            //now mark it as visited so we never revisit it as it
                            //will cause cycle
                            visited.erase(curWord);
                        }
                    }
                    //we need to get the replaced i with its original character back
                    //so comparisons are correct and consistent
                    curWord[i] = ogChar;
                }
            }
            ladderLen++;
        }

        //queue became empty without finding end word while traversal
        return 0;
    }
};
