typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n, m, s;
vector<ii> ke[200005];
int visited[200005];
int d[505][505]; // (1, 1) => (i, j)
int a[505][505];

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			d[i][j] = 1e9;
		}
	}
}

void Dijkstra(int i, int j){
	priority_queue<iii, vector<iii>, greater<iii>> Q;
	d[i][j] = a[i][j];
	Q.push({a[i][j], {i, j}});
	while(!Q.empty()){
		iii p = Q.top(); Q.pop();
		//p.first : chi phi duong di, p.second : dinh 
		int i1 = p.second.first, j1 = p.second.second;
		int chiphi = p.first;
		if(chiphi > d[i1][j1]) continue;
		for(int k = 0; k < 4; k++){
			int i2 = i1 + dx[k], j2 = j1 + dy[k];
			if(i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m){
				if(d[i2][j2] > d[i1][j1] + a[i2][j2]){
					d[i2][j2] = d[i1][j1] + a[i2][j2];
					Q.push({d[i2][j2], {i2, j2}});
				}
			}
		}
	}
	cout << d[n][m] << endl;
}
