#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    vector<int> nums;
    string number; cin >> number;

    for (size_t i = 0; i < number.size(); ++i)
    {
        nums.push_back(number[i] - '0');
        sum += number[i] - '0';
    }

    sort(nums.begin(), nums.end(), greater<>());
    
    if (sum % 3 == 0 && nums[nums.size() - 1] == 0)
    {
        for (auto element : nums)
            cout << element;
    }
    else
        cout << -1;

    return 0;
}