/*
Find sum of all left leaves in a given Binary Tree
Difficulty Level : Easy
Given a Binary Tree, find the sum of all left leaves in it. For example, sum of all left leaves in below Binary Tree is 5+1=6.
    9
   /  \
  8    6
 /\   /
5  2 1
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

    long leftLeafsum(){
        if(!root)    return -1;
        long sum=0;
        std::queue<Node*> d1;
        d1.push(root);
        while(d1.size()>0){
            int sz = d1.size();
            while(sz--){
                Node *rt = d1.front();
                d1.pop();

                if(rt->left && rt->left->left==NULL && rt->left->right==NULL)
                    sum+=rt->left->data;
                else{
                    if(rt->left){
                        d1.push(rt->left);
                    }
                    if(rt->right){
                        d1.push(rt->right);
                    }
                }
            }
        }
        return sum;
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
    auto start = high_resolution_clock::now();
    cout<<tree.leftLeafsum()<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}
