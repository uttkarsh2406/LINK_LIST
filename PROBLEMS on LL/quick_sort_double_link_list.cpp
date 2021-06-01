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



void print_list(node *head){
    node *he=head;
    do{
        cout<<he->data<<" ";
        he=he->next;
    }while(he!=NULL);

}    

node *get_last(node *head){
    while (head && head->next!=NULL)
    {

        /* code */
        head=head->next;
    }
    return head;
    
}
node *partiton(node *head,node *last){
    int x=last->data;
    node *j=head->prev;

    for (node *i = head; i !=last;i=i->next)
    {
        /* code */
        if(i->data<=x){
            j=(j==NULL)?head:j->next; 
            swap(i->data,j->data);

        }
    }
    j=(j==NULL)?head:j->next;
    swap(j->data,last->data);
    return j;
    
}

void quick_rec(node *head,node *last){
    if(last!=NULL && head!=last && head!=last->next){
        node *p=partiton(head,last);
        quick_rec(head,p->prev);
        quick_rec(p->next,last);
    }
}


void quick_sort(node *head){
    quick_rec(head,get_last(head));
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
        if(t=='p'){
            print_list(head);
        }
        if(t=='s'){
            quick_sort(head);
        }

        
        cin>>t;


    }
    print_list(head);

}