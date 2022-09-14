#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.length(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] + n - 'A') % 26;
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] + n - 'a') % 26;
        }
    }
    return s;
}
