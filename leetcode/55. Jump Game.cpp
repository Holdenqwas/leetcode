#include <vector>
#include <string>
#include <iostream>
#include <queue>

// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    //bool jump(int pos, vector<int>& nums) {
    //    if (pos >= nums.size() - 1) return true;
    //    int cur_val = nums[pos];
    //    while (cur_val) {
    //        bool res = jump(pos + cur_val, nums);
    //        if (res) return true;
    //        cur_val--;
    //    }
    //    return false;
    //}
    //bool canJump55(vector<int>& nums) {
    //    return jump(0, nums);
    //}

    //struct Pos {
    //    int pos;
    //    int steps;
    //    Pos(int pos, int steps) : pos(pos), steps(steps) {};
    //};

    //bool canJump55(vector<int>& nums) {
    //    if (!nums.size()) return true;

    //    if (nums.size() == 1 && nums[0] == 0) return true;
    //    int pos = 0;
    //    queue<Pos*> order;
    //    order.push(new Pos(pos, nums[pos]));

    //    while (order.size()) {
    //        Pos*  cur_pos = order.front();
    //        for (int i = 1; i <= cur_pos->steps; i++) {
    //            int val = cur_pos->pos + i;
    //            if (val >= nums.size() - 1) return true;
    //            order.push(new Pos(val, nums[val]));
    //        }
    //        order.pop();
    //    }
    //    return false;
    //}
    // 
    bool canJump55(vector<int>& nums) {
        int value = 0;
        for (auto cur : nums) {
            if (value < 0) return false;
            if (cur > value) value = cur;
            value--;
        }
        return true;
    }
};

int main55(int argc, char* argv[]) {


    Solution sol = Solution();
    vector< int> a{ 2,3,1,1,4 };
    cout << sol.canJump55(a) << " 1" << endl;
    vector< int> a2{ 3,2,1,0,4 };
    cout << sol.canJump55(a2) << " 0" << endl;
    vector< int> a3{ 2, 0 };
    cout << sol.canJump55(a3) << " 1" << endl;
    vector< int> a4{ 6,5,4,3,2,1,0,0 };
    cout << sol.canJump55(a4) << " 0" << endl;    
    vector< int> a5{ 0 };
    cout << sol.canJump55(a5) << " 1" << endl;

    return 0;
}