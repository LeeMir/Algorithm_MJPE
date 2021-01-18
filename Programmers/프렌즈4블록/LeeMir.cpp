#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	
	vector< vector<char> > vvboard(n,vector<char>(m,'1'));
	vector< vector<char> > vvboard2(n, vector<char>(m,'2'));

	int sw = 0;

	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			vvboard[j][i] = board[i][j];
		}
	}
	vvboard2 = vvboard;

	while (1)
	{
		/* ���� ���� */
		for (int i = 0;i < n - 1;i++)
		{
			for (int j = 0;j < m - 1;j++)
			{
				char ch = vvboard[i][j];
				if (vvboard[i][j] == ' ')
					continue;
				else
				{
					if (ch == vvboard[i + 1][j] && ch == vvboard[i][j + 1] && ch == vvboard[i + 1][j + 1])
					{
						vvboard2[i][j] = ' ';
						vvboard2[i + 1][j] = ' ';
						vvboard2[i][j + 1] = ' ';
						vvboard2[i + 1][j + 1] = ' ';
						sw = 1;
					}
				}
			}
		}

		if (sw == 0)
			break;

		/* ���� ���� */
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (vvboard2[i][j] == ' ')
				{
					vvboard2[i].erase(vvboard2[i].begin() + j);
					vvboard2[i].insert(vvboard2[i].begin(), ' ');
				}
			}
		}

		vvboard = vvboard2;
		sw = 0;
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (vvboard2[i][j] == ' ')
			{
				answer++;
			}
		}
	}

	return answer;
}

int main(void)
{
	int answer = solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" });
	cout << answer;
	system("pause>nul");
	return 0;
}