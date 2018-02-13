#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i,c,b;
    string list[11]={"even","odd","one","two","three","four","five","six","seven","eight","nine"};
    cin>>c>>b;
    for(i=c;i<=b;i++)
    {
        if((i>9) && (i%2==0))  cout<<list[0]<<endl;
        else if((i>9) && (i%2!=0)) cout<<list[1]<<endl;
        else    cout<<list[i+1]<<endl;
    }
    return 0;
}