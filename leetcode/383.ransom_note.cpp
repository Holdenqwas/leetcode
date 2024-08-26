#include <vector>
#include <string>
#include <iostream>
#include <map>

// https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool canConstruct383(string ransomNote, string magazine) {
        map<char, int> DictMagazine;
        int i;
        map<char, int>::iterator it;
        for (i = 0; i < magazine.size(); i++) {
            it = DictMagazine.find(magazine[i]);
            if (it != DictMagazine.end()) {
                it->second++;
            }
            else {
                DictMagazine.insert(make_pair(magazine[i], 1));
            }
        }

        for (i = 0; i < ransomNote.size(); i++) {
            it = DictMagazine.find(ransomNote[i]);
            if (it != DictMagazine.end() && it->second > 0) {
                it->second--;
            }
            else return false;
        }
        return true;
    }
};

int main383(int argc, char* argv[]) {
    Solution sol = Solution();
    //cout << sol.isSubsequence392("abc", "ahbgdc") << endl;
    cout << sol.canConstruct383("aa", "aab") << endl;

    return 0;
}