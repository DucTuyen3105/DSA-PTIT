#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, s, a[202];

bool f[202][100005]; // f[i][j]: co tao duoc tong j tu cac so tu 1 den i hay khong?
                     // dap an: f[n][s]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // co so qhd
    f[0][0] = 1; // ta co the tao duoc tong 0 tu 0 so
    for (int i = 1; i <= n; i++)
    { // duyet cac i
        for (int j = 0; j <= s; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]]);
            }
        }
    }
    cout << f[n][s];
    return 0;
}
