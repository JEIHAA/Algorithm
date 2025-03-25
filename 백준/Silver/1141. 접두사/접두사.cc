#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int wordNum, wordCnt=0;
    string word;
    vector<string> words;

    cin >> wordNum;

    for (int i = 0; i < wordNum; ++i)
    {
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.size() < b.size(); // 길이가 짧은 순으로 비교 기준 정의
        });

   
    for(int i = 0; i < words.size(); ++i)
    {
        for (int j = i+1; j < words.size(); ++j)
        {
            if (words[j].find(words[i]) == 0)
            {
                words.erase(words.begin()+i);
                --i;
                break;
            }
        }
    }

    cout << words.size();
}