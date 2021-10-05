/*Develop a menu driven program for the following operations of on a Circular as well
as a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.*/
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* start = NULL;

int static glob;

void insert(){
    glob++;
    int data;
    int pos;
    cout<<"Enter data to be inserted: ";
    cin>>data;
    cout<<"Enter position to be inserted in: ";
    cin>>pos;
    node* ptr = start;
    struct node* new_node;
    new_node = new node;
    new_node->data = data;
    if(pos==1){
        if(start==NULL){
            start = new_node;
            new_node->next = start;
        }
    }
    else if(pos==glob){
        while(ptr->next!=start){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
    else{
        for(int i=0;i<pos-2;i++){
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void del(){
    int pos;
    node* ptr = start;
    if(glob==0){
        cout<<"Empty list, nothing to delete!";
    }
    else{
        do
        {
            cout<<"Enter position to delete: ";
            cin>>pos;
        } while (glob<pos);
        for (int i = 0; i < pos-2; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }
    glob--;
}

void search(){
    node* ptr = start;
    int data;
    cout<<"Enter data to be found: ";
    cin>>data;
    bool found = false;
    int ctr=0;
    do{  
        ctr++;
        if(ptr->data==data){
            found = true;
            cout<<"Found at index: "<<ctr<<endl;
        }
        ptr = ptr->next;
    }while(ptr!=NULL);
    if (found==false){
        cout<<"Element not in list"<<endl;
    }
}

void display(){
    node* ptr = start;
    cout<<"START->";
    do{
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }while (ptr!=start);
    cout<<"NULL"<<endl;
}

int main(){
    int flag;
    do
    {
        cout<<"--MENU--\n1)Insertion\n2)Deletion\n3)Search\n4)Display\n5)Exit\nINPUT: ";
        cin>>flag;
        switch (flag)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            search();
            break;
        case 4: 
            display();
            break;
        case 5:
            cout<<"Exiting...";
            break;
        default:
            cout<<"Enter a valid input!"<<endl;
            break;
        }
    } while (flag!=5);
}