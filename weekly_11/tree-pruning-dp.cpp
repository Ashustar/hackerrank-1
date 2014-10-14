/*
 * Not the fish.
 * iSea @ 2014-10-09 11:56
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 2;
const int MAXK = 200 + 2;
const long long INF = -(long long)(1e15);

vector<int> g[MAXN];
int n, k, val[MAXN];
long long dpn[MAXK];

inline void update(long long& x, long long y) {
	x = max(x, y);
}

void dfs(int x, int f) {
	long long dpc[MAXK], dptmp[MAXK];
	fill (dpc, dpc + k + 1, INF);
	dpc[0] = val[x];

	for (const int& next : g[x]) {
		if (next != f) {
			dfs (next, x);
			fill (dptmp, dptmp + k + 1, INF);
			for (int ck = 0; ck <= k; ++ck) {
				if (dpc[ck] == INF) {
					break ;
				}
				for (int nk = 0; nk + ck <= k; ++nk) {
					if (dpn[nk] == INF) {
						break ;
					}
					update (dptmp[ck + nk], dpc[ck] + dpn[nk]);
				}
				if (ck + 1 <= k) {
					update (dptmp[ck + 1], dpc[ck]);
				}
			}
			// memcpy (dpc, dptmp, sizeof(dptmp));
			copy (dptmp, dptmp + k + 1, dpc);
		}
	}
	// memcpy (dpn, dpc, sizeof(dpc));
	copy (dpc, dpc + k + 1, dpn);
}

void solve() {
	dfs (0, -1);
	cout << max(0LL, *max_element(dpn, dpn + k + 1)) << endl;
}

int main() {
	// freopen ("tree-pruning.in", "r", stdin);
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