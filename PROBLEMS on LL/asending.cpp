#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}
// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
void rev(Node **head){
	Node *prev=NULL,*nex=NULL,*curr=*head;
	while (curr)
	{
		/* code */
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;

	}
     *head=prev;	
	

}

Node *merge(Node *head1,Node *head2){
	if(!head1){
		return head2;
	}
	if(!head2){
		return head1;
	}
	Node *temp_node=NULL;

	if(head1->data<head2->data){
		temp_node=head1;
        head1->next=merge(head1->next,head2);
	}
	else{
		temp_node=head2;
		head2->next=merge(head1,head2->next);
	}
	return temp_node;
}

void split_list(Node *head,Node **ahead,Node **dhead){
	*ahead=new Node(0);
	*dhead=new Node(0);

	Node *ascn=*ahead;
	Node *dscn=*dhead;
	Node *curr=head;

	while (curr)
	{
		/* code */
		ascn->next=curr;
		ascn=ascn->next;
		curr=curr->next;

		if(curr){
			dscn->next=curr;
			dscn=dscn->next;
			curr=curr->next;
		}
	}
	ascn->next=NULL;
	dscn->next=NULL;
	*ahead=(*ahead)->next;
	*dhead=(*dhead)->next;
	
}

void sort(Node **head)
{
     // Code here
	 Node *ahead,*dhead;
	 split_list(*head,&ahead,&dhead);
	 rev(&dhead);
	 *head=merge(ahead,dhead);



    
}