#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>


// https://leetcode.com/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool wordPattern290(string pattern, string s) {
        if (pattern.size() == 1) {
            if (s.find(' ') == -1) return true;
            return false;
        }
        map<char, string> HashMap;
        map<char, string>::iterator it;
        set<string> HashSet;
        set<string>::iterator itSet;
        int i = 0, j = 0;
        for (char a : pattern) {
            if (i >= s.size()) return false;
            it = HashMap.find(a);
            if (it != HashMap.end()) {
                if (it->second == s.substr(i, it->second.size())) {
                    i = i + it->second.size();
                    if (i < s.size() && s[i] != ' ') return false;
                    i++;
                }
                else {
                    return false;
                }
            }
            else {
                j = i;
                while (s[j] != ' ') {
                    j++;
                    if (j >= s.size()) break;
                }

                itSet = HashSet.find(s.substr(i, j - i));
                if (itSet != HashSet.end()) return false;
                HashMap.insert(make_pair(a, s.substr(i, j - i)));
                HashSet.insert(s.substr(i, j - i));
                i = ++j;
            }
        }
        return i >= s.size() - 1 ? true : false;
    }
};

int main290(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.wordPattern290("a", "cat cat cat cat") << endl;
    cout << sol.wordPattern290("jquery", "jquery") << endl;
    cout << sol.wordPattern290("aaa", "aa aa aa aa") << endl;
    cout << sol.wordPattern290("abba", "dog cat cat dog") << endl;
    cout << sol.wordPattern290("abba", "dog cat cat fish") << endl;
    cout << sol.wordPattern290("aaaa", "dog cat cat dog") << endl;
    cout << sol.wordPattern290("abba", "dog dog dog dog") << endl;

    return 0;
}