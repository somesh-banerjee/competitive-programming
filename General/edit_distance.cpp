/*
The edit distance between two strings is the minimum number of operations (insertions, deletions, and
substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings.
Edit distance has applications, for example, in computational biology, natural language processing, and spell
checking. Your goal in this problem is to compute the edit distance between two strings.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min3(int c1,int c2, int c3){
    int min=c1<c2?c1:c2;
    if(c3<min) return c3;
    return min;
}

int edit_distance(const string &str1, const string &str2) {
    int l1,l2,i,j;
    l1 = str1.length();
    l2 = str2.length();
    int **arr = new int*[l1+1];
    for(i = 0; i <=l1; ++i) {
        arr[i] = new int[l2+1];
        arr[i][0]=i;
    }
    for(i = 0; i <=l2; ++i)
        arr[0][i]=i;
    for(i = 1; i <=l1; ++i){
        for(j = 1; j <=l2; ++j){
            int ins,del,mis,mat;
            ins=arr[i][j-1]+1;
            del=arr[i-1][j]+1;
            mis=arr[i-1][j-1]+1;
            mat=arr[i-1][j-1];
            if(str1[i-1]==str2[j-1])
                arr[i][j]=min3(ins,del,mat);
            else
                arr[i][j]=min3(ins,del,mis);
        }
    }
    return arr[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
