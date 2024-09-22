#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int f[1003][1003]; // f[i][j]: tong lon nhat co the thu duoc khi di den o (i, j)
// dap an: max(f[n][i]) -> tong lon nhat o hang thu n
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // khoi tao co so qhd
    for (int i = 1; i <= n; i++)
        f[1][i] = a[1][i]; // hang tren cung la cac o xuat phat
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j]; // tu o ben tren di xuong
            if (j > 1)
            { // ton tai o tren ben trai
                f[i][j] = max(f[i][j], f[i - 1][j - 1]);
            }
            if (j < n)
            { // ton tai o tren ben phai
                f[i][j] = max(f[i][j], f[i - 1][j + 1]);
            }
            f[i][j] += a[i][j]; // cong gia tri cua o hien tai vao f[i][j]
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}
