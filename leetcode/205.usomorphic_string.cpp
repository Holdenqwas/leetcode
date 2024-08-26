#include <vector>
#include <string>
#include <iostream>
#include <map>

// https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isIsomorphic205(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, char> MapChar;
        map<char, char> MapCharReverse;
        map<char, char>::iterator it;
        for (int i = 0; i < t.size(); i++) {
            it = MapChar.find(t[i]);
            if (it != MapChar.end()){
                if (it->second != s[i]) {
                    return false; 
                }
            }
            else {
                it = MapCharReverse.find(s[i]);
                if (it != MapCharReverse.end()) return false;
                MapChar.insert(make_pair(t[i], s[i]));
                MapCharReverse.insert(make_pair(s[i], t[i]));
            }
        }
        return true;
    }
};

int main205(int argc, char* argv[]) {
    Solution sol = Solution();
    //cout << sol.isSubsequence392("abc", "ahbgdc") << endl;
    cout << sol.isIsomorphic205("egg", "add") << endl;
    cout << sol.isIsomorphic205("foo", "bar") << endl;
    cout << sol.isIsomorphic205("paper", "title") << endl;

    return 0;
}