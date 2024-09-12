#include <vector>
#include <iostream>

// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int maxArea11(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int sum = min(height[left], height[right]) * (right - left);
        int temp_sum = 0;
        while (right > left) {
            if (height[left] < height[right]) left++;
            else right--;
            temp_sum = min(height[left], height[right]) * (right - left);
            if (temp_sum > sum) sum = temp_sum;
        }
        return sum;
    }
};

int main11(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a{ 1,8,6,2,5,4,8,3,7 };
    cout << sol.maxArea11(a) << " || 49" << endl;

    vector<int> a2{ 1,1 };
    cout << sol.maxArea11(a2) << " || 1" << endl;

    vector<int> a3{ 1,8,6,100,100,4,8,3,7 };
    cout << sol.maxArea11(a3) << " || 100" << endl;


    return 0;
}
