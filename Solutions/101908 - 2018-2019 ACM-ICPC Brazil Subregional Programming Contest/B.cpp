// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908B

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcountll(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

const int N = 102;

int dp[N][N];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	//	freopen("in.txt", "rt", stdin);
	//	freopen("out.txt", "wt", stdout);
#endif
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vi cur;
			for (int k = 1; i - k >= 0; k++)
				cur.pb(dp[i - k][j]);
			for (int k = 1; j - k >= 0; k++)
				cur.pb(dp[i][j - k]);
			for (int k = 1; i - k >= 0 && j - k >= 0; k++)
				cur.pb(dp[i - k][j - k]);
			UN(cur);
			int res = SZ(cur);
			for (int k = 0; k < SZ(cur); k++) {
				if (k != cur[k]) {
					res = k;
					break;
				}
			}
			if (i == j || i == 0 || j == 0) res = OO;
			dp[i][j] = res;
		}
	}
	int n, x, y, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == 0 || y == 0 || x == y) {
			puts("Y");
			return 0;
		}
		res ^= dp[x][y];
	}
	res ? puts("Y") : puts("N");
	return 0;
}