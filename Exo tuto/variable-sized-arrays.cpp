#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[]) {
    int a;
    int b;
    cin >> a >> b;
    int** outer = new int*[a];
    for(int i = 0; i < a; i++) {
        int c;
        cin >> c;
        outer[i] = new int[c];
        for(int j = 0; j < c; j++) {
            cin >> outer[i][j];
        }
    }
    while(b-- > 0) {
        int d;
        int c;
        cin >> d >> c;
        cout << outer[d][c] << endl;
    }

    return 0;
}
