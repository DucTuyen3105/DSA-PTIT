#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, a[20];
bool check(vector<int> v)
{
    int res = 0;
    for (int x : v)
        res += x;
    return res % 2;
}
vector<vector<int>> ans;
bool used[20];
void Try(vector<int> v, int last)
{
    if (v.size() && check(v))
        ans.push_back(v);
    for (int i = last + 1; i < n; i++)
    {
        if (!used[i])
        {
            v.push_back(a[i]);
            used[i] = 1;
            Try(v, i);
            v.pop_back();
            used[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v;
    Try(v, -1);
    if (ans.empty())
    {
        cout << "NOT FOUND";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        for (int i : x)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
