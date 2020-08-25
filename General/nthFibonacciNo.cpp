/*

Efficient way to find nth fibonacci number
n<45
*/
#include <iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    long long *a=new long long[n+1];
    a[0]=0;
    a[1]=1;
    for(i=2;i<n+1;i++)
        a[i]=a[i-1]+a[i-2];
    cout<<a[n];
    return 0;
}
