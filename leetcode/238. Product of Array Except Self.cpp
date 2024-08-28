#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>


// https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf238(vector<int>& nums) {
        int size = nums.size();

        vector<int> answer;
        answer.reserve(size);

        vector<int> prefix{ nums[0] };
        prefix.reserve(size);

        vector<int> suffix{ nums[size -1]};
        suffix.reserve(size);

        for (int i = 1; i < size; i++) {
            prefix.push_back(prefix[i - 1] * nums[i]);
        }
        for (int i = 1; i < size; i++) {
            suffix.push_back(suffix[i - 1] * nums[size - i - 1]);
        }


        for (int i = 0; i < size; i++) {
            if (i == 0) {
                answer.push_back(suffix[size - 2]);
            }
            else if (i == (size - 1)) {
                answer.push_back(prefix[size - 2]);
            }
            else {
                int a = prefix[i - 1];
                int b = suffix[size - i - 2];
                answer.push_back(a * b);
            }
        }
        return answer;
    }
};

int main238(int argc, char* argv[]) {
    Solution sol = Solution();

    vector<int> a{ 1,2,3,4 };
    for (auto i : sol.productExceptSelf238(a)) {
        cout << i << " ";
    }
    cout << endl << "24 12 8 6";

    cout << endl;


    vector<int> a2{ -1,1,0, -3,3 };
    for (auto i : sol.productExceptSelf238(a2)) {
        cout << i << " ";
    }
    cout << endl << "0 0 9 0 0";
    return 0;
}