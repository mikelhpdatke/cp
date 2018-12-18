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

void InsertionSort(){
    ll j, tmp;
    FOR(i, 2, n){
        tmp = a[i];
        j = i - 1;
        while (j > 0 && tmp < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}

int main(){
    cout << "N = ";
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    InsertionSort();
    FOR(i, 1, n) cout << a[i] << ' ';
}

