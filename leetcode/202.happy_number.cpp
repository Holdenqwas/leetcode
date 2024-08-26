#include <unordered_map>
#include <math.h>
#include <iostream>



// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isHappy202(int n) {
        //cout << "Input = " << n << endl;
        unordered_map<int, int> Dict;
        unordered_map<int, int> PrevValue;
        int i, value;
        for (i = 0; i < 10; i++) {
            Dict.insert(make_pair(i, i * i));
        }
        
        i = 1;
        value = 0;
        int t, t2;
        while (n != 1) {
            while (n >= 10) {
                t2 = n % 10;
                t = Dict.find(t2)->second;
                //cout << t2 << ' ';
                value += t;
                n = n / 10;
            }
            t2 = n % 10;
            t = Dict.find(t2)->second;
            //cout << t2 << ' ';
            value += t;

            //cout << " = " << value << endl;
            n = value;
            if (PrevValue.find(value) != PrevValue.end()) return false;
            PrevValue.insert(make_pair(value, 0));
            value = 0;
        }
        return true;
    }
};

int main202(int argc, char* argv[]) {
    Solution sol = Solution();

    cout << sol.isHappy202(19) << endl;
    cout << sol.isHappy202(2) << endl;

    return 0;
}