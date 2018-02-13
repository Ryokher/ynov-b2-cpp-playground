#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    
    int n, query, mark;
    string student;
    map<string, int> s;
    cin >> n;
    while(n)
    {
        cin >> query >> student;
        if(query == 1)
        {
            cin >> mark;
        }     
        
        auto studentFound = s.find(student);
        
        switch(query)
        {
            case 1:
               if(studentFound != s.end())
               {
                   studentFound->second += mark; 
               }
               else
               {
                   s.insert(make_pair(student, mark));
               }
               break;
            case 2:
                if(studentFound != s.end())
                {
                    s.at(student) = 0;
                }
                break;
            case 3:
                if(studentFound != s.end())
                {
                    cout << studentFound->second << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
            break;
        }
        --n;
    }
    return 0;
}