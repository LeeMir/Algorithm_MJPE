#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string cake;
	int n;
	cin >> n;
	cin >> cake;
	int count_s = 0;
	int count_k = 0;
	int start = 0;
	
	for(start = 0;start < n/2;++start){
		if (cake[start] == 's')
			++count_s;
		else
			++count_k;
	}
	if (count_s == count_k)
		cout << 1 << endl << n/2<<endl;
	else{
		cout << 2 << endl;
		for (int end=n/2;end<n;++end){
			if (cake[end] == 's')
				++count_s;
			else
				++count_k;
			if(cake[end - n/2]== 's')
				--count_s;
			else
				--count_k;
			if (count_s == count_k){
				cout << end - n / 2 + 1 << " " << end + 1<<endl;
				break;
			}
		}
	}
	return 0;
}
