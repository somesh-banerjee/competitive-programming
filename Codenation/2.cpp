/*
Count minimum number of fountains to be activated to cover the entire garden
Difficulty Level : Hard
There is a one-dimensional garden of length N. In each position of the N length garden, a fountain has been installed. Given an array a[]such that a[i] describes the coverage limit of ith fountain. A fountain can cover the range from the position max(i – a[i], 1) to min(i + a[i], N). In beginning, all the fountains are switched off. The task is to find the minimum number of fountains needed to be activated such that the whole N-length garden can be covered by water.

Examples:

Input: a[] = {1, 2, 1}
Output: 1
Explanation:
For position 1: a[1] = 1, range = 1 to 2
For position 2: a[2] = 2, range = 1 to 3
For position 3: a[3] = 1, range = 2 to 3
Therefore, the fountain at position a[2] covers the whole garden.
Therefore, the required output is 1.

Input: a[] = {2, 1, 1, 2, 1}
Output: 2
*/
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int solve(int a[],int n){
    int c[n]={-1};
    /*
    Each c[i] stores j where i to j is covered by 1 fountain
    and this fountain has the largest j(i.e. largest range) for all fountains reaching i.
    */
    for(int i=0;i<n;i++){
        int left=max(0,i-a[i]);
        int right=min(n-1,i+a[i]);
        c[left]=max(right,c[left]);
    }
    int nxt=c[0],cnt=1;
    /*
    nxt is the right most point covered by the fountain which is currently activated
    fn is the right most point covered by the fountain which is in position i.
    select the highest fn till 'nxt' position is reached.
    when nxt is reached update nxt with greatest fn and cnt++
    */
    for(int i=1;i<n;i++){
        int fn=max(fn,c[i]);
        if(i==nxt){
            cnt++;
            nxt=fn;
        }
    }
    return cnt;

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

	auto start = high_resolution_clock::now();

	cout << solve(a,n)<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
	return 0;
}
