#include<iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class Node{
       
    public:
        Node(int data){
            this->data=data;
            parent=NULL;
            left=NULL;
            right=NULL;
        }
        int data;
        Node *parent;
        Node *left;
        Node *right;

};
class BST{
    
    private:
        Node *root; 
    public:
        BST(){
            root=NULL;
        }
        Node *boolisEmpty(){
            return root=NULL;

        }
        Node *getTree(){
            return root;
        }
        Node *insertNode(int x){
            Node *y=NULL;
            Node *node=root;
            Node *iNode=new Node(x);
            while(node!=NULL){
                y=node;
                if(iNode->data<node->data){
                    node=node->left;
                }
                else{
                    node=node->right;
                }

            }
            iNode->parent=y;
            if(y==NULL){
                root=iNode;
            }
            else if(iNode->data<y->data){
                y->left=iNode;

            }
            else
                y->right=iNode;
            return node;


        }
        Node *findNode(int x){
            Node *node=root;
            while(node!=NULL){
                if(node->data==x){
                    return node;
                }
                else if(x<node->data)
                    node=node->left;
                else
                    node=node->right;
                    

            }
            
        }
        
        bool deleteNode(int x){
            Node* z = findNode(x);
            if(z != NULL){
                if(z->left == NULL){
                    Transplant(root,z,z->right);
                }
                else if(z->right == NULL){
                    Transplant(root,z,z->left);
                }
                else{
                    Node* y = tree_Minimum(z->right);
                    if(y->parent != z){
                        Transplant(root,y,y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    Transplant(root,z,y);
                    y->left = z->left;
                    y->left->parent = y;
                }
                return true;
            }
            else{
                return false;
            }
        }
        void Transplant(Node* root, Node* u, Node* v){
            if(u->parent == NULL){
                root = v;
            }
            else if(u == u->parent->left){
                u->parent->left = v;
            }
            else{
                u->parent->right = v;
            }
            if(v == NULL){
                v->parent = u->parent;
            }
        }
        Node *tree_Minimum(Node *x){
            while(x->left==NULL){
                x=x->left;

            }
            return x;
        }
        void inOrderTraversal(Node *T){
            if(T!=NULL){
                inOrderTraversal(T->left);
                cout<<T->data<<" ";
                inOrderTraversal(T->right);
            }
        }
        void preOrderTraversal(Node *T){
            if(T!=NULL){
                cout<<T->data<<" ";
                inOrderTraversal(T->left);
                inOrderTraversal(T->right);
            }
        }
        void postOrderTraversal(Node *T){
            if(T!=NULL){
                inOrderTraversal(T->left);
                inOrderTraversal(T->right);
                cout<<T->data<<" ";

            }
        }
        
        int Height(Node *T){
            if(T==NULL){
                return -1;
            }
            else{
                int left=Height(T->left);
                int right=Height(T->right);
                return max(left,right)+1;
            }
        }
        int NumberOfNodes(Node *T){
            if(T==NULL){
                return 0;
            }
            else{
                int left=Height(T->left);
                int right=Height(T->right);
                return left+right+1;
            }
        }
        bool isBSTinorder(Node *T,Node *pre){
            if(T!=NULL){
                if(T==NULL){
                    return true;
                }
                if(isBSTinorder(T->left,pre)==false){
                    return false;
                }
                if(pre!=NULL && T->data <= pre->data){
                    return false;
                }
                pre=T;
                return isBSTinorder(T->right,pre);
            }
            return true;
        } 
        void leafNodes(Node *T){
            if(T==NULL){
                return;
            }
            if(T->left==NULL && T->right==NULL){
                cout<<T->data<<" ";
                return;
            }
            else{
                if(T->left)
                    leafNodes(T->left);
                if(T->right)
                    leafNodes(T->right);
            }

        }
        bool isSparse(Node *T){
            int eNodes=NumberOfNodes(T);
            int maxNodes=pow(2,Height(T)+1)-1;
            float percent=(eNodes*100)/maxNodes;
            if(percent<50){
                return true;
            }
            return false;

        }
        

        bool isBST(Node *T){
            Node *pre=NULL;
            return isBSTinorder(T,pre);            

        }
        void visualizeTree(Node *T){
            int x=100;
            int y=100;
            int shift=ceil(NumberOfNodes(T));
            visualizeTraversal(T,x,y);
            
        }
        void visualizeTraversal(Node *T,int x,int y){
            if(T!=NULL){
                gotoxy(x,y);
                cout<<T->data<<" ";
                x -=5;
                y +=6;
                inOrderTraversal(T->left);
                inOrderTraversal(T->right);
            }
        }
        void gotoxy(int x, int y) // Function Definition
        {
            COORD coordinates;
            coordinates.X = x;
            coordinates.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
        }
        
};

int main(){
    BST *b=new BST();
    b->insertNode(5);
    b->insertNode(1);
    b->insertNode(2);
    b->insertNode(3);
    b->insertNode(6);
    b->insertNode(7);
    //b->insertNode(9);
    //b->insertNode(10);
    b->visualizeTree(b->getTree());
   
    // b->inOrderTraversal(b->getTree());
    // cout<<endl;
    // cout<<b->Height(b->getTree());
    // cout<<endl;
    // cout<<b->NumberOfNodes(b->getTree());
    // cout<<endl;
    // cout<<b->isBST(b->getTree());
    // cout<<endl;
    // b->leafNodes(b->getTree());
    // cout<<endl;
    // cout<<b->isSparse(b->getTree());

    





}