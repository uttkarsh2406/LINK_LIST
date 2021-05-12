// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
struct node *get_las(struct node *head){
    while(head->next!=NULL){
        head=head->next;

    }
    return head;
}

struct node *part(struct node *head,struct node *taill,struct node **ne_head,struct node **ne_end){
    struct node *pivot=taill,*prev=NULL,*curr=head,*tail=pivot;

    while (curr!=pivot)
    {
        /* code */
        if(curr->data<pivot->data){
            if((*ne_head)==NULL){
                *ne_head=curr;
            }
            prev=curr;
            curr=curr->next;
        }
        else{
            if(prev){
                prev->next=curr->next;
            }
                struct node *temp=curr->next;
                curr->next=NULL;
                tail->next=curr;
                tail=curr;
                curr=temp;
            
        }
        
    }
    if((*ne_head)==NULL){
        *ne_head=pivot;
    }
    *ne_end=tail;
    return pivot;

}

struct node *quickrec(struct node *head,struct node *tail ){
    if(!head|| head==tail){
        return head;
    }
    struct node *ne_head=NULL,*ne_end=NULL;
    struct node *pivot;
    pivot=part(head,tail,&ne_head,&ne_end);

    if(ne_head!=pivot){
        struct node *temp=ne_head;
        while (temp->next!=pivot)
        {
            /* code */
            temp=temp->next;   
        }
        temp->next=NULL;
        ne_head=quickrec(ne_head,temp);
        temp=get_las(ne_head);
        temp->next=pivot;

    }
    pivot->next=quickrec(pivot->next,ne_end);
    return ne_head;

}

void quickSort(struct node **headRef) {
   *headRef=quickrec(*headRef,get_las(*headRef));
   return;
}