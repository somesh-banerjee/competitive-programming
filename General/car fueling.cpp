#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int n, int tank, vector<int> & stops) {
    int cur=0,last,c=0;
    while(cur<=n){
        last=cur;
        while(cur<=n && stops[cur+1]-stops[last]<=tank)
            cur++;
        
        if(cur == last){
            //cout<<cur;
            return -1;}
        
        if(cur <= n){
            c++;
            //dist=dist-stops[cur];
        }
    }
    //cout<<cur;
    return c;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops.at(0)=0;
    stops.at(n+1)=d;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, n, m, stops) << "\n";

    return 0;
}
