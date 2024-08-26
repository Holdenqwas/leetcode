

#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    void rotate189(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> output;
        output.reserve(size);
        output.resize(size);

        for (int i = 0; i < size; i++) {
            if ((i + k) < size) {
                output[(i + k)] = nums[i];
            }
            else {
                output[(i + k) % size] = nums[i];
            }
        }

        nums = output;
    }
};

int main189(int argc, char* argv[]) {
    Solution sol = Solution();


    return 0;
}