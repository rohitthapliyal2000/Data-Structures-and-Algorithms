/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
int arr1[1000] , arr2[1000];
void forv2(int v2, node *root)
{
    node *temp = root;
    int i = 0;
    while(temp -> data != v2)
    {
        if(temp -> data > v2)
        {
            arr2[i++] = temp -> data;
            temp = temp -> left;
        }
        else if(temp -> data < v2)
        {
            arr2[i++] = temp -> data;
            temp = temp -> right;
        }
        else
        {
            arr2[i++] = temp -> data;
            break;
        }

    }
    arr2[i] = temp -> data;

}

void forv1(int v1, node * root)
{
    node *temp = root;
    int i = 0;
    while(temp -> data != v1)
    {
        if(temp -> data > v1)
        {
            arr1[i++] = temp -> data;
            temp = temp -> left;
        }
        else if(temp -> data < v1)
        {
            arr1[i++] = temp -> data;
            temp = temp -> right;
        }
        else
        {
            arr1[i++] = temp -> data;
            break;
        }

    }
    arr1[i] = temp -> data;

}

node * lca(node * root, int v1,int v2)
{
    forv1(v1,root);
    forv2(v2,root);
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 100; i++)
    {
        if(arr1[i] != 0)
        {
            c1++;
        }
        if(arr2[i] != 0)
        {
            c2++;
        }
        if(arr1[i] == 0 && arr2[i] == 0)
        {
            break;
        }
    }
    int min = 999, num;
    for(int i = 0; i < c1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                num = arr1[i];
            }
            if(num < min)
            {
                min = num;
            }
        }
    }
    node *temp = root;
    while(temp -> data != min)
    {
        if(temp -> data < min)
        {
            temp = temp -> right;
        }
        else if(temp -> data > min)
        {
            temp = temp -> left;
        }
        else
        {
            break;
        }
    }
    return temp;
}

