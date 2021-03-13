#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long candies(int n, vector<int> arr) {
    long sum = 0;
    vector<int> dp(n, 1);
    arr[0] >= arr[1] ? dp[0]++ : dp[1]++;
    sum += (dp[0]+dp[1]);
    for(int i = 2; i < n-1; i++){
        if(arr[i] > arr[i-1]){
            dp[i] = dp[i-1]+1;
        }
        if(arr[i] <= arr[i+1]){
            if(dp[i] == 1){
                dp[i+1]++;
            }else{
                dp[i]--;
            }
        }
        sum += dp[i];
    }
    sum += dp[n-1];
    return sum;
}

int main(void){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        arr.push_back(r);
    }
    cout << candies(n, arr) << "\n";
}