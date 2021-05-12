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

node *last_node(node *head){
    while(head && head ->next !=NULL){
        head=head->next;
    }
    return head;
}



node *partition(node *head,node *tail){
    int x=tail->data;
    node *temp=head->prev;
    for (node * i = head; i !=tail; i=i->next)
    {
        /* code */
        if(i->data<=x){
            temp=(temp==NULL)?head:temp->next;

            swap(temp->data , i->data);
        }

    }
    temp=(temp==NULL)?head:temp->next;
    swap(temp->data,tail->data);
    return temp;
    

}

void quick_sort_rec(node *head,node *tail){
    if(tail!=NULL && head !=tail && head !=tail->next){
        node *part=partition(head,tail);;
        
        quick_sort_rec(head,part->prev);
        quick_sort_rec(part->next,tail);


    }
}



void q_sort(node *head){
    node *tail=last_node(head);
    quick_sort_rec(head,tail);
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
    q_sort(head);
    print_list(head);

}