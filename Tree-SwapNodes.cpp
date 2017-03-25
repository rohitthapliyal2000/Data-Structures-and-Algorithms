#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node
{
    int data;
    node *left;
    node *right;
}node;

void inorder(node *root)
{
    if(root == NULL)
        return;
    else
    {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}


node * swaps(node* root, int height)
{
    if(root == NULL)
        return root;
    else
    {
        if(height == 1)
        {
            node * inter;
            if(root == NULL)
                return root;
            inter = root -> left;
            root -> left = root -> right;
            root -> right = inter;
        }
        else
        {
            if(root == NULL)
                return root;
            swaps(root -> left , height - 1);
            swaps(root -> right , height - 1);
        }
    }
    return root;
}

int main() {

    int nodes , a , b;
    node *root;
    cin >> nodes;
    if(nodes == 0)
        return 0;
    node *arr[1000];
    for(int i = 0; i < nodes; i++)
    {
        arr[i] = new node();
        arr[i] -> data = i+1;
    }
    for(int i = 0; i < nodes; i++)
    {
        cin >> a >> b;
        if(a == -1)
        {
            arr[i] -> left = NULL;
        }
        else
        {
            arr[i] -> left = arr[a-1];
        }
        if( b == -1)
        {
            arr[i] -> right = NULL;
        }
        else
        {
            arr[i] -> right = arr[b-1];
        }
    }
    root = arr[0];
    int t;
    cin >> t;
    int height , safe;
    for(int i = 0; i < t; i++)
    {
        cin >> height;
        safe = height;
        while(safe < nodes)
        {
            root = swaps(root , safe);
            safe += height;
        }
        inorder(root);
        cout << endl;
    }
    return 0;
}
