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
    node *temp=*head;
    n_node->data=data;
    n_node->next=*head;
    if(*head != NULL){
        while(temp->next != *head){
            temp=temp->next;
        }
        temp->next=n_node;
    }
    else{
       n_node->next=n_node;

    }
    *head=n_node;



}

void split(node *head,node **head_1,node **head_2){
    node *slo=head;
    node *fas=head;
    if(head==NULL){
        return;
    }
    while(fas->next!=head && fas->next->next!=head){
        slo=slo->next;
        fas=fas->next->next;
    }
    if(fas->next->next==head){
        fas=fas->next;
    }
    *head_1=head;
    if(head->next!=head){
        *head_2=slo->next;
    }
    fas->next=slo->next;

    slo->next=head;


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
    node *head_1=NULL;

    node *head_2=NULL;
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
    cout<<endl;
    split(head,&head_1,&head_2);
    print_list(head_1);
    cout<<endl;
    print_list(head_2);
    return 0;

    
}
