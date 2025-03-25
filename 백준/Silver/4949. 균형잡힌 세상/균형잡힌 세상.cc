#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    stack<char> brackets;
    vector<string> lines;
    bool answer = true;
    
    while (true)
    {
        getline(cin, line);

        if (line == ".") break;
        
        while (!brackets.empty()) brackets.pop();
        answer = true;

        for (char ch : line)
        {
            if (ch == '(' || ch == '[')
            {
                brackets.push(ch);
            }
            else if (ch == ')' || ch == ']')
            {
                if (brackets.empty())
                {
                    answer = false;
                    break;
                }
                
                if (( brackets.top() == '(' && ch == ')' ) || ( brackets.top() == '[' && ch == ']' ))
                {
                    brackets.pop();
                }
                else
                {
                    answer = false;
                }
            }
        }

        if (answer && brackets.empty())
        {
            lines.emplace_back("yes");
        }
        else
        {
            lines.emplace_back("no");
        }
    }


    for (string answer : lines)
    {
        cout << answer << endl;
    }

}