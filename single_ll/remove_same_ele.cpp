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


void remove_dub(list *head){
    list *x,*c,*v;
    x=head;
    

    while(x!=NULL && x->next!=NULL){
    c=x;
    while(c->next!=NULL){
        if(x->data==c->next->data){
            v=c->next;
            c->next=c->next->next;
            free(v);
        }
        else{
            c=c->next;
        }
        
    }
x=x->next;
    }


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
    remove_dub(head);

    p_list(head);

    
}
