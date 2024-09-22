#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int f[1003][1003]; // f[i][j]: do dai xau con chung dai nhat cua 2 xau s[1:i] va t[1:j]
                   // f[n][m]: dap an, n=s.size(), m=t.size();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    // co so qhd    (bai toan nho nhat)
    f[0][0] = 0;
    // tinh f[i][j] ntn?
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[n][m];
    return 0;
}
