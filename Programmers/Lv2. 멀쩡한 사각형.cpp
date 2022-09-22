using namespace std;

long long solution(int w,int h) {
    int n = w;
    int m = h;
    int k;
    while (m!=0)
    {
        k = n % m;
        n = m;
        m = k;
    }
    long long W = w;
    long long H = h;
    long long ans = (w + h) - n;
    return W * H - ans;
}
