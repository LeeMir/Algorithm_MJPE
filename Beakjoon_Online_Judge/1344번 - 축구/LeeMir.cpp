#include <iostream>

using namespace std;

double comb(int a, int n) // aCn 계산
{
	int i;
	double ans = 1;

	if (n > a / 2)
		n = a - n;

	int tempa = a;
	int tempb = n;
	for (i = 0;i < n;i++)
	{
		ans *= tempa;
		ans /= tempb;
		tempb -= 1;
		tempa -= 1;
	}
	return ans;
}

double mpow(float a, int b) // a의 b제곱
{
	double ans = 1;
	int i;
	for (i = 0;i < b;i++)
		ans *= a;
	return ans;
}

double scoreCal(int num, int score) // 한번에 p의 확률로 골을 넣을 때 총 score만큼의 골을 넣을 확률
{
	double p = num;
	p /= 100;
	int n = score;
	double ans = mpow(p, n) * mpow(1 - p, 18 - n) * comb(18, n);
	return ans;
}

int main(void)
{
	int A, B;
	int sosu[12] = {0,1,4,6,8,9,10,12,14,15,16,18};

	cin >> A;
	cin >> B;

	double scoreA, scoreB;
	scoreA = scoreB = 0;
	int i;
	for (i = 0;i < 12;i++)
	{
		scoreA += scoreCal(A, sosu[i]);
		scoreB += scoreCal(B, sosu[i]);
	}

	double ans = 1 - scoreA * scoreB;

	cout << ans;

	return 0;
}
