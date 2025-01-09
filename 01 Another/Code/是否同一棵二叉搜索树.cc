#include<iostream>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
  int data;
  Tree left;
  Tree right;
};

Tree CreatTree(int N);
Tree InsertTree(Tree root, int data);
bool CompareTree(Tree root1, Tree root2);
void ComparePrint(Tree root1, Tree root2);

int main()
{
  int N{}, L{};
  Tree* rootarray{};
  cin >> N;
  while (N) {
    cin >> L;
    rootarray = new Tree[L+1];
    for (int i = 0; i < L + 1; i++) {
      rootarray[i] = CreatTree(N);
      if (i >= 1) {
        ComparePrint(rootarray[0], rootarray[i]);
      }
    }
    delete[] rootarray;
    cin >> N;
  }
  return 0;
}

// 根据输入创建一棵树
Tree CreatTree(int N) {
  Tree root{};
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    root = InsertTree(root, temp);
  }
  return root;
}

// 插入树的结点
Tree InsertTree(Tree root, int data) {
  if (!root) {
    root = new struct TreeNode;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (data > root->data) {
      root->right = InsertTree(root->right, data);
    } else if (data < root->data) {
      root->left = InsertTree(root->left, data);
    }
  }
  return root;
}

// 比较两颗树是否相等
bool CompareTree(Tree root1, Tree root2) {
  if (root1 == NULL && root2 == NULL) {
    return true;
  } else if (root1 != NULL && root2 != NULL) {
    if (root1->data == root2->data) {
      return CompareTree(root1->left, root2->left) &&
             CompareTree(root1->right, root2->right);
    } else {
      return false;
    }
  } else {
    return false;
  }
}

// 输出判断的结果
void ComparePrint(Tree root1, Tree root2) {
  if (CompareTree(root1, root2)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return;
}