#include <bits/stdc++.h>
using namespace std;

int arr[1000000 + 1];
int n, k, x, y;


int root(int element)
{
    int i = element;
    while(arr[i] != i)
    {
        i = arr[i];
    }
    return i;
}

void change(int x, int y)
{
    int temp = root(y);
    int changer = root(x);
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == temp)
        {
            arr[i] = changer;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        change(x, y);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}