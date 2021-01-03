#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int row_n;
int cal_n;
vector<vector<int>> all_cases;

//가능한 모든 조합 생성
void combination(int n = 0, vector<int> temp = {}) {
	for (int i = n;i < cal_n;i++) {
		temp.push_back(i);
		all_cases.push_back(temp);
		combination(i+1,temp);
		temp.pop_back();
	}
}
bool cmp(vector<int> first, vector<int> second) {
	if (first.size() == second.size()) {
		for (int i = 0;i < first.size();i++) {
			if (first[i] == second[i])
				continue;
			else if (first[i] > second[i])
				return false; //second가 먼저 
			else
				return true; //first가 먼저
		}
	}
	else if (first.size() > second.size())
		return false; //second가 먼저 
	else
		return true; //first가 먼저
	
}
bool is_candidate(vector<int> columns, vector<vector<string>> relation) {
	vector<string> sets;
	for (int i = 0;i < row_n;i++) {
		string temp;
		for (int j = 0;j < columns.size();j++) {
			temp += relation[i][columns[j]] + " ";
		}
		sets.push_back(temp);
	}
	sort(sets.begin(), sets.end());
	sets.erase(unique(sets.begin(), sets.end()), sets.end());
	if (sets.size() == row_n)
		return true;
	return false;


}
void del_cases(vector<int> candidate_key) {
	vector<int> erase_index;
	int count = 0;
	for (int i = 0;i < all_cases.size();i++) {
		bool flag = true;
		for (int j = 0;j < candidate_key.size();j++) {
			vector<int>::iterator iter;
			iter = find(all_cases[i].begin(), all_cases[i].end(), candidate_key[j]);
			if (iter == all_cases[i].end())
				flag = false;
		}
		if (flag)
			erase_index.push_back(i);
	}
	for (int i = 0;i < erase_index.size();i++) {
		int e = erase_index[i] - count;
		all_cases.erase(all_cases.begin() + e);
		count++;
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	cal_n = relation[0].size();
	row_n = relation.size();
	combination(); // 모든 경우의수 생성 (all_cases)
	sort(all_cases.begin(), all_cases.end(), cmp);// all_cases 정렬하기 
	
	for (int i = 0;i < all_cases.size();i++) {
		if (is_candidate(all_cases[i], relation)) {
			del_cases(all_cases[i]);
			i--;
			answer++;
		}
		else {
			all_cases.erase(all_cases.begin() + i);
			i--;
		}
	}
	return answer;
}

int main(void) {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	int answer = solution(relation);
	//cout << "answer :" << answer << endl;
	return 0;
}
