#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void minimumBribes(vector<int> q) {
    int rt = 0;
    for(int i = q.size()-1; i >= 0; i--){
        if(q[i] != i+1){
            if(i-1 >= 0 && q[i-1] == i+1){
                rt += 1;
                swap(q[i-1], q[i]);
            }else if(i-2 >= 0 && q[i-2] == i+1){
                rt += 2;
                q[i-2] = q[i-1];
                q[i-1] = q[i];
                q[i] = i+1;
            }else{
                cout << "Too chaotic\n";
                return;
            }
        }
    }
    cout << rt << "\n";
}