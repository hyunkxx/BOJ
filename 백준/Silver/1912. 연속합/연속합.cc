#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int count; cin >> count;
	for (int i = 1; i <= count; ++i)
		cin >> arr[i];

	int ans = arr[1];
	for (int i = 1; i <= count; ++i)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
};