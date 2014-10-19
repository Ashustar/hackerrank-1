/*
 * Not the fish.
 * iSea @ 2014-10-19 16:37
 */

#include <bits/stdc++.h>

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

int n, goal, a[18];
long long lcm[1 << 18];
int ct[1 << 18];

long long get(long long X) {
	long long ret = X;
	rep (st, goal) {
		if (ct[st] & 1) ret += X / lcm[st];
		else ret -= X / lcm[st];
	}
	// printf ("get %I64d -> %I64d\n", X, ret);
	return ret;
}

int main() {
	while (scanf ("%d", &n) != EOF) {
		rep (i, n) {
			scanf ("%d", &a[i]);
		}
		goal = (1 << n);
		rep (st, goal) {
			long long lc = 1;
			int cnt = 0;
			rep (i, n) {
				if ((st >> i) & 1) {
					cnt += 1;
					lc *= a[i] / __gcd(lc, (long long)a[i]);
				}
			}
			ct[st] = cnt;
			lcm[st] = lc;
		}
		repcase {
			long long L, R;
			cin >> L >> R;
			cout << get(R) - get(L - 1) << endl;
		}
	}
	return 0;
}