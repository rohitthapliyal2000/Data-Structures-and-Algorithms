#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char>s;
    char ch;
    string st;
    cin >> st;
    for(int i = 0; i < st.size(); i++)
    {
        ch = st[i];
        if(ch == '(')
            s.push(ch);
        else if(s.empty())
        {
            cout << "Wrong Format\n";
            return 0;
        }
        else
            s.pop();
    }
    if(!s.empty()) cout << "Wrong Format\n";
    else cout << "Correct Format\n";
    return 0;
}
