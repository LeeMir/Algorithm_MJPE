#include <string>
#include <vector>
#include <iostream>

using namespace std;

string str = "";

void recur(int n)
{
    int num = n;
    if (num == 1)
        str += "1";
    else if (num == 2)
        str += "2";
    else if (num == 3)
        str += "4";
    else if (num % 3 == 0)
    {
        str += "4";
        recur(n / 3 - 1);
    }
    else if (num % 3 == 1)
    {
        str += "1";
        recur(n / 3);
    }
    else if (num % 3 == 2)
    {
        str += "2";
        recur(n / 3);
    }
}

string solution(int n) {
    string answer = "";
    recur(n);
    reverse(str.begin(), str.end());
    answer = str;
    return answer;
}

int main(void)
{
    int n;
    cin >> n;
    string answer = solution(n);
    cout << answer;
    return 0;
}