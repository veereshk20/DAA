#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findPosition(int x, vector<vector<int>>& matrix) {
    int n = matrix.size();
   
    int i = 0, j = n - 1; 
    int comp = 0;
    while (i < n && j >= 0) {
        if (matrix[i][j] == x) {
            cout<<"#"<<comp<<endl;
            return {i, j};
        } else if (matrix[i][j] > x) {
            j--; 
        } else {
            i++;
        }
        comp++;
    }

    return {-1, -1}; 
}

int main() {
    int x;
    vector<vector<int>> matrix = {
        {1,2,3,4,5},
        {6,10,11,12,13},
        {7,14,17,18,19},
        {8,15,20,22,23},
        {9,16,21,24,25}
    };
    cin>>x;
    pair<int, int> position = findPosition(x, matrix);

    if (position.first != -1 && position.second != -1) {
        cout << "Position of " << x << " in matrix: (" << position.first << ", " << position.second << ")" << endl;
    } else {
        cout << x << " not found in matrix." << endl;
    }

    return 0;
}