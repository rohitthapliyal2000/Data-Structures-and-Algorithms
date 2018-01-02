#include <bits/stdc++.h>
using namespace std;

#define int long long

/****Iterative*****
int power(int a ,int b)
{
    int result = 1;
    
    while(b)
    {
        if(b % 2) result *= a;
        a *= a;
        b /= 2;
    }
    
    return result;
}*/

/*****Recursive*****/
int power(int a, int b)
{
    if(b <= 1)
        return a;
    if(b % 2)
    {
        return (a * power(a * a, (b-1)/2));
    }
    else
    {
        return (power(a * a, b/2));
    }
}

signed main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
}
