#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int startStation = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            // If we run out of gas before reaching the next station,
            // reset the starting station to the next station
            if (tank < 0) {
                tank = 0;
                startStation = i + 1;
            }
        }
        
        // If the total gas is less than the total cost,
        // it's impossible to complete the circuit
        if (totalGas < totalCost) {
            return -1;
        }
        
        // If we reach here, it means we can complete the circuit
        return startStation;
    }
};
