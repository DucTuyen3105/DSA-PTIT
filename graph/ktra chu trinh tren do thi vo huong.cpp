#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int n, m, chutrinh = 0;
vector<int> ke[200005];
int visited[200005];
int parent[200005];

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

void dfs(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			parent[v] = u;
			dfs(v);
		}
		else if(v != parent[u]){ // khong phai to tien cua u nhung noi duoc den u theo con duong khac => canh nguoc
			chutrinh = 1;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
			if(chutrinh){
				cout << 1 << endl; return 0;
			}
		}
	}
	cout << 0 << endl;
}	
