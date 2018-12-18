#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define vi vector<ll,ll>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const ll maxN = 1e6 + 8;
const ll oo = 1e9 + 8;

ll n, a[maxN], k;

ll BinarySearch(ll k){
    ll i, j, mid;
    i = 1;
    j = n;
    while (i <= j){
        mid = (i + j) / 2;
        if (a[mid] == k) return mid;
        if (a[mid] < k) i = mid + 1;
        else j = mid - 1;
    }
    return -1;
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cout << "K = ";
    cin >> k;
    ll r = BinarySearch(k);
    if (r > 0) cout << r; else cout << "Khong tim thay!";
}



