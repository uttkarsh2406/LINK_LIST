#include<iostream>
using namespace std;

class link{
    public:
    int data;
    link *next;
    
     
};
///////////////            INSERT NODE                ///////////////////////////////////////////////////////////////////////
link *c_node(int data){
    link *n_node= new link();
    n_node->data=data;
    n_node->next=NULL;

    return n_node;

}


/////////////////////   LENGTH OF LOOP   ////////////////////////////////////////////////////////////////////////////////////////////


int count_nodes(link *list){
    link *s_po=list,*f_po=list;
    while(s_po && f_po && f_po->next){
        s_po=s_po->next;
        f_po=f_po->next->next;
        if(s_po == f_po){
            int res=1;
            link *temp=s_po;
            while(temp->next!=s_po){
                res++;
                temp=temp->next;
            }
            return res;
        }
    }
    return 0;
}


void in_f(link **head,int data){
    
    link *node=c_node(data);
    node->next=*head;
    *head=node;

    
    
}

void in_l(link **head,int data){
    link *node=c_node(data),*temp=NULL;
    if(*head==NULL){
        *head=node;
        return;
    }
    temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;

}

void at_p(link **head,int data,int position){
    link *node=c_node(data),*curr=NULL,*pre=NULL;
    curr=*head;
    
    for (int i = 0; i < position-2; i++)
    {
        curr=curr->next;

    }
    node->next=curr->next;
    curr->next=node;
    
}

void af_n(link **head,int data,int key){
    link *node=c_node(data),*temp=NULL;

    temp=*head;
    while (temp->data!=key)
    {
        temp=temp->next;
    }

    node->next=temp->next;
    temp->next=node;
    
}

///////////////            INSERT NODE FINISH               ///////////////////////////////////////////////////////////////////////

///////////////            DELETE NODE                ///////////////////////////////////////////////////////////////////////


void del_f(link **head){
    link *temp=*head;
    *head=temp->next;
    delete temp;
}

void del_l(link **head){
    link *temp,*pre=NULL;
    temp=*head;
    while (temp->next!=NULL)
    {
        /* code */
        pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    delete temp;
}

void del_n(link **head,int key){
    link *temp,*pre;
    temp=*head;
    while (temp->next->data!=key)
    {
        temp=temp->next;
    }
    pre=temp->next;
    temp->next=temp->next->next;
    delete pre;
    
}

void del_pos(link **head,int pos){
      link *temp=*head,*pre=NULL;

      for (int i = 0; i < pos-1; i++)
      {
          /* code */
          pre=temp;
          temp=temp->next;

      }
      pre->next=temp->next;
      delete temp;
}




///////////////            DELETE NODE  END              ///////////////////////////////////////////////////////////////////////

///////////////            SWAP NODE                ///////////////////////////////////////////////////////////////////////

void node_swap(link **head,int a,int b){
    if(a==b){
        return;
    }

    link *a_back=NULL,*a_cur=*head;
    while(a_cur && a_cur->data != a){
        a_back=a_cur;
        a_cur=a_cur->next;
    }

    link *b_back=NULL,*b_cur=*head;
    while(b_cur && b_cur->data!=b){
        b_back=b_cur;
        b_cur=b_cur->next;
    }

    if(a_cur == NULL || b_cur == NULL){
        return;
    }
    if(a_back != NULL){
       a_back->next=b_cur;
    }
    else{
        *head=b_cur;
    }
    if(b_back!=NULL){
        b_back->next=a_cur;
    }
    else{
        *head=a_cur;
    }

    link *temp=b_cur->next;
    b_cur->next=a_cur->next;
    a_cur->next=temp;


}
///////////////            SWAP NODE  END              ///////////////////////////////////////////////////////////////////////



///////////////            REVERSE LIST                ///////////////////////////////////////////////////////////////////////


void reverse(link **head){
    link *cur=*head,*pre=NULL,*next=NULL;

    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }

    *head=pre;
}

///////////////            REVERSE LIST  END              ///////////////////////////////////////////////////////////////////////



///////////////            search             ////////////////////////////////////////////////////////////////////////////////


int search(link *head,int key){
      link *temp=head;
      while(temp!=NULL)
      {
          if(temp->data==key){
              return 1;
          }
          temp=temp->next;
      }
      return 0;
                      

}
//////////////////            search END             ////////////////////////////////////////////////////////////////////////////////

//////////////            GETTING Nth NODE             ////////////////////////////////////////////////////////////////////////////////


link *n_node(link *head,int pos){
    link *temp=head;
    for (int i = 0; i < pos; i++)
    {
        temp=temp->next;
    }
    return temp;
    

}



//////////////            GETTING Nth NODE    END         ////////////////////////////////////////////////////////////////////////////////


//////////////            GETTING MIDDLE NODE           ////////////////////////////////////////////////////////////////////////////////
link *middle(link *head){
    link *sl_temp=head,*fs_temp=head;
    while(fs_temp->next!=NULL){
        fs_temp=fs_temp->next->next;
        sl_temp=sl_temp->next;
    }
     
     return sl_temp;
     
}

//////////////            GETTING MIDDLE  NODE END           ////////////////////////////////////////////////////////////////////////////////


//////////////            Total Ocurrancee of NODE           ////////////////////////////////////////////////////////////////////////////////

int ocu_node(link *head,int key){
    link *tmep=head;
    int count=0;
    while(tmep!=NULL){
        if(tmep->data==key)
        count++;

        tmep=tmep->next;
    }

    return count;
}
void print_list(link *head){
    
    link *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    
}

void print_list_len(link *head){
    int count=0;
    link *temp=head;
    while (temp!=NULL)
    {
        
        temp=temp->next;
        count++;
    }
    cout<<count<<endl;
    
}


int main(){
    link *head =NULL;
    char ch;
    int data,pos;

    cin>>ch;
    while (ch!='e')
    {   if(ch=='f'){
        cin>>data;
        in_f(&head,data);
    }
    if(ch=='l'){
        cin>>data;
        in_l(&head,data);
    }
    if(ch=='i'){
        cin>>data;
        cin>>pos;
        at_p(&head,data,pos);
        
    }
    if(ch=='a'){
        cin>>data;
        cin>>pos;
        af_n(&head,data,pos);
    }
    if(ch=='d'){
        del_f(&head);
    }
    if(ch=='t'){
        del_l(&head);
    }
    if(ch=='z'){
        cin>>data;
        del_n(&head,data);

    }
    if(ch=='s'){
        cin>>pos;
        del_pos(&head,pos);
    }
    if(ch=='p'){
        print_list(head);
        cout<<endl;
    }
    if(ch=='c'){
        print_list_len(head);
    }
    if(ch=='u'){
        int a,b;
        cin>>a>>b;
        node_swap(&head,a,b);
    }
    if(ch=='b'){
        reverse(&head);
    }
    if(ch=='o'){
        cin>>data;
        if(search(head,data)){
            cout<<"Present"<<endl;

        }
        else{
            cout<<"Not Present"<<endl;
        }
    }
    if(ch=='x'){
        cin>>pos;
        cout<<n_node(head,pos)->data<<endl;
    }
    if(ch=='m'){
        cout<<middle(head)->data<<endl;
    }
    if(ch=='y'){
        cin>>data;
        cout<<ocu_node(head,data)<<endl;
    }
    if(ch=='g'){
        cout<<count_nodes(head)<<endl;
    }

     cin>>ch;  
  }

  

}