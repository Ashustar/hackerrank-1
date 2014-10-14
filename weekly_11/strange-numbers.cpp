/*
 * Not the fish.
 * iSea @ 2014-10-08 10:26
 */

#include <bits/stdc++.h>

using namespace std;

vector<long long> allS;

int get_length(long long X) {
	// length of X
	return X < 10? 1 : get_length(X / 10) + 1;
}

void gen_all() {
	for (int i = 0; i < 10; ++i) {
		allS.push_back(i);
	}
	int pointer = 0;
	while (pointer < (int)(allS.size())) {
		long long num = allS[pointer];
		int len = get_length(num);
		if (len != 1 && get_length(num * len) == len) {
			allS.push_back(num * len);
		}
		if (len < 18 && get_length(num * (len + 1)) == len + 1) {
			allS.push_back(num * (len + 1));
		}
		if (len < 17 && get_length(num * (len + 2)) == len + 2) {
			allS.push_back(num * (len + 2));
		}
		// printf ("%d -> %I64d\n", pointer, num);
		pointer++;
	}
	sort (allS.begin(), allS.end());
}

long long solve(long long C) {
	// range [0, C]
	if (C < 0) {
		return 0;
	}
	return upper_bound(allS.begin(), allS.end(), C) - allS.begin();
}

int main() {
	gen_all();

	int T;
	long long L, R;
	for (cin >> T; T; --T) {
		cin >> L >> R;
		cout << solve(R) - solve(L - 1) << endl;
	}

	return 0;
}