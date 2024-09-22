#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, s;
set<int> adj[1003];
bool visited[1003];
void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            cout << u << "->" << v << '\n';
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(s);
    return 0;
}
