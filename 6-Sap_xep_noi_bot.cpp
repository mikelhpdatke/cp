#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define vi vector<ll,ll>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const ll maxN = 1e6 + 8;
const ll oo = 1e9 + 8;

ll n, a[maxN];

void BubbleSort(){
    FOR(i, 2, n)
        FORD(j, n, i)
            if (a[j] < a[j-1]) swap(a[j], a[j-1]);
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    BubbleSort();
    FOR(i, 1, n) cout << a[i] << ' ';
}

