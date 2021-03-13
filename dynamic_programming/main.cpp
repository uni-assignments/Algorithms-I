#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const long long INF = 0x3f3f3f3f;

float minimum_value(int line, int d, vector<vector<pair<float, float>>> memo){
    int min = 0;
    for(int i = 0; i <= line && i < d; i++){
        if(memo[line][i].second < memo[line][min].second) min = i;
    }
    return memo[line][min].second;
}
void print_memo(int d, int n, vector<vector<pair<float, float>>> memo){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i or j < d; j++){
            cout << memo[i][j].second <<" ";
        }
        cout << endl;
    }
}
float minimum_cost(int n, int d, int t, vector<float> discounts, vector<pair<float, float>> subway_lines){
    vector<vector<pair<float, float>>> memo(n, vector<pair<float, float>> (d));
    
    memo[0][0] = subway_lines[0];
    memo[0][0] = make_pair(subway_lines[0].first, subway_lines[0].second * discounts[0]);
    for(int i = 1; i < n; i++){
        memo[i][0] = make_pair(subway_lines[i].first, subway_lines[i].second * discounts[0] + minimum_value(i-1, d, memo)); //primeira coluna o tempo 0, logo o tempo sera so o dql escala e o custo sera o menor custo
        for(int j = 1; j < d and j <= i; j++){ 
            if(memo[i-1][j-1].first < t and memo[i-1][j-1].first >= 0)
                memo[i][j] = make_pair(subway_lines[i].first + memo[i-1][j-1].first, subway_lines[i].second * discounts[j] + memo[i-1][j-1].second);
            else 
                memo[i][j] = make_pair(-1, INF);
        }
    }
    //print_memo(d, n, memo);
    return minimum_value(n - 1, d, memo);
}


vector<float> transform_discounts(vector<float> discounts, int d_sz){
    for(int i = 1; i < d_sz; i++){
        discounts[i] += discounts[i-1];
        if(discounts[i] > 100.0) discounts[i] = 100.0;
    }
    for(int i = 0; i < d_sz; i++){
        discounts[i] = (100.0 - discounts[i])/100.0;
    }
    return discounts;
}

int main(){

    int n, d, t;
    cin >> n >> d >> t;
    
    vector<float> discounts(d);
    vector<pair<float, float>> subway_lines(n); 
    for (int i = 0; i < d; i++) cin >> discounts[i];
    
    float time, price;
    for (int i = 0; i < n; i++) {
        cin >> time >> price;
        subway_lines[i] = make_pair(time, price);
    }

    discounts = transform_discounts(discounts, d);
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << minimum_cost(n, d, t, discounts, subway_lines) << endl;
    return 0;
}