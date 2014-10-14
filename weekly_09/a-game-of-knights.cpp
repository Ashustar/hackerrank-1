// Rain Dreamer MODEL
// iSea @ 2014-08-29 16:06
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

const int MAXN = 300 + 10;

int n, k, X, sg[MAXN][MAXN];

int get_sg(int x, int y);

void dfs(int x, int y, int left_step, int *mem) {
	if (x < 0 || y < 0) {
		return ;
	}
	if (left_step != X) {
		mem[get_sg(x, y)] += 1;
	}
	if (left_step == 0) {
		return ;
	}
	dfs (x - 1, y - 2, left_step - 1, mem);
	dfs (x - 2, y - 1, left_step - 1, mem);
}

int get_sg(int x, int y) {
	if (sg[x][y] != -1) {
		return sg[x][y];
	}
	int bound = 2 * X + 1;
	if (x >= bound && y >= bound) {
		return sg[x][y] = get_sg(x - bound, y - bound);
	}
	if (x < bound && y >= 4 * X) {
		return sg[x][y] = x;
	}
	if (y < bound && x >= 4 * X) {
		return sg[x][y] = y;
	}
	int mem[12] = {0};
	dfs(x, y, X, mem);
	for (int ret = 0; ; ++ret) {
		if (mem[ret] == 0) {
			// printf ("calc sg[%d][%d] = %d\n", x, y, ret);
			return sg[x][y] = ret;
		}
	}
}

void add_under_k(int* x, int y, int K) {
	rep (i, 32) {
		x[i] = (x[i] + (y & 1)) % K;
		y >>= 1;
		if (!y) break;
	}
}

bool is_zero(int* x, int K) {
	rep (i, 32) {
		if (x[i] % K != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	// freopen ("test.out", "w", stdout);
	repcase {
		scanf ("%d%d%d", &n, &k, &X);
		memset (sg, -1, sizeof(sg));
		// rep (i, 201) rep (j, 201) {
		// 	printf ("%d%c", get_sg(i, j), j == 200? '\n' : ' ');
		// }
		int ret[32] = {0};
		memset (ret, 0, sizeof(ret));
		rep (i, n) {
			int xi, yi;
			scanf ("%d%d", &xi, &yi);
			// printf ("%d %d sg: %d\n", xi, yi, get_sg(xi, yi));
			add_under_k(ret, get_sg(xi, yi), k + 1);
		}
		puts (is_zero(ret, k + 1)? "Second player wins" : "First player wins");
	}
	return 0;
}