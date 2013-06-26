#include <algorithm>
using namespace std;

const int MAXLEN = 20010;
int n, maxlcp;
int head[MAXLEN], b[MAXLEN], id[MAXLEN], rank[MAXLEN], nb[MAXLEN], next[MAXLEN], height[MAXLEN];
int s[MAXLEN];

bool cmp(const int &a, const int &b){
    return s[a] < s[b];
}

void suffixSort(){
	int i, j, k, h;
	for (i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, cmp);	
	for (i = 0; i < n; i++)
		if (i == 0 || s[id[i]] != s[id[i-1]]) b[id[i]] = i;
		else b[id[i]] = b[id[i-1]];
	for (h = 1; h < n; h <<= 1){
		for (i = 0; i < n; i++) head[i] = next[i] = -1;
		for (i = n - 1; i >= 0; i--) if (id[i]){
			j = id[i] - h; if (j < 0) j += n;
			next[j] = head[b[j]]; head[b[j]] = j;
		}
		j = n - h; next[j] = head[b[j]]; head[b[j]] = j;
		for (i = k = 0; i < n; i++) if (head[i] >= 0)
			for (j = head[i]; j >= 0; j = next[j]) id[k++] = j;
		for (i = 0; i < n; i++) if (i > 0 && id[i] + h < n && id[i-1] + h < n
			&& b[id[i]] == b[id[i-1]] && b[id[i] + h] == b[id[i-1]+h])
				nb[id[i]] = nb[id[i-1]]; else nb[id[i]] = i;
		for (i = 0; i < n; i++) b[i] = nb[i];
	}
}

void getHeight(){
	int i, j, h; 
	height[0] = 0;  maxlcp = 0;
	for (i = 0; i < n; i++) rank[id[i]] = i;
	for (h = 0, i = 0; i < n; i++) 
		if (rank[i] > 0){
			j = id[rank[i]-1];
			while (s[i+h] == s[j+h]) ++h;
			height[rank[i]] = h;
			maxlcp >?= h;
			if (h > 0) --h;	
		}	
}

bool init(){
	scanf("%d", &n); 
	if (n == 0) return false;
	int x, y; scanf("%d", &x);
	n--;
	for (int i = 0; i < n; i++){
		scanf("%d", &y);
		s[i] = y - x;
		x = y;	
	} 
	return true;
}

bool check(int l){
	int tmin = n - id[0], tmax = n - id[0];
	for (int i = 1; i < n; i++)
		if (height[i] < l){
			tmin = tmax = n - id[i];
		}
		else{
			tmax >?= n - id[i];
			tmin <?= n - id[i];
			if (tmax - tmin > l) return true;
		}
	return false;
}

void calculate(){
	//printf("%d\n", maxlcp);
	int low = 0, high = maxlcp + 1 ,mid;
	while (low + 1 < high){
		mid = (low + high) / 2;
		if (check(mid)) low = mid; else high = mid;
	}
	printf("%d\n", low>3?low+1:0);
}

void solve(){
	suffixSort(); 
	getHeight();
	calculate();
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while (init()) solve();
	return 0;	
}
