#include<bits/stdc++.h>
using namespace std;

class node{

public:
    int data;
    node* lchild=nullptr;
    node* rchild=nullptr;

    node(int data){
        this->data = data;

    }
};

node* test_input(){
    node* root = new node(30);
    root->lchild = new node(20);
    root->rchild = new node(40);
    root->lchild->lchild = new node(10);
    root->lchild->rchild = new node(25);
    root->rchild->lchild = new node(35);
    root->rchild->rchild = new node(50);
    return root;
}
node* rsearch_bst(node* root, int data){

    if(root==nullptr || root->data == data){
        return root;
    }
    if(root->data>data){
        return rsearch_bst(root->lchild, data);
    }
    return rsearch_bst(root->rchild, data);
}
node* isearch_bst(node* root, int data){

    if(root==nullptr){
        return nullptr;
    }
    while(root!=nullptr){
        if(root->data>data){
            root = root->lchild;
        }else if(root->data<data){
            root = root->rchild;
        }else{
            return root;
        }
    }
    return root;

}
node* rinsert_bst(node* root, int data){

    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }
    if(root->data>data){
        root->lchild = rinsert_bst(root->lchild, data);
        return root;
    }
    root->rchild = rinsert_bst(root->rchild, data);
    return root;
}
node* iinsert_bst(node* root, int data){

    // base case, make a node and return its pointer
    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }

    node* temp = root;
    // traverse in the tree to find a location until both lchild and rchild are not null
    while(temp->lchild!=nullptr && temp->rchild!=nullptr){
        if(temp->data>data){
            temp = temp->lchild;
        }else if(temp->data<data){
            temp = temp->rchild;
        }
    }
    // if only lchild exists, and rchild is null, it means we have to insert in the right side of temp
    if(temp->lchild && temp->rchild==nullptr){
        node* temp2 = new node(data);
        temp->rchild = temp2;
        return root;
    }
    // if only rchild exists, and lchild is null, it means we have to insert in the left side of temp
    if(temp->rchild && temp->lchild==nullptr){
        node* temp2 = new node(data);
        temp->lchild = temp2;
        return root;
    }
    // if both are null, check with temp's data, whether to insert left or right
    if(temp->lchild==nullptr && temp->rchild==nullptr){
        if(temp->data>data){
            temp->lchild = new node(data);
        }else{
            temp->rchild = new node(data);
        }
    }
    return root;

}
void inOrder(node* root){

    if(root==nullptr)
        return;
    inOrder(root->lchild);
    cout<<root->data<<" ";
    inOrder(root->rchild);
}
void preOrder(node* root){
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}


node* constructUtil(int* preOrder, int n, int mini, int maxi){

    static int preIndex = 0;
    if(preIndex>n)
        return nullptr;

    node* root = nullptr;
    if(preOrder[preIndex]>mini && preOrder[preIndex]<maxi){
        root = new node(preOrder[preIndex]);
        preIndex++;
        if(preIndex<=n){

        root->lchild = constructUtil(preOrder, n, mini, preOrder[preIndex-1]);
        root->rchild = constructUtil(preOrder, n, preOrder[preIndex-1], maxi);

        }
    }

    return root;

}
node* construct(int* preOrder, int n){ // n is the last index of preOrder array
    return constructUtil(preOrder, n, INT_MIN, INT_MAX);
}
int main(){

//    node* root = test_input();
//    node* temp = isearch_bst(root, 30);

//    node* root = new node(30);
//    root = iinsert_bst(root, 20);
//    root = iinsert_bst(root, 40);
//    root = iinsert_bst(root, 10);
//    root = iinsert_bst(root, 25);
//    root = iinsert_bst(root, 35);
//    root = iinsert_bst(root, 50);

    int preOrder[] = {30, 20, 10, 25, 40, 35, 50};
    node* root = construct(preOrder, (sizeof(preOrder)/sizeof(preOrder[0]))-1);
    inOrder(root);


return 0;
}
