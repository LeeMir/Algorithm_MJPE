#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool map[1002][1002] = { 0 };
bool visited[1002][1002][2] = { 0 };

struct Data {
	int x;
	int y;
	bool bomb;
	int length;
};

void init(){
	for (int i = 0;i < 1002;i++)
		for (int j = 0;j < 1002;j++)
			map[i][j] = 1;
}

int main(void)
{
	int N, M, x,y, length,sw = 0;
	bool bomb;
	string str;
	queue<Data> q;
	Data data;
	cin >> N >> M;
	init();
	for (int i = 0;i < N;i++)
	{
		cin >> str;
		for (int j = 0;j < M;j++)
			map[i+1][j+1] = str[j] - '0';
	}
	data = { 1,1,0,1 };
	q.push(data);
	while (1)
	{
		if (q.empty()) {
			sw = 1;
			break;
		}
		data = q.front();
		q.pop();
		x = data.x;
		y = data.y;
		bomb = data.bomb;
		length = data.length;
		if (x == N && y == M) {
			break;
		}
		if (visited[x][y][bomb] == 1)
			continue;
		visited[x][y][bomb] = 1;
		if (map[x - 1][y] != 1) {
			data = { x - 1,y,bomb,length + 1 };
			q.push(data);
		}
		if (map[x + 1][y] != 1) {
			data = { x + 1,y,bomb,length + 1 };
			q.push(data);
		}
		if (map[x][y-1] != 1) {
			data = { x,y-1,bomb,length + 1 };
			q.push(data);
		}
		if (map[x][y+1] != 1) {
			data = { x,y+1,bomb,length + 1 };
			q.push(data);
		}
		if(bomb==0)
		{
			if (map[x - 1][y] == 1&&x>1) {
				data = { x - 1,y,1,length + 1 };
				q.push(data);
			}
			if (map[x + 1][y] == 1&&x<N+1) {
				data = { x + 1,y,1,length + 1 };
				q.push(data);
			}
			if (map[x][y - 1] == 1&&y>1) {
				data = { x,y-1,1,length + 1 };
				q.push(data);
			}
			if (map[x][y + 1] == 1&&y<M+1) {
				data = { x,y+1,1,length + 1 };
				q.push(data);
			}
		}
	}
	if (sw == 1)
		cout << -1;
	else
		cout << data.length;
	return 0;
}

