// refer from: https://www.cnblogs.com/tacticKing/p/17325087.html
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


const int MAX_N = 6;
struct node {
  int A;
  int sum_A_plus1;
  node(int u, int v) : A(u), sum_A_plus1(v){};
};
vector<node> result;


bool isForever(int bit_K, int sum_m);
int BitSum(int number);
int Gcd(int n1, int n2);
bool isPrime(int num);
bool cmpNode(node node1, node node2);


int main() {
  int N{}, Km[MAX_N][2]{};
  cin >> N;
  for (int i = 0; i < N; ++i) {  // input example
    cin >> Km[i][0] >> Km[i][1];
  }

  // judge every example is forever
  for (int i = 0; i < N; ++i) {
    cout << "Case " << i + 1 << endl;
    if (isForever(Km[i][0], Km[i][1])) {  // is forever
      // step1, sort result
      sort(result.begin(), result.end(), &cmpNode);

      // step2, display result
      for (int i = 0; i < result.size(); ++i) {
        cout << result[i].sum_A_plus1 << ' ' << result[i].A << endl;
      }
    } else {
      cout << "No Solution" << endl;
    }
    result.clear();  // empty last result
  }
  return 0;
}


// K-bit integer, the sum of these bits is m
// 3 < K < 10, 1 < m < 90
bool isForever(int bit_K, int sum_m) {
  int leftband = pow(10, bit_K - 1) + 99;
  int rightband = pow(10, bit_K);
  for (int i = leftband; i < rightband; i += 100) {
    if (BitSum(i) == sum_m) {  // the number that we want
      int sum_n = BitSum(i + 1);
      if (isPrime(Gcd(sum_m, sum_n))) {  // the common divisor is a prime number
        // save sum_n and i
        result.push_back(node(i, sum_n));
      }
    }
  }
  if (result.empty()) {  // no result
    return false;
  }
  return true;
}


// count the sum of each bit
int BitSum(int number) {
  int sum{};
  do {
    sum += number % 10;
    number /= 10;
  } while (number);
  return sum;
}


// find the greatest common divisor of n1 and n2
// it's more of a reduction
int Gcd(int n1, int n2) {
  while (true) {
    if (n1 < n2) {
      n2 -= n1;
    } else if (n2 < n1) {
      n1 -= n2;
    } else {
      return n1;
    }
  }
}


// judge the num is prime > 2
bool isPrime(int num) {
  double sqrt_num = sqrt((double)num);
  if (num < 3) {
    return false;
  }
  for (int i = 2; i <= sqrt_num; ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}


// to sort vector of cmp function
bool cmpNode(node node1, node node2) {
  if (node1.sum_A_plus1 != node2.sum_A_plus1) {
    return node1.sum_A_plus1 < node2.sum_A_plus1;
  } else {
    return node1.A < node2.A;
  }
}
