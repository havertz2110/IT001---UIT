#include <bits/stdc++.h>
using namespace std;

vector<long long> cnt(10);
vector<string> a;

long long Pow[13];
void calcPow(){
    long long tmp = 1;
    for (long long i=0;i<13;i++){
        Pow[i] = tmp;
        tmp*=10;
    }
}

void calc(string x){
    if (cnt[x[0] - '0'] < 1e12) cnt[x[0] - '0'] += 1e12; 
    for (long long i=0;i < x.length(); i++){
        cnt[x[i] - '0'] += Pow[x.length() - i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    calcPow();
    long long n;
    cin >> n;
    a.resize(n);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }

    for (long long i=0;i<n;i++){
        calc(a[i]);
    }

    sort(cnt.begin(),cnt.end());
    long long ans=0;
    for (long long i=0;i<10;i++){
        if (cnt[i] > 1e12) cnt[i] -= 1e12;
        ans += cnt[i]*i;
    }

    cout << ans;
    return 0;
}
