#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next,*prev;
};


void insert_at_front(node **head,int data){
    node *no=new node();
    no->data=data;
    no->next=*head;
    no->prev=NULL;
    if((*head)!=NULL){
        (*head)->prev=no;

    }
    *head=no;
    
}

void insert_at_end(node **head,int data){
    node *no=new node();
    no->data=data;
    no->next=NULL;
    node *last=*head;
    if((*head)==NULL){
        no->prev=NULL;
        *head=no;
        return;
    }
    while(last->next!=NULL){
       last=last->next;
    }
    last->next=no;
    no->prev=last;
}

void insert_after(node **head,int key,int data){
     if((*head)==NULL){
         return;
     }
     node *no=new node();
     no->data=data;
     node *temp=*head,*pre=NULL;
     while(temp->data != key){
         
         temp=temp->next;
     }
     no->next=temp->next;
     temp->next=no;
     no->next->prev=no;
     no->prev=temp;
     
}


void print_list(node *head){
    node *he=head;
    do{
        cout<<he->data<<" ";
        he=he->next;
    }while(he!=NULL);

}

void del_from_front(node **head){
    node *temp=*head;
    *head=(*head)->next;
    delete temp;
}

void del_at_end(node **head){
    node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    delete temp;
}


void del_after_given_node(node **head,int key){
    node *temp=*head;
    while(temp->data != key){
        temp=temp->next;

    }
    node *pre=temp->prev;
    pre->next=temp->next;
    temp->next->prev=pre;

    delete temp;

}


void reverse(node **head){
    node *temp=NULL;
    node *curr=*head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL){
        *head=temp->prev;
    }
}

int main(){
    node *head=NULL;
    char t;
    int k;
    cin>>t;
    while(t!='e'){
        if(t=='i'){
            cin>>k;
            insert_at_front(&head,k);
        }
        if(t=='o'){
            cin>>k;
            insert_at_end(&head,k);
        }
        if(t=='p'){
            int data;
            cin>>k>>data;
            insert_after(&head,k,data);
        }
        if(t=='d'){
            del_from_front(&head);
        }
        if(t=='w'){
            del_at_end(&head);
        }
        if(t=='r'){
            cin>>k;
            del_after_given_node(&head,k);
        }
        cin>>t;


    }
    print_list(head);

}