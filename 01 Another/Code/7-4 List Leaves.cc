// https://pintia.cn/problem-sets/1603283867296088064/exam/problems/1603283867392557065
// 参考代码：https://blog.csdn.net/liyuanyue2017/article/details/83539009

#include<iostream>
#include<queue>
using namespace std;

// 树的结点
struct TreeNode {
  int data;
  int left;
  int right;
};

int main() {
  int N{}, root{}, flag{};
  char l1{}, l2{};
  TreeNode temp{};
  TreeNode Tr[10]{};
  queue<struct TreeNode> q;  // 队列
  // 读入树的所有结点
  cin >> N;
  if (!N) {  // 如果为空树
    root = -1;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    Tr[i].data = i;
    cin >> l1 >> l2;  // cin的语法要有更深刻的理解
    if (l1 == '-') {
      Tr[i].left = -1;
    }
    else {
      Tr[i].left = l1 - '0';
      root -= Tr[i].left;
    }
    if (l2 == '-') {
      Tr[i].right = -1;
    }
    else {
      Tr[i].right = l2 - '0';
      root -= Tr[i].right;
    }
    root += i;  // 没有被减去的就是根结点
  }

  // 层序遍历，并判断叶子结点
  // 层序遍历需要用到队列的知识点
  q.push(Tr[root]);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    if ((temp.left == -1) && (temp.right == -1)) {
      if (flag) {
        // 这个输出空格不是第一次遇到了哈
        cout << ' ';
      } else {
        flag = 1;
      }
      cout << temp.data;
    }
    if (temp.left != -1) {
      q.push(Tr[temp.left]);
    }
    if (temp.right != -1) {
      q.push(Tr[temp.right]);
    }
  }
  return 0;
}
