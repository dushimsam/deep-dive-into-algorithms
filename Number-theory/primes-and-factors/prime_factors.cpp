#include<bits/stdc++.h>
using namespace std;

/***
                            PRIME FACTORIZATION O(sqrt(n))
                            (prime factors of anumber)
it turns out that if n is not a prime number , its factors will be less than sqrt(n).

 ***/
vector<int> findPrimeFactors(int n){
    vector<int> primeFactors;

    for(int x = 2; x*x <= n; x++){
        while(n % x == 0){
              primeFactors.push_back(x);
              n /= x;
        }
    }
    
    // if n is remaining meaning that it is also among the group of prime factors.
    if(n >= 2) primeFactors.push_back(n);

    return primeFactors;
}
int main(){
 int n = 24;

 vector<int> primeFactors = findPrimeFactors(n);
 for(int i=0;i<primeFactors.size();i++)
     cout<<primeFactors[i]<<" ";

    return 0;
}