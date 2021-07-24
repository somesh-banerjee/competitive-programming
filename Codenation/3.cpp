/*
Represent a number as the sum of positive numbers ending with 9
Difficulty Level : Hard
Given an integer N, the task is to check if N can be expressed as a sum of integers having 9 as the last digit (9, 19, 29, 39…), or not. If found to be true, then find the minimum count of such integers required to obtain N. Otherwise print -1.

Examples:

Input: N = 156
Output: 4
Explanation:
156 = 9 + 9 + 9 + 129

Input: N = 60
Output: -1
Explanation:
No possible way to obtain sum 60 from numbers having 9 as the last digit.
*/
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int solve(int n){
    int k=10-(n%10);
    n=n-9*(k-1);
    if(n%10==9)
        return k;
    return -1;
}

int main()
{
    int n;
    cin>>n;

	auto start = high_resolution_clock::now();

	cout << solve(n)<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
	return 0;
}
