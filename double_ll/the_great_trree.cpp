#include<iostream>
using namespace std;


class  bt{
    public:
        int data;
        bt *left;
        bt  *right;

 

};

bt *cr_node(int data){

    bt *node =new bt();
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}


bt *insert(bt *root,int data){
    if(root==NULL){
        return cr_node(data);
    }

    if(data<root->data){
        root->left=(insert(root->left,data));

    }
    if(data>root->data){
        root->right=insert(root->right,data);
    }

    return root;
}



bt *concatenate(bt *l_list,bt *r_list){
    if(l_list == NULL){
        return r_list;
    }
    if(r_list == NULL){
        return l_list;
    }
    bt *left_last=l_list->left;
    bt *right_last=r_list->left;

    left_last->right=r_list;
    r_list->left=left_last;

    right_last->right=l_list;
    l_list->left=right_last;

    return l_list;
}

bt *con(bt *root){
    if(root==NULL){
        return root;
    }
    bt *left=con(root->left);
    bt *right=con(root->right);
    root->right=root->left=root;

    return concatenate(concatenate(left,root),right);
}


void printf_l(bt *node){
    bt *temp=node;

    do
    {
        /* code */
        cout<<temp->data<<" ";
        temp=temp->right;
    } while (node!=temp);
    
}


int main(){
    bt *root=NULL;
    char t;
    cin>>t;

    while(t!='e'){
        if(t=='i'){
            int k;
            cin>>k;
            root=insert(root,k);
        }
        cin>>t;
    }
    bt *head=NULL;
    head=con(root);

    printf_l(head);



}