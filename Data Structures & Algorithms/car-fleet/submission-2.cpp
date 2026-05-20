class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carsData;
        for(int i = 0; i < position.size(); i++)
        {
            carsData.push_back({position[i], speed[i]});
        }

        //now sort based on their positions
        sort(carsData.begin(), carsData.end());
        int n = carsData.size();
        stack<double> fleets;
        for(int i = n - 1; i >= 0; i--){
            double arrivalTime = (double)(target - carsData[i].first) / carsData[i].second;

            //if arrival time of current car is faster than the fleet/car
            if(!fleets.empty() && arrivalTime <= fleets.top()){
                continue;
            }
            fleets.push(arrivalTime);
        }
        return fleets.size();
    }
};
