#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int d[256];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size(), mx = 0; // tan suat lon nhat cua 1 ky tu trong s
    for (char c : s)
    {
        d[c]++;
        mx = max(mx, d[c]);
    }
    if (mx > (n + 1) / 2) // n + 1 / 2  = so vi tri chan ke ca khi n chan va n le
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
