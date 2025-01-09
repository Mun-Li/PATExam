#include<iostream>
#include<string>
#include<stack>
using namespace std;

// 树的输出标志
bool flag = false;

// 树的结点
typedef struct TreeNode* Tree;
struct TreeNode {
  string data;
  Tree left{};
  Tree right{};
};


Tree Init();
Tree CreatNode();
void PostTraversed(Tree root);


int main() {
  Tree root{};
  root = Init();
  PostTraversed(root);
  return 0;
}

// 初始化，整理一棵树
Tree Init() {
  Tree root{}, node{}, temp{};
  stack<Tree> sta{};
  string str{};  // 还是用string类比较简单，来的快啊。
  int N{};
  cin >> N;
  cin.get();
  if (!N) {
    return root;
  } else {
    root = CreatNode();
  }
  node = root;
  for (int i = 0; i < 2 * N; i++) {
    getline(cin, str);
    if (str == "Pop") {
      node = sta.top();
      sta.pop();
    } else {  // 如果是push
      temp = CreatNode();
      temp->data = str.substr(5);
      if (!node->left) {
        node->left = temp;
      } else if (!node->right) {
        node->right = temp;
      }
      node = temp;
      sta.push(temp);
    }
  }
  temp = root;
  root = root->left;
  delete temp;
  return root;
}

// 创造一个树的结点
Tree CreatNode() {
  // 由于结构体中有string类中
  // 需要用new来分配内存
  Tree temp = new struct TreeNode();
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// 后序遍历一棵树
void PostTraversed(Tree root) {
  if (!root) {
    return;
  }
  PostTraversed(root->left);
  PostTraversed(root->right);
  if (flag) {
    cout << ' ';
  } else {
    flag = true;
  }
  cout << root->data;
  return;
}
