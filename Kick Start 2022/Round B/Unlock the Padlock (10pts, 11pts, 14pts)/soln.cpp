#include <bits/stdc++.h>
using namespace std;

void solve(int t){
    int n,d,ans;
    cin>>n>>d;
    vector<int> dial(n);
    for(int i=0;i<n;i++){
        cin>>dial[i];
    }
    ans = dial[0]?1:0;
    for(int i=1;i<n;i++){
        if(dial[i] && dial[i]!=dial[i-1]){
            ans++;
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