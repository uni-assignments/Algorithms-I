#include <iostream>
#include <vector>

using namespace std;

int main (){

//    vector<int> v = {2, 3, 4, 5, 6, 5, 3, 2, 1};
//    vector<int> v = {2, 3, 4, 5, 6};
    vector<int> v = {1, 4, 3, 2};

    int size = v.size();

    int l = 0, r = size, m;

    while(l<r){
        m = (l+r)/2;
        if(m == 0 || m == size) break;
        if(v[m-1] <= v[m] && v[m] >= v[m+1])
            break;
        else if(v[m-1] > v[m]) r = m;
        else if(v[m-1] < v[m]) l = m;
    }

    cout << m << ":" << v[m] << endl;

    return 0;
}