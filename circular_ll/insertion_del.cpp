#include<iostream>
using namespace std;


class node {
      public:
      int data;
      node *next;
};



void insert_in_empty(node **last,int data){
     node *temp=*last;
     if(temp!=NULL){
         return;
     }
    
    node *n_node=new node();
    n_node->data=data;
    *last=n_node;
    n_node->next=n_node;



}

void insert_at_biggning(node **last,int data){
    if((*last)==NULL){
       insert_in_empty(last,data);
       return;
    }
    
    node *n_node=new node();

    n_node->data=data;
    n_node->next=(*last)->next;
    (*last)->next=n_node;

}

void insert_at_end(node **last,int data){
    if((*last)==NULL){
        insert_in_empty(last,data);
        return;
    }

    node *no=new node();
    no->data=data;
    no->next=(*last)->next;
    (*last)->next=no;
    *last=no;
}


void transver(node *last){
    node *tmep;
    tmep=last->next;
    do
    {
        /* code */
        cout<<tmep->data<<" ";
        tmep=tmep->next;
    } while (tmep!=last->next);
    
}


void insert_in_btw(node **last,int key,int data){

    if((*last)==NULL){
        insert_in_empty(last,data);
        return;
    }
    node *no=new node();
    node *p;
    p=(*last)->next;
    do
    {
        /* code */
        if(p->data==key){
            no->data=data;
            no->next=p->next;
            p->next=no;
            if(p==*last){
                *last=no;
            }
        }
        p=p->next;
    } while (p!=(*last)->next);
    
    

}



void del(node **last,int data){
   if((*last)==NULL){
       return;
   }
   node *cur,*pre;
   cur=(*last)->next;
   while(cur->data!=data){
       pre=cur;
       cur=cur->next;
   }
   if(cur->next==cur){
       free(last);
   }
   else if(cur==(*last)->next){
       (*last)->next=(*last)->next->next;
   }
   else if(cur==(*last)){
        pre->next=(*last)->next;
        *last=pre;
   }
   else{
       pre->next=cur->next;

   }
   
}

int main(){
    node *last=NULL;

    char t;
    cin>>t;

    while(t!='e'){
        if(t=='i'){
            int k;
            cin>>k;
           insert_in_empty(&last,k);
        }
        if(t=='a'){
           int k;
           cin>>k;
           insert_at_biggning(&last,k);
        }

        if(t=='r'){
            int k;
            cin>>k;
            insert_at_end(&last,k);

        }
        if(t=='g'){
            int k;
            cin>>k;
            int data;
            cin>>data;
            insert_in_btw(&last,k,data);
        }
        if(t=='d'){
            int data;
            cin>>data;
            del(&last,data);
        }
        cin>>t;
    }
    transver(last);
}