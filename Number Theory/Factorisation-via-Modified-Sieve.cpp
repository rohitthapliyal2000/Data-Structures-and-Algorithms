#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n == 1)
    {
        cout << n; return 0;
    }
    
    int lastPrime[n+1];
    
    for(int i = 0; i <= n; i++) lastPrime[i] = 0;
    
    for(int i = 2; i * i <= n; i++)
    {
        if(!lastPrime[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                if(!lastPrime[j])
                    lastPrime[j] = i;
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!lastPrime[i])
        {
            lastPrime[i] = i;
        }
    }
    
    vector <int> factors;
    
    while(n > 1)
    {
        factors.push_back(lastPrime[n]);
        n /= lastPrime[n];
    }
    
    for(int i : factors) cout << i << ' ';
}
