#include <iostream>
#include <string>
#include <vector>

using namespace std;
char map[102][102] = { 0 };
int visited[102][102] = { 0 };

void colorChangeNInit(int N)
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			visited[i + 1][j + 1] = 0;
			if (map[i + 1][j + 1] == 'G')
				map[i + 1][j + 1] = 'R';
		}
	}
}


void dfs(int x, int y, char c)
{
	if (visited[x][y] == 1)
		return;
	visited[x][y] = 1;
	pair<char, int> up = make_pair(map[x - 1][y], visited[x - 1][y]);
	pair<char, int> down = make_pair(map[x + 1][y], visited[x + 1][y]);
	pair<char, int> left = make_pair(map[x][y - 1], visited[x][y - 1]);
	pair<char, int> right = make_pair(map[x][y + 1], visited[x][y + 1]);
	if (up.first == c && up.second == 0)
		dfs(x - 1, y, c);
	if (down.first == c && down.second == 0)
		dfs(x + 1, y, c);
	if (left.first == c && left.second == 0)
		dfs(x, y - 1, c);
	if (right.first == c && right.second == 0)
		dfs(x, y + 1, c);
}

int main(void)
{
	int N;
	int count1, count2;
	string str;
	
	cin >> N;
	for (int i = 0; i < N;i++)
	{
		cin >> str;
		for (int j = 0;j < N;j++)
			map[i + 1][j + 1] = str[j];
	}

	count1 = count2 = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (map[i + 1][j + 1] != 0 && visited[i + 1][j + 1] == 0) {
				dfs(i + 1, j + 1, map[i + 1][j + 1]);
				count1++;
			}
		}
	}
	colorChangeNInit(N);
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (map[i + 1][j + 1] != 0 && visited[i + 1][j + 1] == 0) {
				dfs(i + 1, j + 1, map[i + 1][j + 1]);
				count2++;
			}
		}
	}
	cout << count1 << " " << count2;
	return 0;
}
