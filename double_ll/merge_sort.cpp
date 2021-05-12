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

node *split(node *head){
    node *slo=head;
    node *fas=head;
    while(fas->next && fas->next->next){
       slo=slo->next;
       fas=fas->next->next;
    }
    node *mid=slo->next;
    slo->next=NULL;
    return mid;

}


node *merge(node *fis,node *sec){
    if(!fis){
        return sec;
    }
    if(!sec){
        return fis;
    }
    if(fis->data<sec->data){
        fis->next=merge(fis->next,sec);
        fis->next->prev=fis;
        fis->prev=NULL;
        return fis;
    }
    else{
        sec->next=merge(fis,sec->next);
        sec->next->prev=sec;
        sec->prev=NULL;
        return sec;
    }
}

node *merge_sort(node *head){
    if(!head || !head->next){
        return head;
    }
    node *second=split(head);
    head=merge_sort(head);
    second=merge_sort(second);

   
   return merge(head,second);


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
    head=merge_sort(head);
    print_list(head);

}