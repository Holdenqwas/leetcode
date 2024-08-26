#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>


// https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isAnagram242(string s, string t) {
        if (s.size() != t.size()) return false;

        map <char, int> HashMap;
        map <char, int>::iterator it;

        for (auto a : s) {
            it = HashMap.find(a);
            if (it != HashMap.end()) it->second++;
            else HashMap.insert(make_pair(a, 1));
        }

        for (auto a : t) {
            it = HashMap.find(a);
            if (it != HashMap.end()) {
                it->second--;
                if (it->second < 0) return false;
            }
            else return false;
        }
        return true;
    }
};

int main242(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.isAnagram242("anagram", "nagaram") << endl;
    cout << sol.isAnagram242("rat", "car") << endl;


    return 0;
}