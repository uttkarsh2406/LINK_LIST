// { Driver Code Starts
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

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


 // } Driver Code Ends
/*
Structure of the node of the linked list is as
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
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here  (((((( Two Unoptimized solution))))))
        /*int pairs=0;
        struct Node *temp=head2;
        while(head1!=NULL){
            temp=head2;
            while(temp!=NULL){
                if(temp->data+head1->data==x){
                    pairs++;

                }
                temp=temp->next;

            }
         head1=head1->next;
            
        }
         return pairs; */


      /*  int pair=0;
       while(head1!=NULL){
           int y=x-head1->data;
           struct Node *temp=head2;
           while(temp!=NULL){
               if(y==temp->data){
                   pair++;
               }
               temp=temp->next;

           }
           head1=head1->next;
 
       }

     return pair; */
        

        int pair=0;
        unordered_set<int> my;
        while(head1!=NULL){
            my.insert(head1->data);
            head1=head1->next;

        }

        while(head2!=NULL){
            if(my.find(x-head2->data)!=my.end()){
                pair++;
            }
            head2=head2->next;
        }

       return pair;

    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}  // } Driver Code Ends