#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> ans[N];

int main()
{
	int n, d, c;
	scanf("%d%d%d", &n, &d, &c);
	if (d == 0)
	{
		if (c != n)
		{
			puts("No");
			return 0;
		}
		puts("Yes");
		return 0;
	}
	if (d == 1)
	{
		if (n & 1)
		{
			puts("No");
			return 0;
		}
		if (c != n / 2)
		{
			puts("No");
			return 0;
		}
		puts("Yes");
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", i + ((i & 1) ? 1 : -1));
		}
		return 0;
	}
	if (c * (d + 1) > n)
	{
		puts("No");
		return 0;
	}
	if ((n & 1) && (d & 1))
	{
		puts("No");
		return 0;
	}

	int nu = c - 1;
	int po = 1;
	while (nu--)
	{
		for (int i = po; i <= po + d; ++i)
		{
			for (int j = po; j <= po + d; ++j)
			{
				if (i != j)
				{
					ans[i].push_back(j);
				}
			}
		}
		po += d + 1;
	}
	int res = n - po + 1;
	if ((res & 1) && (d & 1))
	{
		puts("No");
		return 0;
	}

	if (d & 1)
	{
		for (int j = po; j <= n - res / 2; ++j)
		{
			int xx = (j - po + res / 2) % res + po;
			ans[j].push_back(xx);
			ans[xx].push_back(j);
		}
		d--;
	}
	for (int i = 2; i <= d; i += 2)
	{
		for (int j = po; j <= n; ++j)
		{
			int xx = (j - po + i / 2) % res + po;
			ans[j].push_back(xx);
			ans[xx].push_back(j);
		}
	}

	puts("Yes");
	for (int i = 1; i <= n; ++i)
	{
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); ++j)
		{
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
}