#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m, dem = 0;
char a[1005][1005];
int visited[1005][1005];
int d[1005][1005];  // d[i][j] 

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
}

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = 1;
	while(!q.empty()){
		pair<int, int> p = q.front(); q.pop();
		++dem;
		for(int k = 0; k < 4; k++){
			int i1 = p.first + dx[k], j1 = p.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.' && visited[i1][j1] == 0){
				q.push({i1, j1});
				visited[i1][j1] = 1;
			}
		}
	}
}

int main(){
	nhap();
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '.' && !visited[i][j]){
				bfs(i, j);
				++ans;
			}
		}
	}
	cout << ans << endl;
}
