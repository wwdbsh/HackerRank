#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int count = 0;
    for(int i = 0; i < prices.size(); i++){
        k -= prices[i];
        if(k < 0) break;
        count++;
        if(k == 0) break;
    }
    return count;
}

int main(void){
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int price;
        cin >> price;
        v.push_back(price);
    }
    cout << maximumToys(v, k) << "\n";
}