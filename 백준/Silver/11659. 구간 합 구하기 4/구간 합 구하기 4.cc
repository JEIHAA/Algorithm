#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, I, J;
    vector<int> S, answer;
    S.push_back(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        S.push_back(S.back() + x);
    }

    for (int i = 1; i <= M; ++i)
    {
        cin >> I >> J;
        answer.push_back(S[J] - S[I - 1]);
    }

    for (int sum: answer)
    {
        cout << sum << "\n";
    }
}