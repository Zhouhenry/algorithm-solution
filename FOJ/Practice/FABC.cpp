/*
* Who  : timxad
* Task : ABC_HACK
* Date : Jun 10, 2013
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define Sort(a) sort(all(a))
#define Unique(a) Sort(a); a.resize(unique(all(a) - a.begin()))

#define For(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define Ford(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define Fit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define nl puts("") // new line
#define sp printf(" ") // space
#define ok puts("ok")
#define show(x) cout << x << endl
#define dbg(x) cout << #x << " = " << x << endl

typedef pair<int, int> II;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
string result[] = {"A", "AB", "ABA", "ABAC", "ABACA", "ABACAB", "ABACABA", "ABACABCA", "ABACABCBA", "ABACABCBAB", "ABACBABCABA", "ABACABCACBAB", "ABACABCBABCAB", "ABACABCBABCABA", "ABACBABCABACBAB", "ABACABCACBABCABA", "ABACABCBABCABACAB", "ABACABCBABCABACBAB", "ABACABCACBABCABACAB", "ABACABCACBABCABACBAB", "ABACABCBABCABACABCBAB", "ABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBAB", "ABACABCBABCABACABCBACABA", "ABACABCBABCABACBABCBACABA", "ABACBABCABACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABA", "ABACABCBABCABACABCBACABACBAB", "ABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBABCABACBA", "ABACABCACBABCABACABCBABCABACBAB", "ABACABCBABCABACABCBACABACBABCABA", "ABACABCBABCABACBABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCAB", "ABACABCACBABCABACBABCBACABACBABCABA", "ABACABCBABCABACBABCBACABACBABCABACAB", "ABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABA", "ABACABCBABCABACABCBACABACBABCABACABCBAB", "ABACABCBABCABACBABCBACABACBABCABACABCBAB", "ABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCBABCABACABCBACABACBABCABACABCBABCABA", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBAB", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACAB", "ABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCAB", "ABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBAB", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABA", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABA", "ABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBA", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCAB", "ABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCACBAB", "ABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACBA", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBAB", "ABACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBAB", "ABACABCBABCABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACBA", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACAB", "ABACABCACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBACABACBABCABA", "ABACABCBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBACABACBABCBACABA", "ABACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBAB", "ABACABCBABCABACABCACBABCABACABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCBABCABACABCBACABACBABCBACABCBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACBABCABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABA", "ABACABCBABCABACABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBABCABACBA", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBAB", "ABACABCBABCABACABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABACABCBACABACBABCABA", "ABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCACBACABACBABCABACABCBABCABACBABCBACABACBABCABA", "ABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBABCABACBA", "ABACBABCABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABACBAB", "ABACABCACBABCABACABCBABCABACBABCBACABACBABCABACABCACBABCABACBABCBACABACBABCABACABCBABCABACBABCBACABA"};
int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int n;
	scanf("%d", &n);
	cout << result[n-1];

}

