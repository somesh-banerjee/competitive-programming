#include <bits/stdc++.h>
using namespace std;

bool palindrome(long long r){
    long long rev=0,tmp=r;
    while(tmp){
        rev = rev*10 + (tmp%10);
        tmp/=10;
    }
    return rev == r;
}
void solve(int t){
    long long a;
    cin>>a;
    long long ans=0;
    unordered_set<long long> vis;
    for(long long i=1;i<=a/2+1;i++){
        if(a%i==0){
            if(palindrome(i) && vis.find(i)==vis.end()){
                ans++;
                vis.insert(i);
            }
            if(palindrome(a/i) && vis.find(a/i)==vis.end()){
                ans++;
                vis.insert(a/i);
            }
        }
    }
    
    cout<<"Case #"<<t<<": "<<ans<<endl;
}

int main(){
    int t,i=1;
    cin>>t;
    while(t--)
    {
        solve(i++);
    }
    return 0;
}
