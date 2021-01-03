#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void)
{
	int N,s,k,i,j;
	string cake;
	
	queue<char> qcake;

	cin >> N;
	cin >> cake;

	s = k = 0;

	for (i = 0;i < N;i++)
	{
		qcake.push(cake[i]);

		if (qcake.back() == 's')
			s++;
		else
			k++;

		if (s > N / 4)
		{
			for (;qcake.front() != 's';)
			{
				qcake.pop();
				k--;
			}
			qcake.pop();
			s--;
		}
		else if (k > N / 4)
		{
			for (;qcake.front() != 'k';)
			{
				qcake.pop();
				s--;
			}
			qcake.pop();
			k--;
		}
		else if (s == N / 4 && k == N / 4)
		{
			break;
		}
	}
	

	int begin, end;

	end = i+1;

	if (end == N / 2)
		cout << 1 << endl << end;

	else
	{
		begin = end - N / 2;
		cout << 2 << endl << begin << " " << end;
	}

	system("pause>nul");
	return 0;
}