#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;
//https://www.spoj.com/problems/HOLI/
int dfs(unordered_map<int,vector<int>> &m, unordered_map<string,int> &w, int &res, int node, int parent, int n){
    if(m[node].size()==1 && m[node][0]==parent) return 1;
    int ans=0;
    for(int i:m[node]){
        if(i!=parent){
            int ret = dfs(m,w,res,i,node,n);
            string key = to_string(node)+"-"+to_string(i);
            ans += ret;
            //cout<<key<<" "<<w[key]<<endl;
            //cout<<ret<<endl;
            res += min(ret,n-ret)*2*w[key];
        }
    }
    //cout<<ans<<endl;
    return 1+ans;
}

int solve(){
    int n;
    cin>>n;
    unordered_map<int,vector<int>> m;
    unordered_map<string,int> w;
    int res;
    res=0;
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        m[x].push_back(y);
        m[y].push_back(x);
        string key = to_string(x)+"-"+to_string(y);
        w[key]=z;
        key = to_string(y)+"-"+to_string(x);
        w[key]=z;
    }
    for(int i:m[1]){
        int ret = dfs(m,w,res,i,1,n);
        string key = to_string(1)+"-"+to_string(i);
        // cout<<key<<" "<<w[key]<<endl;
        // cout<<ret;
        res += min(ret,n-ret)*2*w[key];
    }
    //cout<<res<<endl;
    return res;
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int res = solve();
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}