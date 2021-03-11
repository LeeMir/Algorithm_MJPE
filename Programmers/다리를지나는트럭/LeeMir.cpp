#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Data {
    int wei;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int roadon = 0;
    vector<int> truck = truck_weights;
    queue<Data> q;
    for (int i = 0; i < bridge_length; i++)
        q.push({ 0 });
    while (1)
    {
        answer++;
        roadon -= q.front().wei;
        q.pop();
        if (truck.empty() && roadon == 0)
            break;
        if (!truck.empty() && roadon + truck[0] <= weight)
        {
            q.push({ truck[0] });
            roadon += truck[0];
            truck.erase(truck.begin());
        }
        else
            q.push({ 0 });
    }
    return answer;
}
