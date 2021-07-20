/*
Sum of cousins of a given node in a Binary Tree
Difficulty Level : Medium
Given a binary tree and data value of a node. The task is to find the sum of cousin nodes of given node. If given node has no cousins then return -1.
Note: It is given that all nodes have distinct values and the given node exists in the tree.
Examples:
Input:
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
         key = 13
Output: 11
Cousin nodes are 5 and 6 which gives sum 11.

Input:
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
           key = 7
Output: -1
No cousin nodes of node having value 7.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node{
  int data;
  struct Node *left,*right;
};

class BT{
    public:
    Node *root;
    BT(){
        root=NULL;
    }
    BT(int t){
        Node *temp = new Node();
        temp->data=t;
        temp->left = temp->right = NULL;
        root=temp;
    }
    Node *insert(Node * rt,int t){
        if(rt==NULL){
            Node *temp = new Node();
            temp->data=t;
            temp->left = temp->right = NULL;
            rt=temp;
            return rt;
        }
    }

    long sumCousin(int key){
        if(!root || root->data==key)    return -1;
        long sum=0;
        int found=0;
        std::queue<Node*> d1;
        d1.push(root);
        while(d1.size()>0){
            if(found) return sum;
            sum=0;
            int sz = d1.size();
            while(sz--){
                Node *rt = d1.front();
                d1.pop();

                if((rt->left && rt->left->data==key) || (rt->right && rt->right->data==key))
                    found=1;
                else{
                    if(rt->left){
                        sum+=rt->left->data;
                        d1.push(rt->left);
                    }
                    if(rt->right){
                        sum+=rt->right->data;
                        d1.push(rt->right);
                    }
                }
            }
        }
    }
};

int main() {
    BT tree(1);
    tree.root->left = tree.insert(tree.root->left,3);
    tree.root->right = tree.insert(tree.root->right,7);
    tree.root->left->left = tree.insert(tree.root->left->left,6);
    tree.root->left->right = tree.insert(tree.root->left->right,5);
    tree.root->left->right->left = tree.insert(tree.root->left->right->left,10);
    tree.root->right->left = tree.insert(tree.root->right->left,4);
    tree.root->right->right = tree.insert(tree.root->right->right,13);
    tree.root->right->left->left = tree.insert(tree.root->right->left->left,17);
    tree.root->right->left->right = tree.insert(tree.root->right->left->right,15);
    /*cout<<tree.root->data<<endl;
    cout<<tree.root->left->data<<endl;
    cout<<tree.root->right->data<<endl;
    cout<<tree.root->left->left->data<<endl;
    cout<<tree.root->left->right->data<<endl;*/
    cout<<".";
    auto start = high_resolution_clock::now();
    cout<<tree.sumCousin(13)<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}
