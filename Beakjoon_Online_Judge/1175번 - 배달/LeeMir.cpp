#include <iostream>
#include <string>
#include <queue>

using namespace std;

char map[52][52];
bool visited[52][52][4][2][2] = { 0 };
void initmap()
{
	for (int i = 0;i < 52;i++)
		for (int j = 0;j < 52;j++)
			map[i][j] = '#';
}

void ClearQueue(queue<vector<int>> &someQueue)
{
	queue<vector<int>> empty;
	swap(someQueue, empty);
}

int main(void)
{
	int N, M, i,j,sw, x, y, length, dir, c, d,cd;
	cin >> N >> M;
	string str;

	queue<vector<int>> q;

	vector<int> data = { 0, 0, 0, 0, 0, 0 }; // x,y,length, dir, c, d
	initmap();
	sw = cd = 0;
	for (i = 0;i < N;i++)
	{
		cin >> str;
		for (j = 0;j < M;j++) {
			if (str[j] == 'C'&&cd==0) {
				str[j] = 'D';
				cd = 1;
			}
			map[i + 1][j + 1] = str[j];
			if (str[j] == 'S') {
				data[0] = i + 1;
				data[1] = j + 1;
			}
			
		}
	}
	q.push(data);
	while (1)
	{
		if (q.empty()) {
			sw = -1;
			break;
		}

		else {
			data = q.front();
			q.pop();
			x = data[0];
			y = data[1];
			length = data[2];
			dir = data[3];
			c = data[4];
			d = data[5];
			
			
			if (visited[x][y][dir][c][d] == 1)
				continue;
			visited[x][y][dir][c][d] = 1;
			//cout << x << " " << y << " " << dir << " " << c << " " << d << endl;

			
			if (map[x - 1][y] != '#'&&dir!=1)
			{
				data[0] = x - 1;
				data[1] = y;
				data[2] = length+1;
				data[3] = 1;
				if(map[x-1][y]=='C')
					data[4] = 1;
				if (map[x - 1][y] == 'D')
					data[5] = 1;
				q.push(data);
				if (data[4] == 1 && data[5] == 1)
					break;
				data[4] = c;
				data[5] = d;
				//cout << "push : " << data[0] << " " << data[1] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
			}
			if (map[x + 1][y] != '#'&&dir!=2)
			{
				data[0] = x + 1;
				data[1] = y;
				data[2] = length+1;
				data[3] = 2;
				if (map[x + 1][y] == 'C')
					data[4] = 1;
				if (map[x + 1][y] == 'D')
					data[5] = 1;
				q.push(data);
				if (data[4] == 1 && data[5] == 1)
					break;
				data[4] = c;
				data[5] = d;
				//cout << "push : " << data[0] << " " << data[1] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
			}
			if (map[x][y - 1] != '#'&&dir!=3)
			{
				data[0] = x;
				data[1] = y - 1;
				data[2] = length + 1;
				data[3] = 3;
				if (map[x][y-1] == 'C')
					data[4] = 1;
				if (map[x][y-1] == 'D')
					data[5] = 1;
				q.push(data);
				if (data[4] == 1 && data[5] == 1)
					break;
				data[4] = c;
				data[5] = d;
				//cout << "push : " << data[0] << " " << data[1] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
			}
			if (map[x][y + 1] != '#'&&dir!=4)
			{
				data[0] = x;
				data[1] = y + 1;
				data[2] = length + 1;
				data[3] = 4;
				if (map[x][y+1] == 'C')
					data[4] = 1;
				if (map[x][y+1] == 'D')
					data[5] = 1;
				q.push(data);
				if (data[4] == 1 && data[5] == 1)
					break;
				data[4] = c;
				data[5] = d;
				//cout << "push : " << data[0] << " " << data[1] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
			}
		}
	}
	if (sw == -1)
		cout << -1;
	else
		cout << data[2];
	return 0;
}
