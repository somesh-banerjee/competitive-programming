/*
You are given a primitive calculator that can perform the following three operations with
the current number 𝑥: multiply 𝑥 by 2, multiply 𝑥 by 3, or add 1 to 𝑥. Your goal is given a
positive integer 𝑛, find the minimum number of operations needed to obtain the number 𝑛
starting from the number 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int min3(int c1,int c2, int c3){
    int min=c1<c2?c1:c2;
    if(c3<min) return c3;
    return min;
}

vector<int> optimal_sequence(int n) {
    int i;
    std::vector<int> sequence;
    int *a=new int[n+1];
    a[0]=a[1]=0;
    a[2]=a[3]=1;
    for(i=4;i<n+1;i++){
        int c1,c2,c3;
        c2=c3=999999;
        c1=a[i-1]+1;
        if(i%2==0) c2=a[i/2]+1;
        if(i%3==0) c3=a[i/3]+1;
        a[i]=min3(c1,c2,c3);
    }
    cout<<a[n]<<endl;
    i=n;
    while(i>0){
        sequence.push_back(i);
        int c1,c2,c3;
        c2=c3=999999;
        c1=a[i-1];
        if(i%2==0) c2=a[i/2];
        if(i%3==0) c3=a[i/3];
        if(c1==min3(c1,c2,c3)) i=i-1;
        else if(c2==min3(c1,c2,c3)) i=i/2;
        else if(c3==min3(c1,c2,c3)) i=i/3;
        
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
