#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

int arr[201];

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int ans = 0;
    for(int i = 0; i < d; i++){
        arr[expenditure[i]]++;
    }
    for(int i = d; i < expenditure.size(); i++){
        double median = 0;
        if(d % 2 != 0){
            int count = 0;
            for(int j = 0; j < 201; j++){
                count += arr[j];
                if(count > d/2){
                    median = j;
                    break;
                }
            }
        }else{
            int count = 0, m1 = 0, m2 = 0;
            for(int j = 0; j < 201; j++){
                count += arr[j];
                if(m1 == 0 && count >= d/2){
                    m1 = j;
                }
                if(m2 == 0 && count >= d/2+1){
                    m2 = j;
                    break;
                }
            }
            median = (double)(m1+m2)/2;
        }
        if(expenditure[i] >= median*2){
            ans++;
        }
        arr[expenditure[i-d]]--;
        arr[expenditure[i]]++;
    }
    return ans;
}

int main(void){
    int n, d;
    vector<int> v;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        int ex;
        cin >> ex;
        v.push_back(ex);
    }
    cout << activityNotifications(v, d) << "\n";
}