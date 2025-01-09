#include<iostream> 
using namespace std;

const int MAXN = 102;
int a[MAXN]{};
int length_a[MAXN];


int main(void) {
  int n{}, max_length{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  max_length = 0;
  for (int i = 0; i < n; ++i) {
    length_a[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (a[i] >= a[j] && length_a[i] < length_a[j] + 1) {
        length_a[i] = length_a[j] + 1;
      }
    }
    if (length_a[i] > max_length) {
      max_length = length_a[i];
    }
  }

  cout << max_length;

  return 0;
}
