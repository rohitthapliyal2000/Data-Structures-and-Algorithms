#include <bits/stdc++.h>
using namespace std;

#define int long long

/****Iterative*****
int power(int a ,int b, int m)
{
    int result = 1;
    
    while(b)
    {
        if(b % 2) result = ((result % m) * (a % m)) % m;
        a = (a * a) % m;
        b /= 2;
    }
    
    return result;
}*/

/*****Recursive*****/
int power(int a, int b, int m)
{
    a %= m;

    if(b <= 1)
        return a % m;
    if(b % 2)
    {
        return (a * (power((a * a) % m, (b-1)/2, m)) % m) % m;
    }
    else
    {
        return power((a * a) % m, b/2, m) % m;
    }
}

signed main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << power(a, b, m);
}
