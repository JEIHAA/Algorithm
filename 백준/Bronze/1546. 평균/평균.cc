#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, score, maxScore=0;
    double total = 0, avg = 0;
    vector<int> scoreArr;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> score;
        scoreArr.push_back(score);
        if (maxScore < score)
        {
            maxScore = score;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        total += (float)scoreArr[i] / maxScore * 100;
    }
    avg = total / n;
    cout << avg;
}