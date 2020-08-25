/*
last digit of fibonacci number
are periodic with period 60
*/
#include <iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    long long *a=new long long[300];
    a[0]=0;
    a[1]=1;
    for(i=2;i<60;i++)
        a[i]=(a[i-1]+a[i-2])%100;
    cout<<(a[n%60])%10;
    return 0;
}
