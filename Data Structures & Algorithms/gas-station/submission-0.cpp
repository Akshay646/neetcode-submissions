class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stInd = 0;
        int tGas = 0, tCost = 0;
        for(int i = 0; i < gas.size(); i++){
            tGas += gas[i];
            tCost += cost[i];
        }

        if(tCost > tGas){return -1;}
        int diff = 0;
        for(int i = 0; i < gas.size(); i++){
            diff += gas[i] - cost[i];

            //By any chance if your diff becomes 0, the choosen i
            //was never a valid starting point. Set new stInd to i + 1
            //and diff to 0 to avoid carrying -ve difference
            if(diff < 0){
                stInd = i + 1;
                diff = 0;
            }
        }
        return stInd;
    }
};
