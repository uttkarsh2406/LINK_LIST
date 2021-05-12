#include<iostream>
using namespace std;

class node
{
private:
    /* data */
public:
   int data;
   node  *next;
};


void insert(node **head,int data){
    node *n_node=new node();
    n_node->data=data;
    node *temp=*head;
    if(temp==NULL){
        n_node->next=n_node;
        *head=n_node;
        return;
    }
    
    
   else if(data<(*head)->data){
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=n_node;
        n_node->next=*head;
        *head=n_node;
        return;
        
    }
    else{
        while(temp->next != *head && temp->next->data<data){
        
        temp=temp->next;


    }
    n_node->next=temp->next;
    temp->next=n_node;
    return;
    }
    


}

void print_list(node *head){
    node *temp=head;

    if(temp!=NULL){
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
}

int main(){
    node *head=NULL;
    char c;

    cin>>c;
    while(c!='e'){
        if(c=='i'){
            int k;
            cin>>k;
            insert(&head,k);
        }
        cin>>c;
    }

    print_list(head);
    return 0;

    
}
