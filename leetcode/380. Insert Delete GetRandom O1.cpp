#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>


// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
    }

    bool search(int val) {
        if (mp.find(val) != mp.end())
            return true;
        return false;
    }

    bool insert(int val) {
        if (search(val))
            return false;

        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!search(val))
            return false;

        auto it = mp.find(val);
        v[it->second] = v.back();
        mp[v[it->second]] = it->second;
        v.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

int main380(int argc, char* argv[]) {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << " ";
    cout << obj->remove(2) << " ";
    cout << obj->insert(2) << " ";
    cout << obj->getRandom() << " ";
    cout << obj->remove(1) << " ";
    cout << obj->insert(2) << " ";
    cout << obj->getRandom() << endl;
    cout << "1 0 1>2 1 0>2" << endl;

    RandomizedSet* obj2 = new RandomizedSet();
    cout << obj2->remove(0) << " ";
    cout << obj2->remove(0) << " ";
    cout << obj2->insert(0) << " ";
    cout << obj2->getRandom() << " ";
    cout << obj2->remove(0) << " ";
    cout << obj2->insert(0) << endl;
    cout << "0 0 1>0 1 1" << endl;


    RandomizedSet* obj3 = new RandomizedSet();
    cout << obj3->insert(0) << " "; 
    cout << obj3->insert(2) << " "; 
    cout << obj3->insert(1) << " "; 
    cout << obj3->insert(1) << " "; 
    cout << obj3->insert(1) << " "; 
    cout << obj3->remove(0) << " ";
    cout << obj3->insert(0) << " ";
    cout << obj3->getRandom() << " ";
    cout << obj3->insert(1) << " ";
    cout << obj3->remove(2) << endl;
    cout << "1 1 1 0 0 1 1>1 0 1" << endl;
    return 0;
}