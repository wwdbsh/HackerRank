#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long result[10000000];

long arrayManipulation(int n, vector<vector<int>> queries) {
    for(int i = 0; i < queries.size(); i++){
        result[queries[i][0]-1] += queries[i][2];
        result[queries[i][1]] -= queries[i][2];
    }
    long max_v = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += result[i];
        max_v = max(max_v, sum);
    }
    return max_v;
}