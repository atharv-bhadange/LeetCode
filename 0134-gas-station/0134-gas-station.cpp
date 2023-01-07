class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(accumulate(gas.begin(),gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int start = 0;
        int temp = 0;
        for(int i=0; i<n; i++) {
            temp += gas[i] - cost[i];
            if(temp < 0) {
                start = i+1;
                temp = 0;
            }
        }
        
        return start;
    }
};