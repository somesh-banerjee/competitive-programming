#include <bits/stdc++.h>
using namespace std;

double area(int r){
    return (double)(3.14159265358979323846)*r*r;
}
void solve(int t){
    float a,b,R;
    cin>>R>>a>>b;
    int r=R;
    double sum=0.0;
    bool left=false;
    while(r>0){
        sum += area(r);
        if(left) r/=b;
        else r*=a;
        left = !left;
    }
    cout<<"Case #"<<t<<": "<<fixed << setprecision(6)<<sum<<endl;
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