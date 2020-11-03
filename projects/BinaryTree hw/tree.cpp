#include <iostream>
#include <vector>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node* left;
    struct Node* right; 
}; 
  
/* allocates a new node */
Node* new_node(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// insert nodes in array order 
Node* insert(int arr[], Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = new_node(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insert(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insert(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
  
// print the tree in order of level
void print_in_order(Node* root) 
{ 
    if (root != NULL) 
    { 
        print_in_order(root->left); 
        std::cout << root->data <<" "; 
        print_in_order(root->right); 
    } 
} 



bool exists(Node* root,int val)
{
    if(root == NULL)
        return false;
    if(root->data == val)
        return true;
    if(exists(root->left,val))
        return true;
    if(exists(root->right,val))
        return true;
    else
        return false;
    
}

int checkSiblings(Node* root, int val)
{
    if(root->left == NULL | root->right==NULL)
        return -1;
    if(root->left->data == val)
        if(root->right != NULL)
            return root->right->data;
        else
            return -1;
    if(root->right->data == val)
        if(root->right != NULL)
            return root->left->data;
        else 
            return -1;
    if(checkSiblings(root->left,val) != -1)
        return checkSiblings(root->left,val);
    if(checkSiblings(root->right,val) != -1)
        return checkSiblings(root->right,val);
    else
        return -1;
}

int checkParent(Node* root, int val)
{
    if(root ->left == NULL && root->right == NULL)
            return -1;
    if(root->left != NULL)
    {
        if(root->left->data == val)
            return root->data;
    }
    if(root->right != NULL)
    {
        if(root->right->data == val)
            return root->data;
    }
    
    if(checkParent(root->left,val) != -1)
        return checkParent(root->left,val);
    if(checkParent(root->right,val) != -1)
        return checkParent(root->right,val);
    else
        return -1;   
}

string checkChildren(Node* root, int val)
{
    string ret ="";
    if(root == NULL)
        return ret;
    if(root->data == val)
    {  
        if(root->left != NULL)
            ret += to_string(root->left->data);
        if(root->right != NULL)
        {
            if(root->left != NULL)
                ret += " and ";
            ret += to_string(root->right->data);
        }
            
        return ret;
    }
    if(checkChildren(root->left,val) != "")
        return checkChildren(root->left,val);
    if(checkChildren(root->right,val) != "")
        return checkChildren(root->right,val);
    else
        return ret; 
}

bool deleteLeaf(Node* root,int val)
{
    if(root ->left == NULL && root->right == NULL)
        return false;
    if(root->left != NULL)
    {
        if(root->left->data == val)
        {   
            root->left = NULL;
            return true;
        }
    }
    if(root->right != NULL)
    {   
        if(root->right->data == val)
        {
            root->right = NULL;
            return true;
        }
    }
    if(root->left != NULL){
        if(deleteLeaf(root->left,val))
            return true;
    }
    if(root->right != NULL){
        if(deleteLeaf(root->right,val))
            return true;
    }
    return false;   
}


bool deleteNodeOneChild(Node* root, int val)
{
    if(root ->left == NULL && root->right == NULL)
            return false;
    if(root->left != NULL)
    {
        if(root->left->data == val)
        {   
            if(root->left->left != NULL){
                root->left = root->left->left;
            }
            else{
                root->left = root->left->right;
            }
            return true;
        }
    }
    if(root->right != NULL)
    {
        if(root->right->data == val)
        {
            if(root->right->left != NULL){
                root->right = root->right->left;
            }
            else{
                root->right = root->right->right;
            }
            return true;
        }
    }
    
    if(deleteNodeOneChild(root->left,val))
        return deleteNodeOneChild(root->left,val);
    if(deleteNodeOneChild(root->right,val))
        return deleteNodeOneChild(root->right,val);
    else
        return false;   
}


Node* getLoneChild(Node* root){
    Node* empty = NULL;
    if(root->left == NULL && root->right == NULL)
            return empty;
    
    if(root->left!=NULL && root->right==NULL){   
        Node* temp = root->left;
        root->left=NULL;
        return temp;
    }
    else if(root->left==NULL && root->right != NULL){
        Node* temp = root->right;
        root->right=NULL;
        return temp;
    }
    
    
    
    return getLoneChild(root->left);
    return getLoneChild(root->right);
    return empty;
}



bool deleteNodeTwoChildren(Node* root, int val){
    if(root ->left == NULL && root->right == NULL)
            return false;
    if(root->left != NULL)
    {
        if(root->left->data == val)
        {   
            Node* tempRight = root->left->right; 
            root->left = root->left->left;
            root->left->left=NULL;
            root->left->right = tempRight;
            Node* loneChild = getLoneChild(root);
            if(loneChild != NULL)
                root->left->left = loneChild;
            return true;
        }
    }
    if(root->right != NULL)
    {
        if(root->right->data == val)
        {          
            Node* tempRight = root->right->right;
            root->right = root->right->left;
            root->right->left=NULL;
            root->right->right = tempRight;
            Node* loneChild = getLoneChild(root);
            if(loneChild != NULL)
                root->right->left = loneChild;
            return true;
        }
    }
    
    if(deleteNodeTwoChildren(root->left,val))
        return deleteNodeTwoChildren(root->left,val);
    if(deleteNodeTwoChildren(root->right,val))
        return deleteNodeTwoChildren(root->right,val);
    else
        return false;   
}


void deleteNode(Node* root, int val)
{
    //returnArr(root);
    if(!exists(root,val))
        return;
    else if(checkChildren(root,val).find("and")<checkChildren(root,val).length()){
        //Node with two children
        deleteNodeTwoChildren(root,val);
        //restructure, balance with array method maybe?
        return;
    }
    else if(checkChildren(root, val) != ""){
        //node with one child
        //restructure, max of left side or min of right side or something
        deleteNodeOneChild(root, val);
        return;
    }
    else{
        //it's a leaf
        while(deleteLeaf(root,val));

        return;
    }
}


int main(int args, char **argv) 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insert(arr, root, 0, n); 
    cout<<"Printing the tree first: ";
    print_in_order(root); 

    //The program will check if the following number exists
    int check = 10;
    cout<<"\nDoes the number "<<check<<" exist? ";
    if(exists(root,check))
        cout<<"Yes";
    else
        cout<<"No";
    //Now checking if another number exists
    check = 5;
    cout<<"\nDoes the number "<<check<<" exist? ";
    if(exists(root,check))
        cout<<"Yes";
    else
        cout<<"No";
    
    //The program will check for a sibling, parent, and children of the following value
    int checkFamily = 3;
    cout<<"\nDoes the number "<<checkFamily<<" have a sibling? ";
    if(checkSiblings(root,checkFamily) == -1)
        cout<<"No";
    else
        cout<<"Yes, "<<checkFamily<<" has "<<checkSiblings(root,checkFamily)<<" as a sibling.";
    
    cout<<"\nDoes the number "<<checkFamily<<" have a parent? ";
    if(checkParent(root,checkFamily) == -1)
        cout<<"No";
    else
        cout<<"Yes, "<<checkFamily<<" has "<<checkParent(root,checkFamily)<<" as a parent.";
    
    cout<<"\nDoes the number "<<checkFamily<<" have any children? ";
    if(checkChildren(root,checkFamily) == "")
        cout<<"No";
    else
        cout<<"Yes, "<<checkFamily<<" has "<<checkChildren(root,checkFamily)<<" as children.";
    //Now let's see if 4 has children
    checkFamily=4;
    cout<<"\nDoes the number "<<checkFamily<<" have any children? ";
    if(checkChildren(root,checkFamily) == "")
        cout<<"No";
    else
        cout<<"Yes, "<<checkFamily<<" has "<<checkChildren(root,checkFamily)<<" as children.";
    cout<<"\n";

    //Now time for some deletion
    int nodeOneChild = 4;
    cout<<"\nDeleting node with one child of value "<<nodeOneChild<<". Currently ";
    print_in_order(root);
    deleteNode(root,nodeOneChild);
    cout<<"\nNode with one child deleted, now it is ";
    print_in_order(root);

    int leaf = 6;
    cout<<"\nDeleting all leaves of value "<<leaf<<". Currently ";
    print_in_order(root);
    deleteNode(root,leaf);
    cout<<"\nLeaves deleted, now it is ";
    print_in_order(root);
    cout<<"\n";
    
    int nodeTwoChildren = 2;
    cout<<"\nDeleting node with 2 children of value "<<nodeTwoChildren<<". Currently ";
    print_in_order(root);
    deleteNode(root,nodeTwoChildren);
    cout<<"\nNode with 2 children deleted, now it is ";
    print_in_order(root);
} 
