#include <vector>
#include <algorithm>
#include <iostream>



// https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int hIndex274(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < (i + 1)) {
                return i;
            }
        }
        return citations.size();
    }
};

int main274(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a{ 3,0,6,1,5 };
    cout << sol.hIndex274(a) << endl;    
    
    vector<int> a2{ 1,3,1 };
    cout << sol.hIndex274(a2) << endl;



    return 0;
}