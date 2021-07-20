/*
Program to add two binary strings
Difficulty Level : Medium
Given two binary strings, return their sum (also a binary string).
Example:
Input:  a = "11", b = "1"
Output: "100"
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solve(string b1, string b2){
    int i=b1.size()-1;
    int j=b2.size()-1;
    int s=0;
    string ans="";
    while(i>=0 || j>=0 || s==1){
        s += ((i >= 0)? b1[i] - '0': 0);
        s += ((j >= 0)? b2[j] - '0': 0);
        ans = char(s%2 +'0')+ans;
        s/=2;
        i--;
        j--;
    }
    return ans;
}

int main() {
	string s1,s2;
	cin>>s1>>s2;
	string ans=solve(s1,s2);
	cout<<ans;
	return 0;
}
