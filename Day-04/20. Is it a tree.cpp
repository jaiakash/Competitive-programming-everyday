// Link - https://www.spoj.com/problems/PT07Y/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
bool vis[100001];
void dfs(int i) {
	vis[i] = 1;
	for (auto a : ar[i]) {
		if (!vis[a])
			dfs(a);
	}
}

signed main() {
	int n;	cin >> n;
	int q;	cin >> q;
	if (q != n - 1) {
		cout << "NO";
		return 0;
	}
	while (q--) {
		int a, b;	cin >> a >> b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
			if (ans == 2) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}