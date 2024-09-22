#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, a[502][502], f[502][502]; // f[i][j]: hinh vuong lon nhat ket thuc tai a[i][j]
                                    // dap an la max(f[i][j])
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
            {
                f[i][j] = min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]}) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
