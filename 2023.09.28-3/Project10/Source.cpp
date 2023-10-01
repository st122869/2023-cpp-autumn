#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int cnt = 1;
	int flag = 0;
	int ans = 0;

	std::cin >> n;

	while (cnt <= n)
	{
		flag = 0;
		while (flag < cnt)
		{
			if (ans < n)
			{
				std::cout << cnt << " ";
				flag++;
				ans++;
			}
		}
		cnt++;
	}
	return 0;
}