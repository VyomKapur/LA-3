#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* start = NULL;

void insert(){
    int data;
    cout<<"Enter data to be inserted: ";
    cin>>data;
    struct node* new_node;
    new_node = new node;
    node* ptr = start;
    new_node->data = data;
    if(start == NULL){
        start = new_node;
        new_node->prev = start;
        new_node->next = NULL;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = NULL;
    }
}   
void display(){
    node* ptr = start;
    cout<<"START->";
    while(ptr!= NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL";
}
int findSize(){
    int ctr = 0;
    node* ptr = start;
    while(ptr!= NULL){
        ptr = ptr->next;
        ctr++;
    }
    return ctr;
}

int main(){
    int flag = 0;
    while(flag!=4){
        cout<<"--MENU--\n1)Insert\n2)Display\n3)Find Size\n4)Exit\nINPUT: ";
        cin>>flag;
        switch (flag)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            int ctr;
            ctr = findSize();
            cout<<"Size is: "<<ctr<<endl;
            break;
        case 4:
            cout<<"Exiting...";
            break;
        default:
            break;
        }
    }
}