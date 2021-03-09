#include <iostream>
#include <vector>

using namespace std;

// pair<int,int> divide_and_conquer(int l, int r, vector<int> v){
//     if(l+1 >= r){ // Caso tenhamos dividido tanto q sobrou um par
//         return make_pair(l, r);
//     }    
//     pair<int,int> p_l = divide_and_conquer(l, (l+r)/2, v);
//     pair<int,int> p_r = divide_and_conquer((l+r)/2 + 1, r, v); 

//     return compare_pair(p_l, p_r, v); 

// }

pair<int, int> stocks(int sz, vector<int> v){
    int c_max = sz, max = sz, min = sz;
    for(int i = sz - 1; i >= 0; i--){
        if(v[i] > v[max]) max = i;
        else if((v[max] - v[i]) > (v[c_max] - v[min])) min = i, c_max = max;
    }

    return make_pair(min, c_max);
}
int calculateMin(vector<int> v, int l, int r){
    int mini = l;
    for(int i = l; i <= r; i++){
        if(v[i]<v[mini]){
            mini = i;
        }
    }
    return mini;
}
int calculateMax(vector<int> v, int l, int r){
    int maxi = v[l];
    for(int i = l; i <= r; i++){
        if(v[i]> v[maxi]){
            maxi = i;
        }
    }
    return maxi;
}

pair<int, int> calculateMaxDiff(vector<int> v, int l, int r){
    if(l >= r)
        return make_pair(l, r);

    int mid = (l+r)/2;
    pair<int,int> leftPartition = calculateMaxDiff(v,l,mid);
    pair<int,int> rightPartition = calculateMaxDiff(v,mid+1,r);
    int left = calculateMin(v,l,mid); // calculate the min value in the left partition
    int right = calculateMax(v,mid+1,r); // calculate the max value in the right partition
    if(v[leftPartition.first] - v[leftPartition.second] > v[rightPartition.first] - v[rightPartition.second]){
        if(v[leftPartition.first] - v[leftPartition.second] > v[right] - v[left]) return leftPartition;
        else return make_pair(left, right);
    } else {
        if(v[rightPartition.first] - v[rightPartition.second] > v[right] - v[left]) return rightPartition;
        else return make_pair(left, right);
    }
}

int main (){

    //vector<int> v = {1, 2, 5, 4, 9, 11, 8, 7};
    //vector<int> v = {5, 4, 9, 11, 1, 7};
    vector<int> v = {6, 7, 9, 11, 1, 7};

    int sz = v.size() - 1;
    

    pair<int, int> ans = calculateMaxDiff(v, 0, sz);
    cout << "Pair: (" << ans.first << " , " << ans.second << ")" << endl;
    cout << "Values: (" << v[ans.first] << " , " << v[ans.second] << ")" << endl;

    return 0;
}