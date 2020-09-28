#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class Dequeue{
    int length;
    Node *head;
    public:
    Dequeue(){
        head=NULL;
        length=0;
    }
    
    void Insert_front(){
        Node *newNode = new Node;
        if(newNode==NULL){
            cout<<"OVERFLOW!\n";
            return;
        }
        int n;
        cout<<"Enter element: ";
        cin>>n;
        newNode->data = n;
        newNode->next = head;
        head=newNode;
    }
    
    void Insert_rear(){
        Node *newNode = new Node;
        if(newNode==NULL){
            cout<<"OVERFLOW!\n";
            return;
        }
        int n;
        cout<<"Enter element: ";
        cin>>n;
        newNode->data = n;
        newNode->next = NULL;
        if(head==NULL){
            head=newNode;
            return;
        }
        Node *temp=head;
        while(true){
            if(temp->next==NULL){
                temp->next=newNode;
                break;
            }
            temp=temp->next;
        }
    }
    
    void delete_front(){
        if(head==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        else {
            Node *temp=head;
            head=head->next;
            free(temp);
        }
            
    }
    
    void delete_rear(){
        if(head==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        Node *tmp,*temp=head;
        while(true){
            if(temp->next->next==NULL){
                tmp=temp->next;
                free(tmp);
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
    }
    
    void display(){
        if(head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        cout<<"The queue from head is\n";
        Node *temp=head;
        while(true){
            if(temp==NULL){
                break;
            }
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    Dequeue d;
    while(true){
        cout<<"1 for frontinsertion, 2 for rearinsertion, 3 for display, 4 for frontdeletion and 5 for reardeletion : ";
        int n;
        cin>>n;
        if(n==1)    d.Insert_front();
        else if(n==2)   d.Insert_rear();
        else if(n==3)   d.display();
        else if(n==4)   d.delete_front();
        else if(n==5)   d.delete_rear();
        else break;
    }
    return 0;
}
