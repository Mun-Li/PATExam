#include<iostream>
using namespace std;

// 平衡二叉树结构体
typedef struct TreeNode* AVLTree;
struct TreeNode {
  int data;
  int height;
  AVLTree left;
  AVLTree right;
};

AVLTree Insert(AVLTree root, int x);
int GetHeight(AVLTree root);
int HeightMax(int height1, int height2);
AVLTree Lrot(AVLTree root);
AVLTree Rrot(AVLTree root);
AVLTree LRrot(AVLTree root);
AVLTree RLrot(AVLTree root);

int main() {
  AVLTree root{};
  int N{}, temp{};
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    root = Insert(root, temp);
  }
  if (root) {
    cout << root->data;
  }
  return 0;
}

// AVL的插入，需要不断的调整树的结构
// 这里对于递归的思想，需要好好理解(==+-2这个地方)
AVLTree Insert(AVLTree root, int x) {
  if (!root) {
    root = new struct TreeNode;
    root->data = x;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (x > root->data) {  // 插入右子树
      root->right = Insert(root->right, x);
      // 需要考虑为RR和RL型，则向左旋转，右左旋转
      if (GetHeight(root->left) - GetHeight(root->right) == -2) {
        if (x > root->right->data) {
          root = Lrot(root);
        } else {
          root = RLrot(root);
        }
      }
    } else if (x < root->data) {  // 插入左子树
      root->left = Insert(root->left, x);
      // 需要考虑为LL和LR型，则向右旋转，左右旋转
      if (GetHeight(root->left) - GetHeight(root->right) == 2) {
        if (x < root->left->data) {
          root = Rrot(root);
        } else {
          root = LRrot(root);
        }
      }
    }
  }
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  return root;
}

// 求树的高度
int GetHeight(AVLTree root) {
  if (!root) {  // 树为空，高度为0
    return 0;
  } else {  // 有了height后就不需要递归了
    return root->height;
  }
}

// 取height1和height2中的较大值
int HeightMax(int height1, int height2) {
  return height1 > height2 ? height1 : height2;
}

// 左旋
AVLTree Lrot(AVLTree root) {
  AVLTree temp = root->right;
  root->right = temp->left;
  temp->left = root;
  // 记得更新树高
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  temp->height = HeightMax(GetHeight(temp->left), GetHeight(temp->right)) + 1;
  return temp;
}

// 右旋
AVLTree Rrot(AVLTree root) {
  AVLTree temp = root->left;
  root->left = temp->right;
  temp->right = root;
  root->height = HeightMax(GetHeight(root->left), GetHeight(root->right)) + 1;
  temp->height = HeightMax(GetHeight(temp->left), GetHeight(temp->right)) + 1;
  return temp;
}

// 左右旋
AVLTree LRrot(AVLTree root) {
  // 先左旋
  root->left = Lrot(root->left);
  // 再右旋
  root = Rrot(root);
  return root;
}

// 右左旋
AVLTree RLrot(AVLTree root) {
  // 先右旋
  root->right = Rrot(root->right);
  // 再左旋
  root = Lrot(root);
  return root;
}
