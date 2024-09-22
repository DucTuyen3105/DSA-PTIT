#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m;
char a[10][10];
string s;
bool found = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[20][20];
void Try(int x, int y, int pos)
{
    visited[x][y] = 1;
    if (found || pos == s.size())
    {
        found = 1;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int i = x + dx[k], j = y + dy[k];
        if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == s[pos] && !visited[i][j])
        {
            Try(i, j, pos + 1);
        }
    }
    visited[x][y] = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == s[0])
                Try(i, j, 1);
    if (found)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
