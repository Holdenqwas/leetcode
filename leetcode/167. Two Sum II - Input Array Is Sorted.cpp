#include <vector>
#include <iostream>

// https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;
// [1, 2, 7, 11, 15] , target = 9
class Solution {
public:
    vector<int> twoSum167(vector<int>& numbers, int target) {
        if (numbers.size() == 2) return  vector<int>{1, 2};

        int start = 0, end = numbers.size()-1;
        int sum = numbers[start] + numbers[end];
        while (sum != target) {
            if (sum > target) {
                sum = numbers[start] + numbers[--end];
                continue;
            }
            else {
                sum = numbers[++start] + numbers[end];
                continue;
            }
        }

        vector<int> a = { start + 1, end + 1 };
        return a;
    }
};

int main167(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a { 2,7,11,15 };
    vector<int> out = sol.twoSum167(a, 9);
    cout << out[0] << " " << out[1] << " || 1, 2" << endl;    
    
    vector<int> a2 { 2,3,4 };
    out = sol.twoSum167(a2, 6);
    cout << out[0] << " " << out[1] << " || 1, 3" << endl;    

    vector<int> a3 { -1,0 };
    out = sol.twoSum167(a3, -1);
    cout << out[0] << " " << out[1] << " || 1, 2" << endl;


    return 0;
}
