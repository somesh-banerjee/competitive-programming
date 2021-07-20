/*
Kth array element after M replacements of array elements by XOR of adjacent pairs
Difficulty Level : Easy
Given an array arr[] of size N and two integers M and K, the task is to find the array element at the Kth index after performing following M operations on the given array.

In a single operation, a new array is formed whose elements have the Bitwise XOR values of the adjacent elements of the current array.

If the number of operations M or the value of K after M operations is invalid then print -1.

Examples:

Input: arr[] = {1, 4, 5, 6, 7}, M = 1, K = 2
Output: 3
Explanation:
Since M = 1, therefore, the operation has to be performed only once on the array.
The array is modified to {1^4, 4^5, 5^6, 6^7} = {5, 1, 3, 1}.
The value of the element at index K = 2 in the updated array is 3.



Input: arr[] = {3, 2, 6}, M = 2, K = 1
Output: -1
Explanation:
Since M = 2, operation has be performed twice.
On performing 1st operation on the array {3, 2, 6} it is modified as {3^2, 2^6} = {1, 4}.
On performing 2nd operation on the array {1, 4}, it is modified as {1^4} = {5}.
After performing 2 operations, the size of the array is reduced to 1. This implies that the index K = 1 doesn’t exist after 2 operations.
Hence, the given input is invalid. So the output is -1.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> v,int m){
    vector<int> ans = v;
    while(m--){
        for(int i=0;i<ans.size()-1;i++){
            ans[i]=ans[i]^ans[i+1];
        }
    }
    return ans;
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	if(n-m<=k || m<0){
	    cout<<-1;
	    return 0;
	}
	std::vector<int> v;
	for(int i=0;i<n;i++){
	    int t;
	    cin>>t;
	    v.push_back(t);
	}
	vector<int> ans = solve(v,m);
	cout<<ans[k];
	return 0;
}
