#include <iostream>
#include <cassert>
#include <vector>
typedef long long LL;

using std::vector;

int binary_search(const vector<LL> &a, LL x) {
  LL left = 0, right = (int)a.size(); 
  //write your code here
  while(right>=left){
      LL mid=left+(right-left)/2;
      if(x<a[mid])  right=mid-1;
      else if(x>a[mid]) left=mid+1;
      else return mid;
  }
  return -1;
}

int linear_search(const vector<LL> &a, LL x) {
  for (LL i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  LL n;
  std::cin >> n;
  vector<LL> a(n);
  for (LL i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  LL m;
  std::cin >> m;
  vector<LL> b(m);
  for (LL i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (LL i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
