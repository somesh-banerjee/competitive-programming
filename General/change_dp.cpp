/*
As we already know, a natural greedy strategy for the change problem does not work correctly for any set of
denominations. For example, if the available denominations are 1, 3, and 4, the greedy algorithm will change
6 cents using three coins (4 + 1 + 1) while it can be changed using just two coins (3 + 3). Your goal now is
to apply dynamic programming for solving the Money Change Problem for denominations 1, 3, and 4.
*/
#include <iostream>

using namespace std;

int min3(int c1,int c2, int c3){
    int min=c1<c2?c1:c2;
    if(c3<min) return c3;
    return min;
}

int get_change(int m) {
    int i;
    int *a=new int[m+1];
    a[0]=0;
    for(i=1;i<m+1;i++){
        int c1,c2,c3;
        c2=c3=999999;
        c1=a[i-1]+1;
        if(i>2) c2=a[i-3]+1;
        if(i>3) c3=a[i-4]+1;
        a[i]=min3(c1,c2,c3);
    //    cout<<a[i]<<" "<<c<<endl;
    }
    return a[i-1];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
