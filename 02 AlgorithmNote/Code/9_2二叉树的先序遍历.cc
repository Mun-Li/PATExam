#include<iostream>
using namespace std;

const int MaxN = 50;

// 树顶点的定义
// 考虑到题目的输入，这里用结构体数组来表示这颗树；
// 但是一般而言，我们是用链表的形式来建立树和进行相关的操作；
struct TreeNode {
  int LtreeNode;
  int RtreeNode;
}Tree[MaxN];


// 先序遍历，直接就输出
// 最后后面不能有多余的空格？
void PreorderTraversal(int root) {
  static int flag{};
  ++flag;
  if (root != -1) {
    if (flag != 1) {
      cout << ' ';
    }
    cout << root;
    PreorderTraversal(Tree[root].LtreeNode);
    PreorderTraversal(Tree[root].RtreeNode);
  }
}


int main() { 
  int n{}, root{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l_temp{}, r_temp{};

    // 输入当前的节点数据
    cin >> l_temp >> r_temp;
    Tree[i].LtreeNode = l_temp;
    Tree[i].RtreeNode = r_temp;

    // 这一步是判断哪一个是根节点
    // 离谱这个题目都给出了根节点为0了呀
    root += i;
    if (l_temp != -1) {
      root -= l_temp;
    }
    if (r_temp != -1) {
      root -= r_temp;
    }
  }
  PreorderTraversal(root);
  return 0;
}
