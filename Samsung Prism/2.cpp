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
#include <deque>
using namespace std;

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
    Node *insert(Node * rt,int t, int i){
        if(rt==NULL){
            Node *temp = new Node();
            temp->data=t;
            temp->left = temp->right = NULL;
            rt=temp;
            return rt;
        }
        else if(i%2==0) rt->right = insert(rt->right,t,i/2);
        else rt->left = insert(rt->left,t,i/2);
    }

    long sumCousin(int key){
        long sum=0,level=0;
        int found=0,rsib;
        std::vector<Node*> d1,d2,sib;
        d1.push_back(root);
        while(d1.size()>0){
            for(int i=0;i<d1.size();i++){
                if(d1[i]->data==key){
                    found=1;
                    break;
                }
                if(d1[i]->left!=NULL){
                    d2.push_back(d1[i]->left);
                    if(d1[i]->left->data==key)  rsib=d1[i]->right->data;
                }
                if(d1[i]->right!=NULL){
                    d2.push_back(d1[i]->right);
                    if(d1[i]->right->data==key)  rsib=d1[i]->left->data;
                }
            }
            if(found==1){
                sib=d1;
                break;
            }
            d1.clear();
            d1=d2;
            d2.clear();
        }
        for(int i=0;i<sib.size();i++){
            if(sib[i]->data!=key){
                sum+=sib[i]->data;
            }
        }
        return sum-rsib;
    }
};

int main() {
    BT tree(1);
    tree.root->left = tree.insert(tree.root->left,2,0);
    tree.root->right = tree.insert(tree.root->right,3,0);
    tree.root->left->left = tree.insert(tree.root->left->left,4,0);
    tree.root->left->right = tree.insert(tree.root->left->right,5,0);
    tree.root->right->left = tree.insert(tree.root->right->left,6,0);
    /*cout<<tree.root->data<<endl;
    cout<<tree.root->left->data<<endl;
    cout<<tree.root->right->data<<endl;
    cout<<tree.root->left->left->data<<endl;
    cout<<tree.root->left->right->data<<endl;*/
    cout<<tree.sumCousin(5);
}
