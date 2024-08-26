#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    char addChar(char ac, char bc, bool& needAdd) {
        char out = '0';
        if (ac == bc) {
            if (ac == '1') {
                
                out = (needAdd ? '1' : '0');
                needAdd = true;
            }
            else {
                out = (needAdd ? '1' : '0');
                needAdd = false;
            }
        }
        else {
            if (needAdd) {
                out = '0';
                needAdd = true;
            }
            else {
                out = '1';
                needAdd = false;
            }
        }
        return out;
    }

    string addBinary67(string a, string b) {

        int max_size = max(a.size(), b.size());
        string res(max_size + 1, '0');
        bool needAdd = false;
        char ac, bc;
        int i;
        for (i = 0; i < min(a.size(), b.size()); i++) {
            ac = a[a.size() - 1 - i];
            bc = b[b.size() - 1 - i];
            res[max_size - i] = addChar(ac, bc, needAdd);  
        }

        if (a.size() < b.size()) a = b;
        while (i < (max_size)) {
            ac = a[a.size() - 1 - i];
            res[max_size - i] = addChar(ac, '0', needAdd);
            i++;
        }
        if (needAdd) res[max_size - i] = '1';
        else return res.substr(1, res.size());
        return res;
    }
};

int main67(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.addBinary67("11", "1") << endl;

    cout << sol.addBinary67("1010", "1011") << endl;   
    cout << sol.addBinary67("0", "0") << endl;


    return 0;
}