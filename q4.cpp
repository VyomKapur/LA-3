#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* start = NULL;
struct node* tail = NULL;

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
    tail = new_node;
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
bool checkPalindrome(){
    bool found = false;
    node* backptr = tail;
    node* frontptr = start;
    while(backptr!=frontptr){
        if(backptr->data==frontptr->data){
            found = true;
            backptr = backptr->prev;
            frontptr = frontptr->next;
        }
        else{
            found = false;
            break;
        }
    }
    return found;
}
int main(){
    int flag = 0;
    while(flag!=4){
        cout<<"--MENU--\n1)Insert\n2)Display\n3)Check Palindrome\n4)Exit\nINPUT: ";
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
            bool check;
            check = checkPalindrome();
            cout<<"Is given linked list a palindrome: "<<check<<endl;
            break;
        case 4:
            cout<<"Exiting...";
            break;
        default:
            cout<<"Enter a valid input!"<<endl;
            break;
        }
    }
}