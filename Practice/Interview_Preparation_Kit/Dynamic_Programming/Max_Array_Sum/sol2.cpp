#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100000];

int maxSubsetSum(vector<int> arr){
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < arr.size(); i++){
        dp[i] = max(arr[i], max(dp[i-1], dp[i-2]+arr[i]));
    }
    return dp[arr.size()-1];
}

int main(void){
    int n;
    vector<int> arr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << maxSubsetSum(arr) << "\n";
}