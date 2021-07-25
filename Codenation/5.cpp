/*
https://leetcode.com/problems/backspace-string-compare/
844. Backspace String Compare
Easy

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".
Example 4:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s1,s2;
        //s1.push_back(s[0]);
        //s2.push_back(t[0]);
        for(int i=0;i<s.size() || i<t.size();i++){
            if(i<s.size() && s[i]=='#'){
                if(s1.size()!=0)    s1.pop_back();
            }else if(i<s.size()){
                s1.push_back(s[i]);
            }
            if(i<t.size() && t[i]=='#'){
                if(s2.size()!=0)    s2.pop_back();
            }else if(i<t.size()){
                s2.push_back(t[i]);
            }
        }
        return s1==s2;
    }
};
