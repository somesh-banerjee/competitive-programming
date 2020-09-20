/*
A thief finds much more loot than his bag can fit. Help him to find the most valuable combination
of items assuming that any fraction of a loot item can be put into his bag.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool sortcol( const vector<double>& v1, 
               const vector<double>& v2 ) { 
 return v1[2] > v2[2]; 
} 

int main()
{
    long n,i,W;
    double tmp1,tmp2,ans=0;
    vector<vector <double>> vw;
    cin>>n>>W;
    for(i=0;i<n;i++){
        vector<double> t;
        cin>>tmp1;
        t.push_back(tmp1);
        cin>>tmp2;
        t.push_back(tmp2);
        t.push_back(tmp1/tmp2);
        vw.push_back(t);
    }
    sort(vw.begin(), vw.end(),sortcol);
    i=0;
    while(W>0){
        long a=(vw[i][1]<W)?vw[i][1]:W;
        ans+=a*vw[i++][2];
        W = W - a;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    cout<<ans;
    return 0;
}
