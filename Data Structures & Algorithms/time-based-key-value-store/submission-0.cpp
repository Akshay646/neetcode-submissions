class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //if no such key found, return ""
        if(!timeMap.count(key)){
            return "";
        }
        
        //Now we have to find the timestamp in these entries
        //which is <= given timestamp.

        //As problem statement says, set() calls are made with strictly increasing
        //timestamps per key.
        //You do not have to  create copy of timeMap[key] and store in extra vect<pair>
        int l = 0, r = timeMap[key].size() - 1;
        string value = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(timeMap[key][mid].first <= timestamp){
                value =  timeMap[key][mid].second;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

       return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */