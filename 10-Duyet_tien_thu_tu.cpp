#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define vi vector<ll,ll>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const ll maxN = 1e6 + 8;
const ll oo = 1e9 + 8;

ll n, a[maxN], height[maxN];

void PreOrder(ll i){
    if (i < n){
        cout << a[i] << ' ';
        PreOrder(2 * i + 1);
        PreOrder(2 * i + 2);
        height[i] = max(height[2*i+1], height[2*i+2]) + 1;
    }
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 0, n - 1) cin >> a[i];
    PreOrder(0);
    cout << "\nChieu cao cay = " << height[0];
}


