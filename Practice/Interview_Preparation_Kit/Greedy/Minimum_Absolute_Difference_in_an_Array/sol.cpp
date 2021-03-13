#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    int min_abs = 1e9;
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        min_abs = min(min_abs, abs(arr[i-1]-arr[i]));
    }
    return min_abs;
}

int main(void){
    cout << minimumAbsoluteDifference({1,-3,71,68,17}) << "\n";
}