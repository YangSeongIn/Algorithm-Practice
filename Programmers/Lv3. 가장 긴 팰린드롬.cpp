#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string s)
{
    int cnt = 0;
    if (s.length() == 1) return 1;

    for (int i = s.length() - 1; i >= 1; i--)
    {
        for (int k = 0; k + i < s.length(); k++)
        {
            for (int j = 0; 2 * j < i; j++)
            {
                if (s[k + j] != s[k + i - j] || 2 * j == i) break;
                cnt++;
            }
            if (cnt == (int)ceil((double)i / 2)) return i + 1;
            else cnt = 0;
        }
    }
    return 1;
}
