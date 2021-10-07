#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;

void insertCircularly(){
    struct node* new_node;
    new_node = new node;
    node* ptr = start;
    int data;
    cout<<"Enter data to be inserted: ";
    cin>>data;
    new_node->data = data;
    if(start==NULL){
        start = new_node;
        new_node->next = start;
    }
    else{
        while(ptr->next!=start || ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
}
void insertNonCircularly(){
    struct node* new_node;
    new_node = new node;
    node* ptr = start;
    int data;
    cout<<"Enter data to be inserted: ";
    cin>>data;
    new_node->data = data;
    if(start==NULL){
        start = new_node;
        new_node->next = NULL;
    }
    else{
        while(ptr->next!=start || ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
    }
}
void display(){
    node* ptr = start;
    cout<<"START->";
    do{
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }while(ptr->next!=start || ptr->next!= NULL);
    if(ptr->next==NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<"START"<<endl;
    }
    
}
bool checkCircular(){
    node* ptr = start;
    bool is = false;
    if(start==NULL){
        is = true;
    }
    else{
        while(ptr->next!=start){
            if(ptr->next==NULL){
                is = false;
                break;
            }
            ptr = ptr->next;
            is = true;
        }
    }
    return is;
}

int main(){
    int flag = 0;
    while(flag!=5){
        cout<<"--MENU--\n1)Insert Circularly\n2)Insert Non-circularly\n3)Display\n4)Check circular\n5)Exit\nINPUT: ";
        cin>>flag;
        switch (flag)
        {
        case 1:
            insertCircularly();
            break;
        case 2:
            insertNonCircularly();
            break;
        case 3:
            display();
            break;
        case 4:
            if(checkCircular()==1){
                cout<<"Linked list is circular"<<endl;
            }
            else{
                cout<<"Linked list is Non Circular"<<endl;
            }
            break;
        case 5:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Enter a valid input!"<<endl;
            break;
        }
    }
}