/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
int i = 0;
void inorder(int arr[], Node *root)
{
    if(root == NULL)
        return;
    else
    {
        inorder(arr, root -> left);
        arr[i++] = root -> data;
        inorder(arr, root -> right);
    }
}

bool checkBST(Node* root)
{
    int arr[10000];
    inorder(arr , root);
    int i = 1 , counter = 0, loop = 0;
    while(arr[i] != 0)
    {
        if(arr[i] > arr[i-1])
            counter++;
        loop++;
        i++;
    }
    if(loop == counter)
        return true;
    else
        return false;
}
