#include <iostream>
#include <string>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (getline(cin, str)) {
        cout << str << endl;
    }

    return 0;
}
