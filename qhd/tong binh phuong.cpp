#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll f[10004];
vector<int> v; // luu cac so chinh phuong
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 100; i++)
    {
        v.push_back(i * i);
    }
    for (int i = 1; i <= 10000; i++)
        f[i] = i;
    for (int i = 1; i <= 10000; i++)
    {
        for (int x : v)
        {
            if (i >= x)
            {
                f[i] = min(f[i], f[i - x] + 1);
            }
            else
                break;
        }
    }
    int n;
    cin >> n;
    cout << f[n];
    return 0;
}
