#include <vector>
#include <iostream>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int maxProfit121(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int price_buy = prices[0];
        int price_cell = prices[1];
        int cand_price_buy = price_buy < price_cell ? prices[0] : prices[1];
        int current_income = price_cell - price_buy;
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i] < cand_price_buy) {
                cand_price_buy = prices[i];
            }
            if (current_income < (prices[i] - cand_price_buy)) {
                price_cell = prices[i];
                price_buy = cand_price_buy;
                current_income = price_cell - price_buy;
            }
        }

        if ((price_cell - price_buy) >= 0) return price_cell - price_buy;
        return 0;
    }
};

int main121(int argc, char* argv[]) {
    //vector<int> nums{ 7,1,5,3,6,4 };
    vector<int> nums{ 3,3,5,0,0,3,1,4 };

    Solution sol = Solution();
    cout <<  sol.maxProfit121(nums) << endl;
    for (auto val : nums) {
        cout << val << endl;
    }
    return 0;
}