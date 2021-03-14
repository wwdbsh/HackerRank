#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int rt = 1e9;
    sort(arr.begin(), arr.end());
    for(int i = k-1; i < arr.size(); i++){
        int big = arr[i];
        int small = arr[i-k+1];
        rt = min(rt, big-small);
    }
    return rt;
}

int main(void){
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        v.push_back(e);
    }
    cout << maxMin(k, v) << "\n";
}