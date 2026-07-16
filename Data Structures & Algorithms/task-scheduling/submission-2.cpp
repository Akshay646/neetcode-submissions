class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       int currentTime = 0;
       priority_queue<int> maxHeap;
       queue<pair<int, int>> cooldown;
       unordered_map<char, int> mp;
       for(char task : tasks){
        mp[task]++;
       }
       for(const auto& t : mp){
        maxHeap.push(t.second);
       }
       while(!maxHeap.empty() || !cooldown.empty()){
        currentTime++;
        if(!maxHeap.empty()){
            int freq = maxHeap.top();
            maxHeap.pop();
            freq--;
            //make sure you do not 0 freq as that task is already finished
            if(freq > 0){
            cooldown.push({freq, currentTime + n});
            }
        }
        //check if any tasks are ready
        if(!cooldown.empty() && cooldown.front().second <= currentTime){
            int readyTask = cooldown.front().first;
            cooldown.pop();
            maxHeap.push(readyTask);
        }
       }
       return currentTime;
    }
};
