#include<iostream>

using namespace std;

long long int Nfactorial(long long int n) {
    if(n == 0) {
        return 1;
    } else if(n > 0) {
        return Nfactorial(n-1)*n;
    }
}

int main(){
    long long int n = 0;
    cin >> n;
    cout << Nfactorial(n);
    return 0;
}


