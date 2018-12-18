#include<bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }


#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())

using namespace std;

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }

const int INF = 1000000007;
const int maxn = 1100;
typedef pair<int, int> ii;
int n, m;
int a[maxn][maxn];
vector<ii> ans;
bool check[maxn];
void dfs(int u){
    check[u] = 1;
    FOR(v, 1, n) if (a[u][v] == 1 && check[v] == 0){
        ans.push_back(ii(u, v));
        dfs(v);
    }
}

int main()
{
    int u, v;
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> u>>v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    dfs(1);
    if (ans.size() < n - 1) {
        cout <<" Khong tim duoc cay khung !!";
        return 0;
    }
    cout << ans.size() << endl;
    FOR(i, 0, ans.size() - 1){
        cout << ans[i].first <<" "<<ans[i].second << endl;
    }
}
