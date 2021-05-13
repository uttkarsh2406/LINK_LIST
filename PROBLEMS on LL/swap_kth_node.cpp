// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(!head){
        return NULL;
    }
    if(K>num){
        return head;
    }
    Node *last_pre=NULL,*las=head;
    Node *curr=head;
    
    int i=num-K;
    while (i--){
        last_pre=las;
        las=las->next;
    }
    i=K-1;
    Node *fro_pre=NULL,*fro=head;

    while (i--)
    {
        /* code */
        fro_pre=fro;
        fro=fro->next;

    }
    if(fro_pre!=NULL){
        fro_pre->next=las;
    }
    else{
        head=las;
    }
    if(last_pre!=NULL){
        last_pre->next=fro;
    }
    else{
        head=fro;
    }
    Node *temp=las->next;
    las->next=fro->next;
    fro->next=temp;

    return head;
    
    





}
