#include <iostream>

using namespace std;

bool dp[1001][1001];

string abbreviation(string a, string b) {
    int n = a.length();
    int m = b.length();
    for(int row = 0; row <= n; row++){
        for(int col = 0; col <= m; col++){
            if(row == 0 && col == 0){
                dp[row][col] = true;
                continue;
            }
            if(row == 0 || col == 0 || row < col){
                continue;
            }
            // if(row < col){
            //     continue;
            // }
            if(toupper(a[row]) == b[col]){
                dp[row][col] = true;
            }else{
                dp[row][col] = dp[row-1][col];
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[n][m] ? "YES" : "NO";
}

int main(void){
    string a, b;
    cin >> a >> b;
    cout << abbreviation(a, b) << "\n";
}