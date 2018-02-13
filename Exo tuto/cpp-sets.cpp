#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    set<int> S;
    set<int>::iterator itr;
    int q, type, val;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> type >> val;
        switch (type) {
            case 1 :
                S.insert(val);
                break;
            case 2 :
                S.erase(val);
                break;
            case 3 :
                itr = S.find(val);
                if (itr != S.end()) cout << "Yes" << endl;
                else cout << "No" << endl;
        }
    }
    return 0;
}