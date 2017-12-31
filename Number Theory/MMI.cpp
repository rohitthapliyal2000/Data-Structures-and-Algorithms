#include <bits/stdc++.h>
using namespace std;
#define int long long
int x = 0, y = 0, temp = 0;

int power(int a, int b, int m)
{
    a %= m;
    if(b == 1 || b == 0)
        return a;
    if(b % 2)
    {
        return (a * power((a * a)%m, (b-1)/2, m)) % m;
    }
    else
    {
        return (power((a * a)%m, (b)/2, m) % m);
    }
}

void inv(int c, int m)
{
    if(!m)
    {
        x = 1;
        y = 0;
    }
    else
    {
        inv(m, c % m);
        temp = x;
        x = y;
        y = temp - ((c/m) * y);
    }
}

signed main()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    inv(c, m);
    cout << (((power(a, b, m))%m) * ((x + m) % m)) % m;
}
