#include<bits/stdc++.h>
using namespace std;
const  int MAX = 10e9+7;
const int MOD = 10e9+7; 

int mod(int a, int b)
{
    return (a%b + b)%b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, long long> count;
    for(int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    long long result = 0;
    for(auto &p : count) {
        long long c = p.second;
        result += c * (c - 1) / 2;
    }

    cout << result << "\n";

    return 0;
}
