#include <iostream>
#include <vector>
using namespace std;


vector<int> r(int sz, vector<int> radares){
    vector<int> memo(sz, 0);
    memo[0] = radares[0];
    for(int i = 1; i < sz; i++){
        int j = 1, max = 0;
        //iremos analisar todos os radares a mais de 10km do radar atual i e a menos de 20km
        while(i-j >= 0 and radares[i] - radares[i-j] < 20) { 
            if(radares[i] - radares[i-j] >= 10 and memo[max] < memo[i-j]) max = i - j; //Acharemos o radar com maior valor
            j++;
        }
        memo[i] = radares[i] + memo[max]; // radar atual sera ele + melhor custo de radar;
    }   
    return memo; 
}

int main(){
    
    vector<int> radares = {15, 40, 46, 53, 60, 71, 75, 90, 100};
    vector<int> memo = r(radares.size(), radares);

    for(auto m: memo){
        cout << m << endl;
    }

    return 0;
}