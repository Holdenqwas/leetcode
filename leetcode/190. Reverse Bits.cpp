#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    uint32_t reverseBits190(uint32_t n) {
        uint32_t a = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & 0b01) {
                a += pow(2, i);
            }
            n = n >> 1;
        }
        return a;
    }
};

int main190(int argc, char* argv[]) {
    Solution sol = Solution();
    //cout << 0b01 << endl;
    //cout << (0b00 & 0b01) << endl;
    //cout << (0b01 & 0b01) << endl;
    //cout << (0b10 & 0b01) << endl;
    //cout << (0b11 & 0b01) << endl;
    cout << sol.reverseBits190(0b00000010100101000001111010011100) << endl;
    cout << 964176192 << endl;

    cout << sol.reverseBits190(0b11111111111111111111111111111101) << endl;
    cout << 3221225471 << endl;


    return 0;
}