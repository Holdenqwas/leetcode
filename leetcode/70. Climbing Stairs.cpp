#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

// https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;


class Solution {
public:
    int climbStairs70(int n) {
        if (n < 4) return n;
        vector<int> mem{ 0, 1, 2 };
        
        for (int i = 3; i <= n; i++) {
            mem.push_back(mem[i - 1] + mem[i - 2]);
        }
        return mem.back();
    }
};

int main70(int argc, char* argv[]) {
    Solution sol = Solution();

    cout << sol.climbStairs70(1) << endl;
    cout << sol.climbStairs70(2) << endl;
    cout << sol.climbStairs70(3) << endl;
    cout << sol.climbStairs70(4) << endl;
    cout << sol.climbStairs70(5) << endl;

    return 0;
}