#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string res;
    string str = s.substr(0, 2);
    string res1 = s.substr(2, 6);
    if(s[8]=='A' && s[0]=='1' && s[1]=='2'){
        res="00";
    }
    else if(s[8]=='P' && !(s[0]=='1' && s[1]=='2')){
        stringstream num(str); 
        int x = 0; 
        num >> x;
        res = to_string(x+12);
    }
    else
        res=str;
    //res.append(res1);
    //cout<<res<<res1;
    return  res+res1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
