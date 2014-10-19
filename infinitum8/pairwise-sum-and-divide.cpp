/*
 * Not the fish.
 * iSea @ 2014-10-19 16:02
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

int main() {
	repcase {
		int n;
		scanf ("%d", &n);
		int num1 = 0, num2 = 0;
		rep (i, n) {
			int bar;
			scanf ("%d", &bar);
			if (bar == 1) num1++;
			else if (bar == 2) num2++;
		}
		long long ans = (long long)num1 * (num1 - 1);
		ans += num1 * (n - num1);
		ans += (long long)num2 * (num2 - 1) / 2;
		cout << ans << endl;
	}
	return 0;
}