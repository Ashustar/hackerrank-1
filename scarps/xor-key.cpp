// Rain Dreamer MODEL
// iSea @ 2014-07-28 00:04
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

const int MAXN = 100000 + 10;
const int MAXH = 15;

struct persist_trie {
	struct node {
		node *l, *r;
		int cnt;

		node() {
			cnt = 0;
			l = r = NULL;
		}
	};

	node* root[MAXN];

	void init() {
		root[0] = new node;
	}
	void release(int n) {
		repf (i, 0, n) {
			release_node(root[i]);
		}
	}
	void release_node(node* head) {
		if (!head) return ;
		release_node(head->l);
		release_node(head->r);
		// delete head;
		head = NULL;
	}
	void add_new_root_from_prev(int prev_root, int val) {
		root[prev_root + 1] = new node;
		node* cur_node = root[prev_root + 1];
		node* prev_node = root[prev_root];
		rep (i, MAXH) {
			if ((val >> (MAXH - 1 - i)) & 1) {  // move right
				node* new_child = new node;
				// links
				cur_node->r = new_child;
				cur_node->l = prev_node? prev_node->l : NULL;
				// move next
				cur_node = cur_node->r;
				prev_node = prev_node? prev_node->r : NULL;
			} else {  // move left
				node* new_child = new node;
				// links
				cur_node->l = new_child;
				cur_node->r = prev_node? prev_node->r : NULL;
				// move next
				cur_node = cur_node->l;
				prev_node = prev_node? prev_node->l : NULL;
			}
			cur_node->cnt = (prev_node? prev_node->cnt : 0) + 1;
		}
	}
	int get_cnt_in_interval(node* l_root, node* r_root, bool x) {
		// check if cnt difference between r_root and l_root large than 0
		if (x) { // right
			int ret = r_root && r_root->r? r_root->r->cnt : 0;
			ret -= l_root && l_root->r? l_root->r->cnt : 0;
			return ret;
		} else { // left
			int ret = r_root && r_root->l? r_root->l->cnt : 0;
			ret -= l_root && l_root->l? l_root->l->cnt : 0;
			return ret;
		}
	}
	int query_maximum_xor(int l, int r, int val) {
		// query max (x[l...r] XOR val)
		node *left_root = root[l - 1], *right_root = root[r];
		int res = 0;
		rep (i, MAXH) {
			bool bit = ((val >> (MAXH - 1 - i)) & 1);
			bool flag = get_cnt_in_interval(left_root, right_root, !bit) > 0;
			res = (res << 1) | flag;
			if (flag ^ bit) {  // right
				left_root = left_root? left_root->r : NULL;
				right_root = right_root? right_root->r : NULL;
			} else {  // left
				left_root = left_root? left_root->l : NULL;
				right_root = right_root? right_root->l : NULL;
			}
		}
		return res;
	}
};

persist_trie tree;

int main() {
	repcase {
		int n, q;
		scanf ("%d%d", &n, &q);
		tree.init();
		rep (i, n) {
			int val;
			scanf ("%d", &val);
			tree.add_new_root_from_prev(i, val);
		}
		rep (i, q) {
			int X, u, v;
			scanf ("%d%d%d", &X, &u, &v);
			printf ("%d\n", tree.query_maximum_xor(u, v, X));
		}
		tree.release(n);
	}
	return 0;
}