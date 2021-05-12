// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node* modifyTheList(struct Node *head);

void push(struct Node **head_ref, int new_data)
{
  struct Node* new_node = new Node(new_data);
  new_node->next = *head_ref;    
  *head_ref = new_node;
}

void printList(struct Node *head)
{
    if (!head)
        return;
   	while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL;
		while(n--){
			int a;
			cin>>a;
			push(&head, a);
		}
		head = modifyTheList(head);
		printList(head);
	}
    return 0;
}

// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
struct Node* modifyTheList(struct Node *head)
{
    //add code here.
    if(head->next==NULL){
        return head;
    }
    struct Node *curr=head;
    int a[100];
    int count=0;
    while (curr!=NULL)
    {   a[count]=curr->data;
        count++;
        curr=curr->next;
    }
    curr=head;
    if(count%2!=0){
    int x=count/2+1;
    int i=0;
    while (curr!=NULL)
    {
        curr->data=a[i]-a[count-1];
        count--;
        curr=curr->next;
        if(count==x){
            break;
        }
        i++;
        
    }
    }
    else {
    int x=count/2;
    int i=0;
    while (curr!=NULL)
    {
        curr->data=a[i]-a[count-1];
        count--;
        curr=curr->next;
        if(count==x){
            break;
        }
        i++;
        
    }
    }

    return head;
    
    
    
    
}