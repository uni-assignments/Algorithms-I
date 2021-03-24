#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const long long INF = 0x3f3f3f3f;

void print_memo(int d, int n, vector<vector<pair<double, double>>> memo){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i or j < d; j++){
            cout << memo[i][j].first <<" ";
        }
        cout << endl;
    }
}
double minimum_cost(int n, int d, int t, vector<double> discounts, vector<pair<double, double>> subway_lines){
    vector<vector<pair<double, double>>> memo(n, vector<pair<double, double>> (d));
    vector<int> minimum_value(n, 0);
    memo[0][0] = make_pair(subway_lines[0].first, subway_lines[0].second * discounts[0]);
    
    for(int i = 1; i < n; i++){
        memo[i][0] = make_pair(subway_lines[i].first, subway_lines[i].second * discounts[0] + memo[i-1][minimum_value[i-1]].second); //primeira coluna o tempo 0, logo o tempo sera so o dql escala e o custo sera o menor custo
        for(int j = 1; j < d and j <= i; j++){ 
            if(memo[i-1][j-1].first < t and memo[i-1][j-1].first >= 0){
                memo[i][j] = make_pair(subway_lines[i].first + memo[i-1][j-1].first, subway_lines[i].second * discounts[j] + memo[i-1][j-1].second);
                if(memo[i][minimum_value[i]].second > memo[i][j].second)
                    minimum_value[i] = j;
            }
            else 
                memo[i][j] = make_pair(-1, INF);
        }
    }
    //print_memo(d, n, memo);
    return memo[n-1][minimum_value[n-1]].second;
}


vector<double> transform_discounts(vector<double> discounts, int d_sz){
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
    
    vector<double> discounts(d);
    vector<pair<double, double>> subway_lines(n); 
    for (int i = 0; i < d; i++) cin >> discounts[i];
    
    double time, price;
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