#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s;
    cin >> n >> s >> m;
    int total = s * m;         // tong so luong thuc can
    int res = (s - s / 7) * n; // tong so luong thuc toi da mua duoc
    if (res < total)
        cout << -1;
    else
    {
        int ans = total / n;
        if (total % n)
            ans++;
        cout << ans;
    }
    return 0;
}
