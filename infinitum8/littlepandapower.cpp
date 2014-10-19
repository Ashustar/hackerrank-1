/*
 * Not the fish.
 * iSea @ 2014-10-19 16:15
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

int fast_mod(int a, long long n, int mod) {
	int ret = 1;
	while (n) {
		if (n & 1LL) ret = (long long)ret * a % mod;
		a = (long long)a * a % mod;
		n >>= 1;
	}
	return ret;
}

int ex_gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int g = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return g;
}

int get_inv(long long X, int mod) {
	int x, y;
	ex_gcd(X, mod, x, y);
	while (x < 0) x += mod;
	return x;
}

int main() {
	repcase {
		int A, B, X;
		scanf ("%d%d%d", &A, &B, &X);
		if (X == 1) {
			puts ("0");
			continue ;
		}
		if (B >= 0) printf ("%d\n", fast_mod(A, B, X));
		else printf ("%d\n", fast_mod(get_inv(A, X), -B, X));
	}
	return 0;
}