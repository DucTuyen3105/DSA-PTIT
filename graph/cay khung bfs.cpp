#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, s;
set<int> adj[1003];
bool visited[1003];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
                cout << u << "->" << v << '\n';
            }
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
    bfs(s);
    return 0;
}
