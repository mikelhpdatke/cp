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

void SelectionSort(){
    ll jmin;
    FOR(i, 1, n-1){
        jmin = i;
        FOR(j, i + 1, n) if (a[j] < a[jmin]) jmin = j;
        if (jmin != i) swap(a[i], a[jmin]);
    }
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    SelectionSort();
    FOR(i, 1, n) cout << a[i] << ' ';
}
