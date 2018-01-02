#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 1;
    cin >> n;
    
    for(int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while(n % i == 0)
        {
            n /= i;
            count++;
        }
        ans *= (count + 1);
    }
    
    if(n != 1)
        ans *= (2);
    
    cout << ans;
}
