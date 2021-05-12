#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next,*prev;
};




int count_no(node *head){
    node *p=head;
    int n=0;
    while(p!=NULL){
        p=p->next;
        n++;
    }
    return n;
}


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


void swap_kth_node(node **head,int k){
    int n=count_no(*head);
    if(n<k){
        return;
    }
    if(2*k-1==n){
        return;
    }
    node *p=*head;
    node *pre=NULL;
    for (int i = 1; i < k; i++)
    {
        /* code */
        pre=p;
        p=p->next;

    }
    node *y=*head;
    node *y_pre=NULL;
    for (int i = 1; i < n-k+1; i++)
    {
        /* code */
        y_pre=y;
        y=y->next;
    }
    
    if(pre){
        pre->next=y;
    }
    if(y_pre){
        y_pre->next=p;
    }
    node *temp=p->next;
    p->next=y->next;
    y->next=temp;

    if(k==1){
        *head=y;
    }
    if(k==n){
        *head=p;
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
        
        cin>>t;


    }
    int pos;
    cin>>pos;
    swap_kth_node(&head,pos);
    

     print_list(head);

}