#include <iostream>
using namespace std;

#define MAX_TREE 10
#define NONE -1
typedef char ElementType;
typedef int Tree;

// 静态链表的形式
struct TreeNode {
  ElementType element;
  Tree left;
  Tree right;
};

TreeNode tree1[MAX_TREE];
TreeNode tree2[MAX_TREE];

Tree BuildTree(TreeNode tree[]);
bool IsOmorphic(Tree r1, Tree r2);

int main() {
  Tree r1, r2;
  // 读入两颗树
  r1 = BuildTree(tree1);
  r2 = BuildTree(tree2);
  if (IsOmorphic(r1, r2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

// 建立一颗树
Tree BuildTree(TreeNode tree[]) {
  int n;
  int check[MAX_TREE] = {0};
  char cl, cr;
  Tree root = NONE;
  cin >> n;
  if (!n) return root;
  for (int i = 0; i < n; i++) {
    cin >> tree[i].element >> cl >> cr;
    if (cl == '-') {
      tree[i].left = NONE;
    } else {
      tree[i].left = cl - '0';
      check[tree[i].left] = 1;
    }
    if (cr == '-') {
      tree[i].right = NONE;
    } else {
      tree[i].right = cr - '0';
      check[tree[i].right] = 1;
    }
  }
  // 哪个序号没有没当做孩子，哪个就是根结点
  for (int i = 0; i < n; i++) {
    if (!check[i]) {
      root = i;
      break;
    }
  }
  // 返回根结点
  return root;
}

// 判断两颗树是否同构
// 这个利用了递归的思想非常值得学习
bool IsOmorphic(Tree r1, Tree r2) {
  // 两颗树都为空
  if (r1 == NONE && r2 == NONE) {
    return true;
  }
  // 如果一颗树为空，一棵树不为空
  if (((r1 == NONE) && (r2 != NONE)) || ((r1 != NONE) && (r2 == NONE))) {
    return false;
  }
  // 两颗树都不空的话
  // 判断根结点的值是否相同
  if (tree1[r1].element != tree2[r2].element) {
    return false;
  }
  // 对于根结点判断完毕
  // 如果左子树都为空，判断右子树
  if (tree1[r1].left == NONE && tree2[r2].left == NONE) {
    return IsOmorphic(tree1[r1].right, tree2[r2].right);
  }
  // 如果左子树都不为空，则继续判断下去
  if ((tree1[r1].left != NONE && tree2[r2].left != NONE) &&
      (tree1[tree1[r1].left].element == tree2[tree2[r2].left].element)) {
    return IsOmorphic(tree1[r1].left, tree2[r2].left) && 
           IsOmorphic(tree1[r1].right, tree2[r2].right);
  } else {  // 否则需要交换子树重新交换
    return IsOmorphic(tree1[r1].right, tree2[r2].left) &&
           IsOmorphic(tree1[r1].left, tree2[r2].right);
  }
 }
