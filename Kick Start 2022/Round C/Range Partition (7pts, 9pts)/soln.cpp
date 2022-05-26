#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

void solve(int ttt){
    int n;
    cin>>n;
    long x,y;
    cin>>x>>y;
    long sum = (n*(n+1))/2;
    float d = (sum*1.0)/(x+y);
    long dd = d;
    if(dd!=d){
        cout<<"Case #"<<ttt<<": IMPOSSIBLE"<<endl;
        return;
    }
    long alanSum = dd*x;
    vector<int> ans;
    for(int j=n;j>0 && alanSum>0;j--){
        if(alanSum-j>=0){
            ans.push_back(j);
            alanSum -= j;
        }
    }
    if(alanSum!=0){
        cout<<"Case #"<<ttt<<": IMPOSSIBLE"<<endl;
        return;
    }
    cout<<"Case #"<<ttt<<": POSSIBLE"<<endl;
    cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int tt;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}