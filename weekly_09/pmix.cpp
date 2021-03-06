// Rain Dreamer MODEL
// iSea @ 2014-08-29 02:41
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

const int MAXN = 1000000 + 10;

const int mp[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

char buf[MAXN], tmp[MAXN];
int n, k;

void change(int step) {
	memcpy (tmp, buf, sizeof(tmp));
	rep (i, n) {
		buf[i] = mp[tmp[i]][tmp[(i + step) % n]];
	}
}

int main() {
	while (scanf ("%d%d", &n, &k) != EOF) {
		scanf ("%s", buf);
		rep (i, n) buf[i] = buf[i] - 'A';
		int step = 1;
		while (k) {
			if (k & 1) change(step);
			step <<= 1;
			k >>= 1;
		}
		rep (i, n) buf[i] = buf[i] + 'A';
		puts (buf);
	}
	return 0;
}