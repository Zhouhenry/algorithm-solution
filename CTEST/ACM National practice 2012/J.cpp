// Created : 4:39:36 PM Oct 21, 2012
// Task    : J

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) for (typeof(a) i = (a); i >= (b); i--)
#define REP(i, a) for (typeof(a) i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define DEBUG(x) cout << #x << " = "; cout << x << endl; // thank RR for that
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4 * atan(1);   // d / ld ?
const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

int first[3], second[3];
int hv[][3] = {	{0, 1, 2}, {0, 2, 1},
				{1, 2, 0}, {1, 0, 2},
				{2, 1, 0}, {2, 0, 1}
			};

inline void init() {
	ntest = INF;
}

inline bool check(int a[], int b[]){
	int cnt = 0;
	REP(i, 3) cnt += (a[i] > b[i]);
	return cnt >= 2;
}

inline bool isSureWin(int second[]){
	int per[3];
	REP(i, 6){
		REP(j, 3){
			per[j] = second[hv[i][j]];
		}

		if (!check(per, first)) return false;
	}
	return true;
}


inline void run() {
		scanf("%d %d %d %d %d", &first[0], &first[1], &first[2], &second[0], &second[1]);
		if (first[0] == 0) return stop();

		bool found = false;
		for (second[2] = 1 ; second[2] <= 52; second[2]++){
			bool trung = false;
			REP(i, 3) if (first[i] == second[2]) trung = true;
			REP(i, 2) if (second[i] == second[2]) trung = true;
			if (trung) continue;

			if (isSureWin(second)){
				found = true;
				break;
			}
		}

		if (!found)	second[2] = -1;
		cout << second[2] << endl;
}
