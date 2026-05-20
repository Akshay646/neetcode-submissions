class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        //generate frequencies
        for(char task : tasks){
            freq[task]++;
        }

        //add frequencies to max heap
        priority_queue<int> maxHeap;
        for(auto task : freq){
            maxHeap.push(task.second);
        }

        int time = 0;
        queue<pair<int, int>> coolDownStore;//-> {remainingFreq, nextAvailableTime}
        
        //we also check if q is not empty. becuase after maxheap is empty
        //there are still chnaces after some time, any valid task may come as
        //times++ and then gets enter to maxHeap, else only maxHeap check
        //will result in early false return
        while(!maxHeap.empty() || !coolDownStore.empty()){
            //here time always gets incremented as its one cpu interval everytime
            time++;

            //execute task which is at front
            if(!maxHeap.empty()){
                int currentFreq = maxHeap.top();
                maxHeap.pop();
                currentFreq -= 1; //-> reduce freqeuncy as a task is done

                //now if frequency of this tasks still exists, add it for cooldonw
                if(currentFreq > 0){
                    //next available time for this task is now time + n
                    coolDownStore.push({currentFreq, time + n});
                }
            }

            //check if any valid task is ready at this current time
            if(!coolDownStore.empty() && coolDownStore.front().second == time){
                //add this task in max heap for execution
                maxHeap.push(coolDownStore.front().first);
                coolDownStore.pop();
            }
        }

        return time;
    }
};
