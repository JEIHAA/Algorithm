#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string letters;

    cin >> n;  
    cin >> letters;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int currentPos = 1; currentPos < n; ++currentPos) {
        for (int prevPos = 0; prevPos < currentPos; ++prevPos) {
            if ((letters[prevPos] == 'B' && letters[currentPos] == 'O') ||
                (letters[prevPos] == 'O' && letters[currentPos] == 'J') ||
                (letters[prevPos] == 'J' && letters[currentPos] == 'B')) {
                int cost = (currentPos - prevPos) * (currentPos - prevPos);
                if (dp[prevPos] != INT_MAX) {
                    dp[currentPos] = min(dp[currentPos], dp[prevPos] + cost);
                }
            }
        }
    }
    
    if (dp[n - 1] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dp[n - 1] << endl;
    }
}
