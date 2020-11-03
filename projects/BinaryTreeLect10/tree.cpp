#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* new_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insert(int arr[], Node* root, int i, int n)
{
    if(i<n)
    {
        Node* temp = new_node(arr[i]);
        root = temp;
        root->left = insert(arr, root->left, 2*i+1, n);
        root->right = insert(arr,root->right,2*i+2, n);
    }
    return root;
}

void print_in_order(Node* root)
{
    if(root != NULL)
    {
        print_in_order(root->left);
        cout<<root->data<<" ";
        print_in_order(root->right);
    }
}

int main(int args, char **argv)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = insert(arr, root, 0, n);
    print_in_order(root);
}