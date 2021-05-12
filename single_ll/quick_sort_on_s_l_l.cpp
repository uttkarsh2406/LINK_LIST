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


link_list *partiton(link_list *head,link_list *end,link_list **n_head,link_list **n_end){
    link_list *pivot=end;
    link_list *pre=NULL;
    link_list *cur=head;
    link_list *tail=pivot;

    while(cur!=pivot){
        if(cur->data<pivot->data){
            if(*n_head == NULL){
                *n_head=cur;
            }
            pre=cur;
            cur=cur->next;
        }
        else{
            if(pre)
            pre->next=cur->next;
            
            link_list *temp=cur->next;
            cur->next=NULL;
            tail->next=cur;
            tail=cur;
            cur=temp;
        }
    }

    if(*n_head==NULL){
        *n_head=pivot;
    }
    *n_end=tail;

    return pivot;

}
link_list *find_tail(link_list *head){
    link_list *temp=head;
    while(temp!=NULL && temp->next !=NULL){
        temp=temp->next;

    }
    return temp;
}

link_list *qsort_rec(link_list *head,link_list *end){
   if(!head || head==end){
       return head;
   }
   link_list *n_head=NULL,*n_end=NULL;

   link_list *pivot;
   pivot=partiton(head,end,&n_head,&n_end);

   if(n_head!=pivot){
       link_list *temp=n_head;
       while(temp->next!=pivot){
           temp=temp->next;
       }
       temp->next=NULL;

       n_head=qsort_rec(n_head,temp);

       temp=find_tail(n_head);
       temp->next=pivot;
   }
      pivot->next=qsort_rec(pivot->next,n_end);

   return n_head;


}



void quick_sort(link_list **head){
    link_list *tail=find_tail(*head);
    *head=qsort_rec(*head,tail);

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
    link_list *a=NULL;
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
        
        cin>>t;
    }
   quick_sort(&a);
   p_list(a);
   return 0;
    

}
