// 4_4 贪心
// B1020 月饼
// 注意最后输出的小数点的个数
// ========================
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct MoonCake {
  double all_weight;
  double all_sale;
  double single_sale;
};

MoonCake cake_array[1002]{};
double N = 0, D = 0;

static bool CompCake(MoonCake cake1, MoonCake cake2) {
  return cake1.single_sale > cake2.single_sale;
}

int main() {
  scanf_s("%lf %lf", &N, &D);
  for (int i = 0; i < N; ++i) {
    scanf_s("%lf", &cake_array[i].all_weight);
  }
  for (int i = 0; i < N; ++i) {
    scanf_s("%lf", &cake_array[i].all_sale);
    cake_array[i].single_sale = cake_array[i].all_sale/cake_array[i].all_weight;
  }
  sort(cake_array, cake_array+int(N), CompCake);

  // 开始贪心算法
  double max_sale = 0;
  double total_D = D;
  for (int i = 0; i < N; ++i) {
    if(cake_array[i].all_weight >= total_D) {
      max_sale = max_sale + cake_array[i].single_sale * total_D;
      total_D = 0;
      break;
    } else {
      max_sale = max_sale + cake_array[i].all_sale;
      total_D = total_D - cake_array[i].all_weight;
    }
  }
  cout << max_sale;
  return 0;
}
