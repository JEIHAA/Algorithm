#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, num;

    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> m;
    vector<int> result(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> num;

        result[i] = binary_search(cards.begin(), cards.end(), num) ? 1 : 0;
    }

    for (int i = 0; i < m; ++i)
    {
        if (i < m - 1) cout << result[i] << " ";
        else cout << result[i];
    }
}


