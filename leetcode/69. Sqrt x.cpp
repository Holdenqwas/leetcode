#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

// https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;


class Solution {
public:
    int mySqrt69(int x) {
        return (int)sqrt(x);
    }
};

int main69(int argc, char* argv[]) {
    Solution sol = Solution();

    cout << sol.mySqrt69(8) << endl;

    return 0;
}