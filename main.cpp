#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>
using namespace std;

typedef char EType;
typedef struct tnode  {   EType data;   struct tnode* left;   struct tnode* right; }TNode;
typedef struct tnode* BTREE;

void inorder(BTREE T);
void preorder(BTREE T);
void postorder(BTREE T);
void show_node(BTREE T);
void split_exp(string s,string *a,string *b,char * c);

TNode* put_in_tree(BTREE T,string s);

int main(){

    cout<<"Enter the exp"<<endl;
    string x;
    // input inorder only
    cin>>x;
    cout<<endl;
    BTREE T;
    T=NULL;
    T=put_in_tree(T,x);
    cout<<"inorder = ";
    inorder( T);
    cout<<endl;
    cout<<"preorder = ";
    preorder(T);
    cout<<endl;
    cout<<"postorder = ";
    postorder(T);
    return 0;
}


///////////////////////////////////////////////////////
TNode* put_in_tree(BTREE T,string s){

    string a;string b;char c;
    split_exp(s,&a,&b,&c);
    TNode *tmp = (TNode*) malloc(sizeof(TNode));
    tmp->right=tmp->left=NULL;

    if(T==NULL){
     tmp->data=c;
     T=tmp;
    }

    if(a.size()==1){
         tmp->left = (TNode*) malloc(sizeof(TNode));
         tmp->left->data=a[0];
         tmp->left->right=tmp->left->left=NULL;

    }

    if(b.size()==1){
         tmp->right = (TNode*) malloc(sizeof(TNode));
         tmp->right->data=b[0];
         tmp->right->right=tmp->right->left=NULL;
    }

    if(a.size()!=1){

        T->left=put_in_tree(T->left,a);
    }

    if(b.size()!=1){

        T->right=put_in_tree(T->right,b);

    }

    if(a.size()==1&&b.size()==1){
        return T;
    }

    return T;



}







void split_exp(string s,string *a,string *b,char *c){
    *a = ""; *b="";

    for(int i =s.size()-1;i>0;i--){

        if(s[i]=='+'||s[i]=='-'){
           for(int j =0;j<i;j++){
                                *a=*a+s[j];
                                 }
        *c=s[i];
        break;
           }
            *b=*b+s[i];

    }

    if((*a).size()==0){

        for(int i =s.size()-1;i>0;i--){
            if(s[i]=='*'||s[i]=='/'){

                for(int j =0;j<i;j++){
                *a=*a+s[j];
                }
                *c=s[i];
                break;
            }

            *b="";
            *b=*b+s[i];
        }


    }
    string d="";
    int i =((*b).size()-1);
    for(;i>=0;i--){

        d=d+(*b)[i];

    }
    *b=d;
}
void preorder(BTREE T){
    if (T != NULL){
    show_node(T);
    preorder(T->left);
    preorder(T->right);
    }
}

void postorder(BTREE T){
    if (T != NULL){
    postorder(T->left);
    postorder(T->right);
    show_node(T);
    }
}

void inorder(BTREE T){
    if (T != NULL){
    inorder(T->left);
    show_node(T);
    inorder(T->right);
    }
}

void show_node(BTREE T){
    cout<<T->data;
}
