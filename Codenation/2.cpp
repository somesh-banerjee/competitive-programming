/*
https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
1326. Minimum Number of Taps to Open to Water a Garden
Hard

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

Example 3:
Input: n = 7, ranges = [1,2,1,0,2,1,0,1]
Output: 3

Example 4:
Input: n = 8, ranges = [4,0,0,0,0,0,0,0,4]
Output: 2

Example 5:
Input: n = 8, ranges = [4,0,0,0,4,0,0,0,4]
Output: 1

Constraints:

1 <= n <= 10^4
ranges.length == n + 1
0 <= ranges[i] <= 100
*/
int minTaps(int n, vector<int>& a) {
        int c[n+1];
    /*
    Each c[i] stores j where i to j is covered by 1 fountain
    and this fountain has the largest j(i.e. largest range) for all fountains reaching i.
    */
    for(int i=0;i<n+1;i++){
        c[i]=-1;
        int left=max(0,i-a[i]);
        int right=min(n,i+a[i]);
        c[left]=max(right,c[left]);
    }
    int nxt=c[0],cnt=1;
    /*
    nxt is the right most point covered by the fountain which is currently activated
    fn is the right most point covered by the fountain which is in position i.
    select the highest fn till 'nxt' position is reached.
    when nxt is reached update nxt with greatest fn and cnt++
    */
        int fn=c[0];
    for(int i=1;i<n;i++){
      fn=max(fn,c[i]);
        if(i==nxt){
            cnt++;
            nxt=fn;
        }
    }
    if(nxt!=n)    return -1;
    return cnt;
}
