/*
Problem Introduction
Given a sequence 𝑎1, . . . , 𝑎𝑛 of integers and an integer 𝑚 ≤ 𝑛, find the maximum among {𝑎𝑖, . . . , 𝑎𝑖+𝑚−1} for
every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1. A naive 𝑂(𝑛𝑚) algorithm for solving this problem scans each window separately.
Your goal is to design an 𝑂(𝑛) algorithm.

Input Format. The first line contains an integer 𝑛, the second line contains 𝑛 integers 𝑎1, . . . , 𝑎𝑛 separated
by spaces, the third line contains an integer 𝑚.

Constraints. 1 ≤ 𝑛 ≤ 105, 1 ≤ 𝑚 ≤ 𝑛, 0 ≤ 𝑎𝑖 ≤ 105 for all 1 ≤ 𝑖 ≤ 𝑛.

Output Format. Output max{𝑎𝑖, . . . , 𝑎𝑖+𝑚−1} for every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void max_sliding_window(vector<int> const & A, int w, int n) {
    deque<int> pos(w);
    int i,j;
    pos.push_front(0);
    for(i=1;i<w;i++){
        while(pos.size()>0 && A[i]>A[pos.back()]){
            pos.pop_back();
        }
        pos.push_back(i);
    }
    cout<<A[pos.front()]<<" ";
    while(i<n){
        while(pos.size()>0 && pos.front()<i-w+1)
            pos.pop_front();
        while(pos.size()>0 && A[i]>A[pos.back()]){
            pos.pop_back();
        }
        pos.push_back(i);
        cout<<A[pos.front()]<<" ";
        i++;
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A,w,n);
    return 0;
}
