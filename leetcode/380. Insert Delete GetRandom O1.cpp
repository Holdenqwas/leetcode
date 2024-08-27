#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>


// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        next = store.end();
    }

    bool insert(int val) {
        it = store.find(val);
        if (it == store.end()) {
            store.insert(val);
            next = store.end();
            return true;
        }
        return false;
    }

    bool remove(int val) {
        it = store.find(val);
        if (it != store.end()) {
            store.erase(it);
            next = store.end();
            return true;
        }
        return false;
    }

    int getRandom() {
        next--;
        int val = *next;
        if (next == store.begin()) next = store.end();
        return val;
    }
private:
    unordered_set<int> store;
    unordered_set<int>::iterator it;
    unordered_set<int>::iterator next;
};

int main(int argc, char* argv[]) {
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