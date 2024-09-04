#include <vector>
#include <iostream>

// https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    //int canCompleteCircuit134(vector<int>& gas, vector<int>& cost) {
        //int s_gas = 0, s_cost = 0;
        //int index = 0;
        //int diff = 0;
        //for (int i = 0; i < gas.size(); i++) {
        //    s_gas += gas[i];
        //    s_cost += cost[i];

        //    if ((gas[i] - cost[i]) <= diff) {
        //        index = i;
        //        diff = gas[i] - cost[i];
        //    }
        //}
        //if (s_cost > s_gas) return -1;
        //return (index + 1) % gas.size();
    //}

    //int canCompleteCircuit134(vector<int>&gas, vector<int>&cost) {
    //    int s_gas = 0, s_cost = 0;
    //    for (int i = 0; i < gas.size(); i++) {
    //        s_gas += gas[i];
    //        s_cost += cost[i];
    //    }
    //    if (s_cost > s_gas) return -1;

    //    for (int i = 0; i < gas.size(); i++) {
    //        int cur_index = i;

    //        int tank = 0;
    //        do {
    //            tank += gas[cur_index];
    //            tank -= cost[cur_index];
    //            cur_index++;

    //            //if (tank < 0) break;

    //            if (cur_index >= gas.size()) cur_index = 0;
    //        } while (cur_index != i && tank >= 0);

    //        if (cur_index == i) return cur_index;
    //    }

    //    return -1;
    //}

    int canCompleteCircuit134(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int surplus = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0) {
                surplus = 0;
                start = i + 1;
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }
};

int main134(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a{ 1,2,3,4,5 };
    vector<int> b{ 3,4,5,1,2 };
    cout << sol.canCompleteCircuit134(a, b) << " 3" << endl;

    vector<int> a2{ 2,3,4 };
    vector<int> b2{ 3,4,3 };
    cout << sol.canCompleteCircuit134(a2, b2) << " -1" << endl;

    vector<int> a3{ 5,8,2,8 };
    vector<int> b3{ 6,5,6,6 };
    cout << sol.canCompleteCircuit134(a3, b3) << " 3" << endl;

    vector<int> a4{ 5,1,2,3,4 };
    vector<int> b4{ 4,4,1,5,1 };
    cout << sol.canCompleteCircuit134(a4, b4) << " 4" << endl;

    return 0;
}
