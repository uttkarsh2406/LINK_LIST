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

void node_exac(link_list **head){
link_list *tmep=NULL;
    link_list *node=*head;
    while (node->next!=NULL)
    {
        /* code */
        tmep=node;
        node=node->next;

    }
    tmep->next=NULL;
    node->next=*head;
    *head=node;
    
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
    link_list *list=NULL;
    int k;
    char t;
    cin>>t;
    while (t!='e')
    {
        /* code */
        if(t=='i'){
            cin>>k;
            insert(&list,k);
        }
        cin>>t;
    }
    node_exac(&list);
    p_list(list);
    

}
