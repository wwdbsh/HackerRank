#include <iostream>
#include <vector>

using namespace std;

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size()-(i+1); j++){
            if(a[j] > a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                count++;
            }
        }
    }
    cout << "Array is sorted in " << count << " swaps.\nFirst Element: " << a[0] << "\nLast Element: " << a[a.size()-1] << "\n";
}

int main(void){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        v.push_back(e);
    }
    countSwaps(v);
}