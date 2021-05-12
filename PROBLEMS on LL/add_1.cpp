// { Driver Code Starts
//Initial template for C++

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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{   
    public:
    Node *reverse(Node *head){
       Node *pre=NULL,*next,*curr=head;
         while(curr!=NULL){
             next=curr->next;
             curr->next=pre;
             pre=curr;
             curr=next;
             
             
         }
         return pre;
    }

    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
         head=reverse(head);
         Node *curr=head;
         int flag=1;
         while (flag)
         {
             /* code */
             curr->data+=1;
             if(curr->data<10){
                 return reverse(head);
             }
             else curr->data=0;

             if(curr->next==NULL){
                 break;
             }
             else 
             curr=curr->next;
         }
        
        curr->next=new Node(1);
        return reverse(head);
         

                 
         
            
             
         
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends