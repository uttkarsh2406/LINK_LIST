// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node *merge(Node *fis,Node *sec){
        if(!fis){
            return sec;
        }
        if(!sec){
            return fis;
        }

        if(fis->data<sec->data){
            fis->next=merge(fis->next,sec);
            return fis;
        }
        else{
            sec->next=merge(fis,sec->next);
            return sec;
        }

    }

    Node *split(Node *head){
        Node *slo=head,*fas=head;
        while (fas->next && fas->next->next)
        {
            /* code */
            slo=slo->next;
            fas=fas->next->next;
        }
        Node *temp=slo->next;
        slo->next=NULL;
        return temp;
        

    }
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next){
            return head;
        }
        Node *secnd=split(head);
        head=mergeSort(head);
        secnd=mergeSort(secnd);
       return merge(head,secnd);


    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends