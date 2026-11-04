class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    //assume:   x at t = 1 where n=2 then x will be available at
    //          (n + t)th cycle,it will be in cooldown until then.

    vector<int> tFreq(26);
    priority_queue<int> tasksToProcess;
    queue<pair<int, int>> cooldowns;

    for(char task : tasks){
        tFreq[task - 'A']++;
    }

    for(int i : tFreq){
        if(i > 0){
            tasksToProcess.push(i);
        }
    }
    int time = 0;
    //now process the tasks
    while(!tasksToProcess.empty() || !cooldowns.empty()){
        //counter ticks always
        time++;
        //now process task, reduce count and add it for cooldown
        if(!tasksToProcess.empty()){
            int curTask = tasksToProcess.top();
            tasksToProcess.pop();
            curTask--;
            int nxtAvailableAt = time + n;

            //first check if the task(s) is still available
            if(curTask > 0){
                cooldowns.push({nxtAvailableAt, curTask});
            }
        }

        //check if task is ready to be process,if so, take it out
        //from cooldown and add it to taskProcessor to process
        if(!cooldowns.empty() && cooldowns.front().first <= time){
            int taskToAdd = cooldowns.front().second;
            tasksToProcess.push(taskToAdd);
            cooldowns.pop();
        }
    }
    return time;

    }
};
