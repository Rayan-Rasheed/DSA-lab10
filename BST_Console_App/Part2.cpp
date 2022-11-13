#include<iostream>
#include <cmath>
#include <windows.h>
#include<conio.h>
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
            return root;


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
            
        }
        
        
        
};
void gotoxy(int x, int y) // Function Definition
        {
            COORD coordinates;
            coordinates.X = x;
            coordinates.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
        }
void header(){
    gotoxy(15,1);
    cout<<"**********************BINARY TREE STRUCTURE*********************\n\n";
}
int mainMenu(){
    system("cls");
    header();
    cout<<"1-Insert Node \n";    
    cout<<"2-Find Node  \n";  
    cout<<"3-Delete Node\n"; 
    cout<<"4-Show Inorder Traveresal\n";    
    cout<<"5-Show PreOrder Traveresal\n";    
    cout<<"6-Show PostOrder Traveresal\n";  
    cout<<"7-Get Number of Nodes\n";
    cout<<"8-Get Height of Tree\n";  
    cout<<"9-Get leafNodes of Tree\n"; 
    cout<<"10-Sparse Tree\n"; 
    cout<<"Choose option....";
    int opt;
    cin>>opt;
    return opt;





}
bool insertNode(BST *b){
    cout<<"Enter Node value: ";
    int val;
    cin>>val;
    Node *n=b->insertNode(val);
    if(n){
        return true;
    }
    
}
bool findNode(BST *b){
    cout<<"Enter Node value to find: ";
    int val;
    cin>>val;
    Node *n=b->findNode(val);
    if(n){
        return true;
    }
    return false;
}
bool DeleteNode(BST *b){
    cout<<"Enter Node value to delete: ";
    int val;
    cin>>val;
    Node *n=b->findNode(val);
    if(n){
        b->deleteNode(val);

        return true;
    }
    return false;
}
int main(){

    BST *b=new BST();
    int option=1;
    while(option<10 && option>0){
        option=mainMenu();
        if(option==1){
            system("cls");
            header();
            if(insertNode(b)==false){
                cout<<"Node Inserted";
            }
            getch();

        }
        else if(option==2){
            system("cls");
            header();
            if(findNode(b)){
                cout<<"Found";
            }
            else{
                cout<<"Not found";
            }
            getch();
        }
        else if(option==3){
            system("cls");
            header();
            if(DeleteNode(b)){
                cout<<"Node deleted";
            }
            
            getch();

        }
        else if(option==4){
            system("cls");
            header();
            b->inOrderTraversal(b->getTree());
            getch();

        }
        else if(option==5){
            system("cls");
            header();
            b->preOrderTraversal(b->getTree());
            getch();

        }
        else if(option==6){
            system("cls");
            header();
            b->postOrderTraversal(b->getTree());
            getch();


        }
        else if(option==7){
            system("cls");
            header();
            cout<<b->NumberOfNodes(b->getTree());
            getch();

        }
        else if(option==8){
            system("cls");
            header();
            cout<<b->Height(b->getTree());
            getch();


        }
        else if(option==10){
            system("cls");
            header();
            cout<<b->isSparse(b->getTree());
            getch();

        }
        else if(option==9){
            system("cls");
            header();
            b->leafNodes(b->getTree());
            getch();
        }

    }
    
    


    // b->insertNode(5);
    // b->insertNode(1);
    // b->insertNode(2);
    // b->insertNode(3);
    // b->insertNode(6);
    // b->insertNode(7);
    // //b->insertNode(9);
    // //b->insertNode(10);
    // b->visualizeTree(b->getTree());
   
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