#include <string>
#include <vector>

using namespace std;

int makeLcm(int a, int b)
{
    int at(a), bt(b);
    int k = 0;
    while (b != 0)
    {
        k = a % b;
        a = b;
        b = k;
    }
    a = at * bt / a;
    return a;
}

int solution(vector<int> arr) {
    vector<int> tmp;
    int t = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        t = makeLcm(t, arr[i]);
    }

    return t;
}
