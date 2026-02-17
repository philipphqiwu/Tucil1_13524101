#include <bits/stdc++.h>
using namespace std;

int iter = 0;

// Check validity
bool isSafe(vector<vector<bool>> &checked, int row, int col, char color, int n, unordered_set<char> color_set) {

    // Check if num exist in the row
    for (int x = 0; x < n; x++){
        if (checked[row][x]){
            return false;
        }
    }

    // Check if num exist in the col
    for (int x = 0; x < n; x++){
        if (checked[x][col]){
            return false;
        }
    }

    // Check if num exist in the surrounding 3x3 sub-matrix
    int startRow = row - 1, startCol = col - 1;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(i+startRow < 0 || i+startRow>=n || j+startCol < 0 || j+startCol>=n){
                continue;
            } else if (checked[i + startRow][j + startCol]){
                return false;
            }
        }
    }

    // Check if color occupied
    if(color_set.find(color) != color_set.end()){
        return false;
    }

    return true;
}

// Recursive Solve
bool solveQueensRec(vector<string> &mat, vector<vector<bool>> &checked, int row, int n, unordered_set<char> color_set) {

    iter++;



    // W case
    if (row == n){
        return true;
    }

    // safe check
    for(int col=0; col<n; col++){
        if (isSafe(checked, row, col, mat[row][col], n, color_set)) {
            checked[row][col] = true;
            color_set.insert(mat[row][col]);
            if (solveQueensRec(mat, checked, row+1, n, color_set)){
                return true;
            }
            checked[row][col] = false;
            color_set.erase(mat[row][col]);
        }
    }

  	return false;
}

bool solveQueens(vector<string> &mat, vector<vector<bool>> &checked, int n, unordered_set<char> color_set) {
  	return solveQueensRec(mat, checked, 0, n, color_set);
}

int main() {
    vector<string> mat = {
        "AAABBCCCD",
      	"ABBBBCECD",
      	"ABBBDCECD",
        "AAABDCCCD",
        "BBBBDDDDD",
        "FGGGDDHDD",
        "FGIGDDHDD",
        "FGIGDDHDD",
        "FGGGDDHHH"};

    /*
    contoh konfig without solution
    mat = {
        "AAA",
      	"ABB",
      	"BCC"};
    */

    int n = mat.size();

    unordered_set<char> color_set;
    vector<vector<bool>> checked;

    for(int i = 0; i<n; i++){
        if(mat[i].size() != n){
            cout << "Invalid Dimensions!!" << endl;
            return 0;
        }
        vector<bool> checkedRow (n, false);
        checked.push_back(checkedRow);
        for(int j = 0; j < n; j++){
            color_set.insert(mat[i][j]);
        }
    }

    if(color_set.size() != n){
        cout << "Jumlah Warna Tidak Sesuai!!" << endl;
        return 0;
    }

    color_set.clear();

	if(solveQueens(mat, checked, n, color_set)){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if(checked[i][j]){
                    cout << "# ";
                } else{
                    cout << mat[i][j] << " ";
                }
            cout << endl;
        }
        cout << endl << "Jumlah iterasi: " << iter << endl;
	}
    else{
        cout << endl << "Tidak ditemukan solusi!!!" << endl;
        cout << endl << "Jumlah iterasi: " << iter << endl;
    }
    return 0;
}
