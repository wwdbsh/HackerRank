#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int count = 0, min_cost = 0, p_num = k;
    sort(c.begin(), c.end());
    for(int i = c.size()-1; i >= 0; i--){
        min_cost += (count+1)*c[i];
        p_num--;
        if(p_num == 0){
            p_num = k;
            count++;
        }
    }
    return min_cost;
}

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int flower;
        cin >> flower;
        v.push_back(flower);
    }
    cout << getMinimumCost(k, v) << "\n";
}