#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    string str = "";
    for (int i = 0; i < dartResult.length(); i++)
    {
        if ('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            str += dartResult[i];
        }
        else if (dartResult[i] == 'S')
        {
            v.push_back(stoi(str));
            str = "";
        }         
        else if (dartResult[i] == 'D')
        {
            v.push_back(pow(stoi(str), 2));
            str = "";
        }        
        else if (dartResult[i] == 'T')
        {
            v.push_back(pow(stoi(str), 3));
            str = "";
        }  
        else if (dartResult[i] == '*')
        {
            if (i != 2) 
                v[v.size() - 2] *= 2;
            v[v.size() - 1] *= 2;
        }
        else if (dartResult[i] == '#')
            v[v.size() - 1] *= -1;
    }
    for (int i = 0; i < 3; i++)
        answer += v[i];
    return answer;
}
