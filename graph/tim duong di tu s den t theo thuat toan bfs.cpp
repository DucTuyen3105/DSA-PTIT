#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int n, m, s, t;
vector<int> ke[200005];
int visited[200005];
int parent[200005];

void nhap(){
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
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
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	dfs(s);
	if(!visited[t]){
		cout << "-1\n";
	}
	else{
		vector<int> v; // luu duong di
		while(t != s){
			v.push_back(t);
			t = parent[t];
		}
		v.push_back(s);
		reverse(v.begin(), v.end());
		for(int x : v){
			cout << x << " ";
		}
	}
}
