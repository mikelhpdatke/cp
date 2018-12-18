#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define vi vector<ll,ll>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const ll maxM = 1e6 + 8;
const ll maxN = 1e6 + 8;

pi e[maxM];
ll n, m;

void BFS(){
    queue<ll> q;
    ll u;
    bool avail[maxN];
    memset(avail, true, sizeof avail);
    avail[1] = false;
    q.push(1);
    do{
        u = q.front();
        cout << u << ' ';
        q.pop();
        FOR(i, 1, 2 * m) if (e[i].first == u && avail[e[i].second]){
            avail[e[i].second] = false;
            q.push(e[i].second);
        }
    } while (!q.empty());
}

int main(){
    cout << "N, M = ";
    cin >> n >> m;
    ll d, c;
    FOR(i, 1, m){
        cin >> d >> c;
        e[i] = make_pair(d, c);
        e[m + i] = make_pair(c, d);
    }
    BFS();
}


