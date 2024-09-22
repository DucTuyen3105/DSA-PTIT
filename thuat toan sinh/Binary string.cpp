#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
int a[100][100];
int check[100][100];
vector<string> v;

void Try(int i, int j, string s) {
    check[i][j] = 1;
    s += to_string(a[i][j]);
    if (i == n && j == n) {
        v.push_back(s);
        check[i][j] = 0;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= n && check[x][y] == 0) {
            Try(x, y, s);
        }
    }
    check[i][j] = 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    Try(1, 1, "");
    int _max = 0;
    for (auto &s : v) {
        if (s.length() > _max) _max = s.length();
    }
    for (auto &s : v) {
        while (s.length() < _max) {
            s = "0" + s;
        }
    }
    string ans = v[0];
    for (auto &x : v) {
        if (x > ans) ans = x;
    }
    cout << ans;
}
		

			
			
