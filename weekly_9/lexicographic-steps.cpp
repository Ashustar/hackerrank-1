// Rain Dreamer MODEL
// iSea @ 2014-08-29 01:04
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int MAXN = 22;

int com[MAXN][MAXN];

void solve(int n, int m, int k) {
	if (n == 0 && m == 0) return ;
	if (com[n + m - 1][m] >= k + 1) {
		putchar ('H');
		solve(n - 1, m, k);
		return ;
	}
	putchar ('V');
	solve(n, m - 1, k - com[n + m - 1][m]);
}

int main() {
	rep (i, MAXN) {
		com[i][0] = com[i][i] = 1;
		repf (j, 1, i - 1) {
			com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
		}
		// repf (j, 0, i) {
		// 	printf ("%d%c", com[i][j], j == i? '\n' : ' ');
		// }
	}
	repcase {
		int n, m, k;
		scanf ("%d%d%d", &n, &m, &k);
		solve(n, m, k);
		puts ("");
	}
	return 0;
}