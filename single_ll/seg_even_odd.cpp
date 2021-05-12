#include<iostream>
#include<stdio.h>
using namespace std;
class list{
    public:
    int data;
    list *next;
};


list *c_node(int data){
    list *n_node=(list*)malloc(sizeof(list));
    n_node->data=data;
    n_node->next=NULL;
    return n_node;
}


void insert(list **head,int data){
    list *d_node=c_node(data);
    d_node->next=*head;
    *head=d_node;
    
}


void even_odd(list **head){
    list *end=*head;
    list *pre=NULL;
    list *curr=*head;

    while(end->next!=NULL){
        end=end->next;
    }
    list *ne_end=end;

    while(curr->data%2!=0 && curr!=NULL ){
        ne_end->next=curr;
        curr=curr->next;
        ne_end->next->next=NULL;
        ne_end=ne_end->next;

    }

    if(curr->data%2==0){
        *head=curr;

        while(curr!=end){
            if(curr->data%2==0){
                pre=curr;
                curr=curr->next;
            }
            else{
                pre->next=curr->next;
                curr->next=NULL;
                ne_end->next=curr;
                ne_end=curr;
                curr=pre->next;


                

            }
        }
    }
    else{
        pre=curr;
    }
    if(ne_end!=end && end->data%2!=0){
        pre->next=end->next;
        end->next=NULL;
        ne_end->next=end;
    }
    return;

}

void p_list(list *n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main(){
    struct list *head=NULL;

    char t;
    cin>>t;
    while (t!='e')
    {
        if(t=='i'){
            int a;
            cin>>a;
           insert(&head,a);
        }

        cin>>t;

    }
    even_odd(&head);

    p_list(head);

    
}
