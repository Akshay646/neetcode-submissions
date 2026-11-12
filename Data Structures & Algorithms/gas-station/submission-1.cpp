class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasLeft = 0;
        int stInd = 0;
        int tGas = 0, tCost = 0;
        for(int i = 0; i < gas.size(); i++){
            tGas += gas[i];
            tCost += cost[i];
        }

        if(tCost > tGas){return -1;}

        for(int i = 0; i < gas.size(); i++){
            totalGasLeft += gas[i] - cost[i];
            if(totalGasLeft < 0){
                totalGasLeft = 0;
                stInd = i + 1;
            }
        }
        return stInd;
    }
};
