#include <iostream>
#include <vector>
#include <string>
using namespace std;
string tictactoe(vector<vector<int>>& moves);
int main() {
	vector <vector<int>> M = {{2,2 }, { 0,2 }, { 1,0 }};

	cout << tictactoe(M) << endl;

};
string tictactoe(vector<vector<int>>& moves) {
	int maindigA = 0, suppdigA = 0, horA = 0, verA = 0, horB = 0, verB = 0, maindigB = 0, suppdigB = 0;
	int tictacdesk[3][3];
	string res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tictacdesk[i][j] = 0;
		}
	}
	for (int move = 0; move < moves.size(); move++) {
		for (int turn = 0; turn < moves[move].size(); turn++) {
			if (move % 2 == 0 || move == 0) {
				tictacdesk[moves[move][0]][moves[move][1]] = 1;
			}
			else {
				tictacdesk[moves[move][0]][moves[move][1]] = 2;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		horA = 0, verA = 0;
		for (int j = 0; j < 3; j++) {
			if (tictacdesk[i][j] == 1) {
				horA++;
			}
			if (tictacdesk[j][i] == 1) {
				verA++;
			}
		}
		if (horA == 3 || verA == 3) {
			res = "A";
			return res;
		}
	}
	for (int i = 0; i < 3; i++) {
		horB = 0, verB = 0;
		for (int j = 0; j < 3; j++) {
			if (tictacdesk[i][j] == 2) {
				horB++;
			}
			if (tictacdesk[j][i] == 2) {
				verB++;
			}
		}
		if (horB == 3 || verB == 3) {
			res = "B";
			return res;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (tictacdesk[i][i] == 1) {
			maindigA++;
		}
		if (tictacdesk[i][2-i] == 1) {
			suppdigA++;
		}
		if (tictacdesk[i][i] == 2) {
			maindigB++;
		}
		if (tictacdesk[i][2 - i] == 2) {
			suppdigB++;
		}
	}
	if (maindigA == 3 || suppdigA == 3) {
		res = "A";
		return res;
	}
	else if (maindigB == 3 || suppdigB == 3) {
		res = "B";
		return res;
	}
	if (res != "A" || res != "B") {
		if (moves.size() < 8) {
			res = "Pending";
		}
		else {
			res = "Draw";
		}
	}
	return res;
};