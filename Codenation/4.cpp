/*
https://leetcode.com/problems/remove-k-digits/
Remove K Digits
Medium

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        string NUM;
        NUM.push_back(num[0]);
        int sz = num.size();
        for(int i=1;i<sz;i++){
            while(k && NUM.size() && num[i] < NUM[NUM.size()-1]){
                NUM.pop_back();
                k--;
                //cout<<"."<<i<<endl;
            }
            if(NUM.size()!=0 || num[i]!='0')    NUM.push_back(num[i]);
            //cout<<i<<" "<<NUM<<endl;
            sz = num.size();
        }
        while(NUM.size()>0 && k--){
            NUM.pop_back();
            if(NUM.size()==0) return "0";
        }
        if(NUM.size()==0) return "0";
        return NUM;
    }

int main()
{
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        //cout<<k;
        cout<<removeKdigits(s,k)<<endl;
    }
    return 0;
}
