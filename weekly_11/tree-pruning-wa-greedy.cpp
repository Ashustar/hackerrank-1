/*
 * Not the fish.
 * iSea @ 2014-10-09 10:42
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;

vector<int> g[MAXN];
int n, k, val[MAXN];
int height[MAXN], parent[MAXN];
bool erased[MAXN];
long long subsum[MAXN];

void dfs(int x, int f) {
	parent[x] = f;
	if (f != -1) {
		height[x] = height[f] + 1;
	}
	subsum[x] = val[x];
	for (const int& next : g[x]) {
		if (next != f) {
			dfs (next, x);
			subsum[x] += subsum[next];
		}
	}
}

set<pair<long long, pair<int, int> > > alter;

pair<long long, pair<int, int> > get_alter(int x) {
	return make_pair(subsum[x], make_pair(-height[x], x));
}

void erase_childnode_from_alter(int x) {
	erased[x] = true;
	printf ("erase %d\n", x);
	alter.erase (get_alter(x));
	for (const int& next : g[x]) {
		if (next != parent[x]) {
			erase_childnode_from_alter (next);
		}
	}
}

void erase_parentnode_from_alter(int x) {
	while (x != 0 && !erased[parent[x]]) {
		x = parent[x];
		erased[x] = true;
		alter.erase (get_alter(x));
		printf ("erase %d\n", x);
	}
}

void solve() {
	height[0] = 1;
	dfs (0, -1);

	alter.clear();
	for (int i = 0; i < n; ++i) {
		alter.insert(get_alter(i));
		erased[i] = false;
	}

	long long ret = subsum[0];
	for (int i = 0; i < k && !alter.empty(); ++i) {
		set<pair<long long, pair<int, int> > > :: iterator minimum = alter.begin();
		if (minimum->first < 0) {
			ret -= minimum->first;
			erase_childnode_from_alter (minimum->second.second);
			erase_parentnode_from_alter (minimum->second.second);
		} else {
			break;
		}
	}
	cout << ret << endl;
}

int main() {
	while (scanf ("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			scanf ("%d", &val[i]);
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf ("%d%d", &u, &v);
			g[--u].push_back(--v);
			g[v].push_back(u);
		}
		solve();
	}
	return 0;
}