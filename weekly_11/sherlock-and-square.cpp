/*
 * Not the fish.
 * iSea @ 2014-10-07 13:18
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int fastmod(int a, int p) {
	if (p == 0) {
		return 1;
	}
	if (p & 1) {
		return (long long)a * fastmod(a, p - 1) % mod;
	}
	int ret = fastmod(a, p >> 1);
	return (long long)ret * ret % mod;
}

int main() {
	int T, x;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &x);
		printf ("%d\n", (fastmod(2, x + 1) + 2) % mod);
	}
	return 0;
}