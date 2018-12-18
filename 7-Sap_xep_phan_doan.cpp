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

void QuickSort(ll L, ll H){
    ll x, i, j;
    if (L >= H) return;
    x = a[(L+H)/2];
    i = L;
    j = H;
    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            if (i < j) swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    QuickSort(L, j);
    QuickSort(i, H);
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    QuickSort(1, n);
    FOR(i, 1, n) cout << a[i] << ' ';
}


