#include <iostream>
#include <vector>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> ans;
    int ptr = d % a.size();
    for(int i = ptr; i < a.size(); i++){
        ans.push_back(a[i]);
    }
    for(int i = 0; i < ptr; i++){
        ans.push_back(a[i]);
    }
    return ans;
}

int main(void){
    int n, d;
    cin >> n >> d;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        v.push_back(e);
    }
    vector<int> ans = rotLeft(v, d);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}