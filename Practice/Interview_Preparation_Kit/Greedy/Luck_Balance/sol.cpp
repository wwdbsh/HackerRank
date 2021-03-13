#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int max_luck = 0;
    sort(contests.begin(), contests.end());
    for(int i = contests.size()-1; i >= 0; i--){
        int l = contests[i][0];
        int t = contests[i][1];
        if(t == 1 && k > 0){
            max_luck += l;
            k--;
        }else if(t == 1){
            max_luck -= l;
        }else{
            max_luck += l;
        }
    }
    return max_luck;
}

int main(void){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        int l, t;
        cin >> l >> t;
        v.push_back({l, t});
    }
    cout << luckBalance(k, v) << "\n";
}