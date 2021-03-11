#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool visited[52][52];
char map[52][52];
int N, M;

struct Data {
	int x;
	int y;
	int dis;
};

void initmap()
{
	for (int i = 0;i < 52;i++)
		for (int j = 0;j < 52;j++)
			map[i][j] = 'W';
}

void initvisited()
{
	for (int i = 0;i < 52;i++)
		for (int j = 0;j < 52;j++)
			visited[i][j] = false;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int bfs(int i, int j)
{
	initvisited();
	queue<Data> q;
	Data data;
	q.push({ i,j,0 });
	int x,y,dis,maxdis = 0;
	while (1)
	{
		if (q.empty())
			break;
		data = q.front();
		q.pop();
		x = data.x;
		y = data.y;
		dis = data.dis;
		maxdis = max(dis, maxdis);
		if (visited[x][y] == true)
			continue;
		visited[x][y] = true;
		if (map[x + 1][y] == 'L'&&visited[x+1][y]==false)
			q.push({ x + 1,y,dis + 1 });
		if (map[x - 1][y] == 'L'&&visited[x - 1][y] ==false)
			q.push({ x - 1,y,dis + 1 });
		if (map[x][y+1] == 'L'&&visited[x][y+1] == false)
			q.push({ x,y+1,dis + 1 });
		if (map[x][y-1] == 'L'&&visited[x][y-1] == false)
			q.push({ x,y-1,dis + 1 });
	}
	return maxdis;
}

void printmap()
{
	for (int i = 0;i <= N+1;i++) {
		for (int j = 0;j <= M+1;j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(void)
{
	string str;
	int dist, maxdist = 0;
	cin >> N >> M;

	initmap();

	for (int i = 1;i <= N;i++)
	{
		cin >> str;
		for (int j = 1;j <= M;j++)
			map[i][j] = str[j-1];
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= M;j++)
		{
			if (map[i][j] == 'L')
			{
				dist = bfs(i, j);
				maxdist = max(dist, maxdist);
			}
		}
	}
	cout << maxdist;
	return 0;
}