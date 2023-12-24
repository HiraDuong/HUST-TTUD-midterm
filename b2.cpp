#include <iostream>
#include <vector>

using namespace std;

const int MAX_SUM = 1e5 + 5;
vector<long long> dp(MAX_SUM, 0);

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s;
    cin >> s;

    if(s > MAX_SUM) {
        cout << -1 << "\n";
        return -1;
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = MAX_SUM; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]);
        }
    }

    long long result = 0;
    for(int i = s; i < MAX_SUM; i++) {
        result = (result + dp[i]);
    }

    cout << result << "\n";

    return 0;
}