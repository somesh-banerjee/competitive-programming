#include <vector>
#include <list>
#include <map>
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

#define SD(a) scanf("%d", &a)
#define SDD(a, b) scanf("%d %d", &a, &b)
#define SDDD(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define PD(a) printf("%d", a)
#define PS(a) printf("%s", a)
#define PL(a) printf("%lld", a)
#define PN printf("\n")

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SFOR(i,a,b,c) for(int i=a;i<b;i+=c)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define SRT(x) sort(ALL(x))
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,127,sizeof(x))
#define MOD 1000000007
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long UL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PI;


int main(){
    int t;
    SD(t);
    VI ans;
    while(t--)
    {
        LL i,j,k,n,s=0,rem=-1,f=0;
        cin>>n>>k;
        int q[n];
        for(i=0;i<n;i++){
            cin>>q[i];
            s+=(q[i]-k);
            if(!f && s<0){
                f=1;
                rem=i;
            }
        }
        if(f){  
            cout<<rem+1<<endl;
            continue;
        }
        LL ans=s/k;
        cout<<ans+n+1<<endl;
    }
    return 0;
}


