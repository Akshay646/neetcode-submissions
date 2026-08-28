class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        queue<pair<int, int>> cooldown;

        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }

        //add it into max hep
        for(int f : freq){
            if(f > 0){
                maxHeap.push(f);
            }
        }
        int time = 0;
        //now process tasks
        while(!maxHeap.empty() || !cooldown.empty()){
            //time ticks anyway
            time++;
            //check if maxHeap has any elements
            if(!maxHeap.empty()){
                int maxTask = maxHeap.top();
                maxHeap.pop();
                maxTask--; //reduce the task freq a it executes
                //add it to cooldown with time when it'll be
                //available next

                //do not push task which is already completed
                if(maxTask > 0){
                cooldown.push({maxTask, time + n});
                }
            }

            //now check if any task in cooldown is availble
            //to be processed, if so, add it to maxHeap to process
            if(!cooldown.empty() && time >=
            cooldown.front().second){
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
