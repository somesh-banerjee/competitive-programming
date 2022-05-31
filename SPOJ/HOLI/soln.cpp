#include <iostream>
#include <vector>

using namespace std;

class Graph{
    int V;
    vector<vector<pair<int,int>>> l;
    
    public:
    Graph(int v){
        V = v;
        l.resize(V);
    }
    
    void addEdge(int u, int v, int cost){
        l[u].push_back(make_pair(v,cost));
        l[v].push_back(make_pair(u,cost));
    }
    
    int dfs(int node, vector<bool> &vis, vector<long> &count, long &ans){
        vis[node]=true;
        count[node]=1;
        
        for(auto nbr_pair:l[node]){
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if(!vis[nbr]){
                count[node] += dfs(nbr,vis,count,ans);
                int nx = count[nbr];
                int ny = V-nx;
                ans += 2*min(nx,ny)*wt;
            }
        }
        return count[node];
    }
    
    int dfs(){
        vector<bool> vis(V,false);
        vector<long> count(V,0);
        
        long ans=0;
        dfs(0,vis,count,ans);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int tt=t;
    while(t--){
        int v;
        cin>>v;
        Graph g(v);
        for(int i=0;i<v-1;i++){
            int x,y,z;
            cin>>x>>y>>z;
            g.addEdge(x-1,y-1,z);
        }
        cout<<"Case #"<<tt-t<<": "<<g.dfs()<<endl;
    }
    
    return 0;
}