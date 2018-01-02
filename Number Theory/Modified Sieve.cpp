#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
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
    
    for(int i = 1; i <= n; i++)
    {
        cout << i << "'s smallest prime factor -> " << lastPrime[i] << endl;
    }
}
