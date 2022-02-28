#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(int ro, int col, vector<vector<string>>& arr, string num) {
    for (int i = 0; i < 9; i++) {
        if (arr[ro][i] == num)//validate this row
            return false;
        if (arr[i][col] == num)//validate this col
            return false;
        if (arr[3 * (ro / 3) + i / 3][3 * (col / 3) + i % 3] == num)//validate this grid
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<string>>& arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            if (arr[i][j] != ".") {
                string temp = arr[i][j];
                arr[i][j] = '+';
                if (!isValid(i, j, arr, temp)) {
                    return false;
                }
                arr[i][j] = temp;
            }
    }
    return true;
}

void main()
{
	vector<vector<string>> board =
	{ {".", "8", "7", "6", "5", "4", "3", "2", "1"}
, { "2", ".", ".", ".", ".", ".", ".", ".", "." }
, { "3", ".", ".", ".", ".", ".", ".", ".", "." }
, { "4", ".", ".", ".", ".", ".", ".", ".", "." }
, { "5", ".", ".", ".", ".", ".", ".", ".", "." }
, { "6", ".", ".", ".", ".", ".", ".", ".", "." }
, { "7", ".", ".", ".", ".", ".", ".", ".", "." }
, { "8", ".", ".", ".", ".", ".", ".", ".", "." }
, { "9", ".", ".", ".", ".", ".", ".", ".", "." } };
	//{	  {"5", "3", ".", ".", "7", ".", ".", ".", "."}
	//	, { "6", ".", ".", "1", "9", "5", ".", ".", "." }
	//	, { ".", "9", "8", ".", ".", ".", ".", "6", "." }
	//	, { "8", ".", ".", ".", "6", ".", ".", ".", "3" }
	//	, { "4", ".", ".", "8", ".", "3", ".", ".", "1" }
	//	, { "7", ".", ".", ".", "2", ".", ".", ".", "6" }
	//	, { ".", "6", ".", ".", ".", ".", "2", "8", "." }
	//	, { ".", ".", ".", "4", "1", "9", ".", ".", "5" }
	//	, { ".", ".", ".", ".", "8", ".", ".", "7", "9" } };

	if (isValidSudoku(board))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
}
