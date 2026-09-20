class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> tasksToProcess;
        queue<pair<int, int>> cooldowns; //{time, freq}

        //calculate the frequency as we need most frequent tasks all the time to process
        vector<int> freqs(26, 0);
        for(char t : tasks){
            freqs[t - 'A']++;
        }
        //add all in max heap
        for(int f : freqs){
            if(f > 0){
                tasksToProcess.push(f);
            }
        }
        //we check cooldowns empty becuase, there might no tasks in max heap, but tasks
        //can be in cooldown store to cooldown until their time arrives to process(add
        //in maxheap to process)
        int time = 0;
        while(!tasksToProcess.empty() || !cooldowns.empty()){
            //time ticks anyway
            time++;
            //now check process the current task and add it for cooldown
            if(!tasksToProcess.empty()){
                int freq = tasksToProcess.top();
                tasksToProcess.pop();
                //since you process the current task, decrement its freq
                freq--;
                //check if we still have enough tasks, i.e. freq > 0
                if(freq > 0){
                    cooldowns.push({time + n, freq});
                }
            }

            //now check if any task in cooldowns is ready to process, if so, add it in
            //max heap
            //I.e. If current time arrives and becomes >= tasks sitting in cooldown, ofc, 
            //that task is now ready, move to heap and pop it out of cooldown queue
            if(!cooldowns.empty() && time >= cooldowns.front().first){
                tasksToProcess.push(cooldowns.front().second);
                cooldowns.pop();
            }
        }

        return time;
    }

};
