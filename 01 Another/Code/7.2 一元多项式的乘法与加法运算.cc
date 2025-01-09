#include <iostream>
using namespace std;
struct Poly {
  int coefficient;  // 系数
  int index;        // 指数
  struct Poly* next;
};
// 输入多项式
Poly* InputPoly() {
  int n = 0;
  Poly* p1, * p2, * temp;
  p1 = (Poly*)malloc(sizeof(struct Poly));
  //p2->coefficient = 0;
  //p2->index = 0;
  //p2->next = NULL;
  //p1 = p2;
  p2 = p1;
  cin >> n;  // 多项式非零的项数
  for (int i = 0; i < n; ++i) {
    temp = (Poly*)malloc(sizeof(struct Poly));
    cin >> temp->coefficient;
    cin >> temp->index;
    p2->next = temp;  // 将新建的结点插入链表尾部
    p2 = p2->next;    // p2始终指向链表尾部
    //if (++i < n) {  // 如果在后面这样建的话，不一定用的上。
    //                // 还是在头结点用一个空结点，然后在释放掉！
    //  p2->next = (Poly *)malloc(sizeof(struct Poly));
    //  p2 = p2->next;
    //}
  }
  p2->next = NULL;
  temp = p1;
  p1 = p1->next;
  free(temp);
  return p1;
}
// 输出多项式
void OutputPoly(Poly* p) {
  if (!p) {
    cout << "0 0";
  }
  // 输出多项式非零的系数和指数
  while (p) {
    cout << p->coefficient << ' ';
    if (p->next) {
      cout << p->index << ' ';
    }
    else {
      cout << p->index;
    }
    p = p->next;
  }
  cout << endl;
  return;
}
// 两个多项式的加法
Poly* PolyAdd(Poly* p1, Poly* p2) {
  Poly* ps, * rear, * temp;
  ps = (Poly*)malloc(sizeof(struct Poly));
  rear = ps;
  // 一项一项的加
  while (p1 && p2) {
    if (p1->index == p2->index) {  /*两个多项式的指数一样*/
      // 注意！
      // 这里需要考虑系数为0的情况。即，合并同类项。
      if (p1->coefficient + p2->coefficient == 0) {
        p1 = p1->next;
        p2 = p2->next;
        continue;
      }
      // 创建一个新的结点
      // 存储当前的计算结果
      temp = (Poly*)malloc(sizeof(struct Poly));
      temp->coefficient = p1->coefficient + p2->coefficient;
      temp->index = p1->index;
      // 将此结点加入到多项式的末尾
      rear->next = temp;
      rear = rear->next;
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->index < p2->index) {  /*指数大的多项式往后移动一项*/
      // 创建一个新的结点
      // 存储当前指数大的项数
      temp = (Poly *)malloc(sizeof(struct Poly));
      temp->coefficient = p2->coefficient;
      temp->index = p2->index;
      // 将此结点加入到多项式的末尾
      rear->next = temp;
      rear = rear->next;
      p2 = p2->next;
    } else {  /*p1->index > p2->index*/
      // 创建一个新的结点
      // 存储当前指数大的项数
      temp = (Poly *)malloc(sizeof(struct Poly));
      temp->coefficient = p1->coefficient;
      temp->index = p1->index;
      // 将此结点加入到多项式的末尾
      rear->next = temp;
      rear = rear->next;
      p1 = p1->next;
    }
  }
  // 如果多项式还有剩余的项，加到结果多项式的后面
  while (p1) {
    // 创建一个新的结点
    // 存储当前剩余项数
    temp = (Poly *)malloc(sizeof(struct Poly));
    temp->coefficient = p1->coefficient;
    temp->index = p1->index;
    // 将此结点加入到多项式的末尾
    rear->next = temp;
    rear = rear->next;
    p1 = p1->next;
  }
  while (p2) {
    // 创建一个新的结点
    // 存储当前剩余项数
    temp = (Poly *)malloc(sizeof(struct Poly));
    temp->coefficient = p2->coefficient;
    temp->index = p2->index;
    // 将此结点加入到多项式的末尾
    rear->next = temp;
    rear = rear->next;
    p2 = p2->next;
  }
  rear->next = NULL;
  temp = ps;
  ps = ps->next;
  free(temp);
  return ps;
}
// 两个多项式的乘法
// 将其转化为加法来做这个题
Poly *PolyMul(Poly *p1, Poly *p2) {
  Poly *pm, *temp;
  pm = NULL;
  // 一项项的加上去
  for (Poly *pi = p1; pi != NULL; pi = pi->next) {
    for (Poly *pj = p2; pj != NULL; pj = pj->next) {
      temp = (Poly *)malloc(sizeof(struct Poly));
      // 由于输入的限制，这里不可能为0，不用考虑合并同类项
      temp->coefficient = pi->coefficient * pj->coefficient;
      temp->index = pi->index + pj->index;
      temp->next = NULL;
      pm = PolyAdd(pm, temp);
    }
  }
  return pm;
}
int main() {
  Poly *p1, *p2, *pm, *ps;
  // 输入两个多项式
  p1 = InputPoly();
  p2 = InputPoly();
  // 两个多项式求积
  pm = PolyMul(p1, p2);
  // 两个多项式求和
  ps = PolyAdd(p1, p2);
  // 输出两个多项式求和求积的结果
  OutputPoly(pm);
  OutputPoly(ps);
  return 0;
}
