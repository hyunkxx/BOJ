#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

vector<int> list;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count; cin >> count;
    for (int i = 0; i < count; ++i)
    {
        int element; cin >> element;
        list.push_back(element);
    }

    sort(list.begin(), list.end());
    
    int prev = INT_MAX;
    int cur;

    pair<int*, int*> pivot;

    int* left  = &list[0];
    int* right = &list[list.size() - 1];

    while (left < right)
    {
        cur = *left + *right;

        if (abs(cur) < prev)
        {
            prev = abs(cur);
            pivot.first = left;
            pivot.second = right;

            if (cur == 0)
                break;
        }

        if(cur < 0)
            left++;
        else
            right--;
    }

    if(prev != INT_MAX)
        cout << *pivot.first << " " << *pivot.second;

    return 0;
}
