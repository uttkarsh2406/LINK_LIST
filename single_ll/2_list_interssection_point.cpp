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

int node_exac(link_list *a_head,link_list *b_head){

    link_list *a=a_head;
    link_list *b;

    while (a!=NULL  )
    {
        /* code */
         b=b_head;
        while (b!=NULL)
        {
            /* code */
            if(a->data == b->data){
                return a->data;
            }
            b=b->next;
        }
        a=a->next;
        
    }
    
    return -1;
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
   int c=node_exac(a,b);
   cout<<c<<endl;
   return 0;
    

}
