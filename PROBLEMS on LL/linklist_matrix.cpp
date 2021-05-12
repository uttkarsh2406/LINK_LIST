// { Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

void display(Node* head)
{
    Node* Rp;
	Node* Dp = head;
	while (Dp) {
		Rp = Dp;
		while (Rp) {
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		
		Dp = Dp->down;
	}
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
	    else display(head);
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends


/*structure of the node of the linked list is as

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]




Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    int i,j;
     Node* temp1=new Node(mat[0][0]);
     Node* head=temp1;
     Node* ptr=head;
     Node* ptr1=head;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             if(i!=0 || j!=0)
             {
                 Node* temp=new Node(mat[i][j]);
                 ptr->right=temp;
                 ptr=temp;
                if(i!=n-1)
                {
                    Node *temp2=new Node(mat[i+1][j]);
                    ptr1->down=temp2;
                    //ptr1=temp2;
                }
                if(i==n-1)
                {
                    ptr1->down=NULL;
                    
                }
             }
            
         }
          ptr->right=NULL;
     }
     return head;
     
}
