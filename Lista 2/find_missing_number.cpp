#include <iostream>
#include <vector>
using namespace std;


int get_diff(vector<int> v){
    return min(v[1] - v[0], v[v.size() - 1] - v[v.size() - 2]);
}

int find_missing(vector<int> v, int diff){

    int l = 0, r = v.size() - 1, m;

    while(l < r){
        m = (l+r)/2;
        if(v[m] > diff*m + v[0]) r = m;
        else l = m + 1;
    }
    
    if(m == 0) return v[m] + diff;
    else if(m == v.size() - 1) return v[m] - diff;
    else  return v[m] - v[m-1] == diff ? v[m] + diff : v[m] - diff;
}

int main (){

   vector<int> l = {1, 2, 3, 5};
   vector<int> r = {3, 6, 9, 15};
   vector<int> m = {5, 10, 20, 25};
   vector<int> n = {1, 3, 7, 9};
   vector<int> v = {2, 6, 8};
    cout << "Missing Number: " << find_missing(l, get_diff(l)) << endl;
    cout << "Missing Number: " << find_missing(r, get_diff(r)) << endl;
    cout << "Missing Number: " << find_missing(m, get_diff(m)) << endl;
    cout << "Missing Number: " << find_missing(n, get_diff(n)) << endl;
    cout << "Missing Number: " << find_missing(v, get_diff(v)) << endl;

    return 0;
}
