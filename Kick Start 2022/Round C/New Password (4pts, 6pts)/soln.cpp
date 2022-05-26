#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

string solve(){
    bool sA,cA,d,sc;
    sA=cA=d=sc=false;
    int nnn;
    cin>>nnn;
    string s;
    cin>>s;
    for(char c:s){
        if(isalnum(c)){
            if(isdigit(c)){
                d=true;
            }
            else if(c<91){
                cA=true;
            }else{
                sA=true;
            }
        }else if(c=='#' || c== '*' || c== '@' || c== '&'){
            sc=true;
        }
    }
    if(!sc) s+="*";
    if(!sA) s+="a";
    if(!cA) s+="A";
    if(!d) s+="1";
    while(s.size()<7){
        s+='a';
    }
    return s;
}

int main(){
    int tt;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        string ans = solve();
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}