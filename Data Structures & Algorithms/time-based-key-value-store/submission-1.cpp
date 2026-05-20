class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timeMap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        auto& pairs = timeMap[key];

        auto itr = upper_bound(
            pairs.begin(),
            pairs.end(),
            timestamp,
            [](int value, const pair<string,int>& p) {
                return value < p.second;
            }
        );

        if(itr == pairs.begin()) {
            return "";
        }

        --itr;

        return itr->first;
    }
};