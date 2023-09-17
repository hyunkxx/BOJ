#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int result = 0;
    int length; cin >> length;

    while (length > 0)
    {
        if (length % 2 == 1)
            result++;

        length /= 2;
    }

    cout << result;

    return 0;
}