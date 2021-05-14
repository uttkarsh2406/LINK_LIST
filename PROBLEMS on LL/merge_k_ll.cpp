// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node *s_m(Node *n,Node *m){
        Node *r=NULL;
        if(n==NULL){
            return m;
        }
        else if(m==NULL){
            return n;
        }
        if(n->data <= m->data){
            r=n;
            r->next=s_m(n->next,m);

        }
        else{
            r=m;
            r->next=s_m(n,m->next);
        }
        return r;

    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           int n=K;
           int l=K-1;
           while (l!=0)
           {
               /* code */
               int j=0,i=l;
               while (i>j)
               {
                   /* code */
                   arr[j]=s_m(arr[j],arr[i]);
                   j++,i--;
                   if(j>=i){
                       l=i;
                   }

               }
               
           }
           return arr[0];

    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends