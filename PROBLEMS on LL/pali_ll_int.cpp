// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.

    Node *rev(Node *head){
        Node *pre=NULL,*curr=head,*next;
        while (curr)
        {
            /* code */
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
        
    }
    bool id(Node *n1,Node *n2){
      for ( ;n1 && n2; n1=n1->next,n2=n2->next)
      {
        /* code */
        if(n1->data=n2->data)
        return 0;
      }
      return 1;
      
    }

    bool isPalindrome(Node *head)
    {
        //Your code here
        int size=0;
        Node *temp=head;
        while (temp)
        {
          /* code */
          size++;
          temp=temp->next;
        }
        if(size<2){
          return 1;
        }
        temp=head;
        int mid=(size-1)/2;
        while (mid--)
        {
          temp=temp->next;
        }
        Node *head2=temp->next;
        temp->next=NULL;

        head2=rev(head2);

        bool tr=id(head,head2);
        head2=rev(head2);
        temp->next=head2;

        return tr;
        

        
         
        
        
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends