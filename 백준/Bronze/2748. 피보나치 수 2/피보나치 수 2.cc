#include <iostream>

using namespace std;

long long cache[91];

long long Fibo(long long num)
{
    if (cache[num] != -1)
        return cache[num];

    cache[num] = Fibo(num - 2) + Fibo(num - 1);

    return cache[num];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill_n(cache, 91, -1);

    cache[0] = 0;
    cache[1] = 1;

    int n; cin >> n;
    cout << Fibo(n);

    return 0;
}