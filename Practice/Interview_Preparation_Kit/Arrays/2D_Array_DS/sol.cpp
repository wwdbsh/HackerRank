#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getSum(vector<vector<int>> arr, int x, int y){
    int sum = 0;
    for(int i = x; i < x+3; i++){
        for(int j = y; j < y+3; j++){
            sum += arr[i][j];
        }
    }
    sum -= (arr[x+1][y] + arr[x+1][y+2]);
    return sum;
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr){
    int ans = -1e9;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ans = max(ans, getSum(arr, i, j));
        }
    }
    return ans;
}

int main(void){
    vector<vector<int>> v(6, vector<int>(6));
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> v[i][j];
        }
    }
    cout << hourglassSum(v) << "\n";
}