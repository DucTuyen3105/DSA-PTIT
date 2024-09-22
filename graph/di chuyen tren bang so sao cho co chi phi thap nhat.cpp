#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, a[503][503], c[503][503]; // c[i][j]: chi phi thap nhat de tu (1, 1) den (i, j)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    c[0][0] = a[0][0];
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int i = x.first + dx[k], j = x.second + dy[k];
            if (i >= 0 && i < n && j >= 0 && j < m && c[i][j] > c[x.first][x.second] + a[i][j])
            {
                c[i][j] = c[x.first][x.second] + a[i][j];
                q.push({i, j});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            c[i][j] = 1e9;
        }
    }
    bfs();
    cout << c[n - 1][m - 1];
}
