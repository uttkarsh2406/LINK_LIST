#include<iostream>
using namespace std;

class link_list
{
private:
    /* data */
public:
   int data;
   link_list *next;
};


void insert(link_list **list,int value){
   link_list *node=new link_list();
   node->data=value;
   node->next=*list;
   *list=node;
}

link_list *node_exac(link_list *a_head,link_list *b_head){

    link_list dum;
    link_list *last;
    last=&dum;
    dum.next=NULL;
    while (a_head!=NULL && b_head!=NULL)
    {
        if(a_head->data == b_head->data){
            insert(&last->next,a_head->data);
        
        a_head=a_head->next;
        b_head=b_head->next;
        }
        else if(a_head->data < b_head->data){
             a_head=a_head->next;
         }
         else{
             b_head=b_head->next;
         }

    }
    
    
    return dum.next;
    
}


void p_list(link_list *head){
    link_list *temp;
    temp=head;
    while (temp!=NULL)
    {
        /* code */
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

int main(){
    link_list *a=NULL,*b=NULL,*inter=NULL;
    int k;
    char t;
    cin>>t;
    while (t!='e')
    {
        /* code */
        if(t=='i'){
            cin>>k;
            insert(&a,k);
        }
        if(t=='u'){
            cin>>k;
            insert(&b,k);
        }
        cin>>t;
    }
    inter=node_exac(a,b);
    p_list(inter);
    

}
