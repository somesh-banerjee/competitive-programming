/*
fib(n) mod m is periodic and the 
sequence starts with 01....

This is also called pisano period, depends on m.

find the period and then mod it with n.
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long i,n,m;
    cin>>n>>m;
    vector<long> a;
    a.push_back(0);
    a.push_back(1);
    i=2;
    while(m>=2){
        a.push_back((a[i-1]+a[i-2])%m);
        if(a[i]==1 && a[i-1]==0)
            break;
        i++;
    }
    i--;
    n=n%i;
    cout<<a[n];
    return 0;
}
