#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;

void insert(){
    struct node* new_node;
    node* ptr = start;
    new_node = new node;
    int data;
    cout<<"Enter data to be inserted: ";
    cin>>data;
    new_node->data = data;
    if(start==NULL){
        start = new_node;
        new_node->next = start;
    }
    else{
        while(ptr->next!=start){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
}
void display(){
    node* ptr = start;
    cout<<"START->";
    do{
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }while(ptr!=start);
}
int findSize(){
    int ctr=0;
    node* ptr = start;
    do
    {   
        ctr++;
        ptr = ptr->next;
    } while (ptr!= start);
    
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
            cout<<"Exiting..."<<endl;
            break;            
        default:
            cout<<"Enter a valid input!"<<endl;
            break;
        }
    }
}