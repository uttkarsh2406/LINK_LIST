// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.


struct Node *merge(struct Node *first,struct Node *second){
    if(!first){
		return second;
	}
	if(!second){
		return first;
	}
	if(first->data<second->data){
		first->next=merge(first->next,second);
		first->next->prev=first;
		first->prev=NULL;
		return first;
		

	}
	else{
		second->next=merge(first,second->next);
		second->next->prev=second;
		second->prev=NULL;
		return second;
	}

}


struct Node *split(struct Node *head){
    struct Node *fas=head,*slo=head;
    while(fas->next && fas->next->next)
    {
        /* code */
        slo=slo->next;
		fas=fas->next->next;

    }
	struct Node *temp=slo->next;
	slo->next=NULL;
	return temp;
    
}




struct Node *sortDoubly(struct Node *head)
{
	// Your code here
    if(!head || !head->next){
        return head;
    }
    struct Node *second;
	second=split(head);
	head=sortDoubly(head);
	second=sortDoubly(second);
	return merge(head,second);
	

}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends