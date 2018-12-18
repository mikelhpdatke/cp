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
void bfs(){
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        //cout <<u<<" ";
        FOR(v, 1, n) if (a[u][v] == 1 && check[v] == 0){
            check[v] = 1;
            q.push(v);
            ans.push_back(ii(u, v));
        }
    }
    if (ans.size() < n - 1) {
        cout <<" Khong tim duoc cay khung !!";
        return;
    }
    cout << ans.size() << endl;
    FOR(i, 0, ans.size() - 1){
        cout << ans[i].first <<" "<<ans[i].second << endl;
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
    bfs();
}
