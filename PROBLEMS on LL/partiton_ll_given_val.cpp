// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    struct Node *small=NULL,*lar=NULL,*equ=NULL,*curr=head,*small_last=NULL,*lar_last=NULL,*equ_last=NULL;

    while (curr!=NULL)
    {
        /* code */
        if(curr->data==x){
            if(equ==NULL){
                equ=equ_last=curr;
            }
            else{
                equ_last->next=curr;
                equ_last=equ_last->next;
            }
        }
        else if (curr->data>x)
        {
            /* code */
            if(lar==NULL){
                lar=lar_last=curr;
            }
            else{
                lar_last->next=curr;
                lar_last=lar_last->next;
            }
        }
        else{
            if(small==NULL){
                small=small_last=curr;
            }
            else{
                small_last->next=curr;
                small_last=small_last->next;
            }
        }
        curr=curr->next;
    }

    if(lar_last!=NULL){
        lar_last->next=NULL;
    }
    if(small==NULL){
        if(equ==NULL){
            return lar;
        }
        equ_last->next=lar;
        return equ;
    }
    
    if(equ==NULL){
        small_last->next=lar;
        return small;
    }
    small_last->next=equ;
    equ_last->next=lar;
    return small;



    
    
    
}