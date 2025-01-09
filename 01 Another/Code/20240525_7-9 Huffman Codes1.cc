// Huffman Codes
// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=671&page=0
// 
// ==================================
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<iostream>

#define HeapCapacity 64
#define MinData 0

// 下面这种结构体的这种命名方式，感觉看到好多次了
// 体会体会使用指针的妙处（直接就改变对应的值，无需再次引用）
// 尤其是在函数传递参数的时候可以用到
typedef struct TreeNode* HuffmanTree;
typedef struct Heap* MinHeap;

struct Heap {
  HuffmanTree* data;
  int size;  // 堆的当前大小
};

struct TreeNode {
  int weight;  // 频率
  HuffmanTree left;
  HuffmanTree right;
};
using namespace std;

map<char, int> mapp;

//
MinHeap InitHeap(int n);
MinHeap CreatHeap();
HuffmanTree CreateHuffmanTree();
void AdjustMinHeap(MinHeap H);
void SortMinHeap(MinHeap H, int i);
HuffmanTree DeleteMinHeap(MinHeap H);
void InseretMinHeap(MinHeap H, HuffmanTree Huff);
int WeightPlantLength(HuffmanTree Huff, int depth);
HuffmanTree Huffman(MinHeap H);
void SubmitJudge(int n, int codeLen);

void SubmitJudge(int n, int codeLen) {
  HuffmanTree Huff = CreateHuffmanTree();
  HuffmanTree pre;
  int counter = 1;
  bool flag = true;  // 是否含有前缀码的判断标志
  char ch;
  string code;

  // 根据编码方式，建立一颗Huffman Tree
  for (int i = 0; i < n; ++i) {
    getchar();
    scanf("%c", &ch);
    cin >> code;
    pre = Huff;  // 每次都从Huffman tree开始判断
    // 开始建立Huffman Tree
    for (int j = 0; j < code.size(); ++j) {
      if (code[j] == '0') {  // 如果当前编码为0，左分支
        if (pre->left == NULL) {
          pre->left = CreateHuffmanTree();
          ++counter;
        }
        if (pre->weight != 0) {  // 这也是会出现前缀码了
          flag = false;
        }
        pre = pre->left;
      } else if (code[j] == '1') {  // 如果当前编码为1，右分支
        if (pre->right == NULL) {
          pre->right = CreateHuffmanTree();
          ++counter;
        }
        if (pre->weight != 0) {  // 这也是会出现前缀码了
          flag = false;
        }
        pre = pre->right;
      }
    }
    if (pre->left || pre->right) {  // 这也是会出现前缀码了
      flag = false;
    }
    pre->weight = mapp[ch];  // 取出字符所对应出现的频率
  }

  // 判断是否满足Huffman codes的要求
  if ((counter == 2*n-1) && flag && (WeightPlantLength(Huff, 0) == codeLen)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

// 计算Huffman codes的长度
int WeightPlantLength(HuffmanTree Huff, int depth) {
  if ((Huff->left == NULL) && (Huff->right == NULL)) {
    return depth * Huff->weight;
  } else {  // Huffman树是一颗完满二叉树（要就是有两个子结点，要就是有0个子结点）
    return (WeightPlantLength(Huff->left, depth + 1) +
            WeightPlantLength(Huff->right, depth + 1));
  }
}

// 创建HuffmanTree
HuffmanTree Huffman(MinHeap H) {
  int times = H->size;
  HuffmanTree Huff;
  for (int i = 1; i < times; ++i) {  // 即 times-1次的组合
    Huff = CreateHuffmanTree();
    Huff->left = DeleteMinHeap(H);
    Huff->right = DeleteMinHeap(H);
    Huff->weight = Huff->left->weight + Huff->right->weight;
    InseretMinHeap(H, Huff);
  }
  Huff = DeleteMinHeap(H);  // 取出创建好的Huffman tree
  return Huff;
}

// 删除最小堆
HuffmanTree DeleteMinHeap(MinHeap H) {
  int parent{}, child{};
  HuffmanTree huff_first = H->data[1];
  HuffmanTree huff_end = H->data[H->size];
  --H->size;  // 删除一个

  // 直接开始调整MinHeap
  for (parent = 1; 2 * parent <= H->size; parent = child) {
    // 在左右儿子中挑最小的
    child = 2 * parent;
    if ((child != H->size) &&
        (H->data[child + 1]->weight < H->data[child]->weight)) {
      ++child;
    }
    // 如果没有最小的了，结束循环？？？
    if (huff_end->weight <= H->data[child]->weight) {
      break;
    }
    // 否则就把儿子结点拿上来
    H->data[parent] = H->data[child];
  }
  H->data[parent] = huff_end;
  return huff_first;
}

// 插入最小堆
// 这个调整的格式还是很简洁
void InseretMinHeap(MinHeap H, HuffmanTree Huff) {
  int i = ++H->size;
  // 哨兵在这里就有用了吧！
  for (; Huff->weight < H->data[i / 2]->weight; i /= 2) {  // 这里的i/2可能是会等于0，利用了之前那个哨兵？
    H->data[i] = H->data[i / 2];
  }
  H->data[i] = Huff;
}

// 初始化堆
MinHeap InitHeap(int n) {
  MinHeap H = CreatHeap();
  HuffmanTree Huff{};
  char c_temp{};
  int f_temp{};
  for (int i = 0; i < n; ++i) {
    getchar();  // 输入这里为什么要一个getchar函数？(读入换行符，和空格)
    scanf("%c %d", &c_temp, &f_temp);  // 这种输入和记录的方式还是第一次看见
    mapp.insert(pair<char, int>(c_temp, f_temp));
    Huff = CreateHuffmanTree();
    Huff->weight = f_temp;
    H->data[++H->size] = Huff;  // 注意这里还有一个H->size
  }
  AdjustMinHeap(H);
  return H;
}

// 调整为最小堆
void AdjustMinHeap(MinHeap H) {
  // 从第一个有孩子结点的结点开始进行调整？(完全二叉树，存储在数组中的一点技巧)
  for (int i = H->size / 2; i > 0; --i) {
    SortMinHeap(H, i);
  }
}

// 调整子最小堆
void SortMinHeap(MinHeap H, int i) {
  int parent{}, child {};
  HuffmanTree Huff = H->data[i];  // 当前结点的哈夫曼树
  for (parent = i; parent * 2 <= H->size; parent = child) {
    child = 2 * parent; // 左子结点
    // 在左右子结点中选取最小的
    if ((child != H->size) && (H->data[child + 1]->weight < H->data[child]->weight)) {
      ++child;
    }
    if (H->data[parent]->weight <= H->data[child]->weight) {
      break;
    }
    H->data[parent] = H->data[child];  // parent一定是要和child交换的？前面不是有一个break吗
  }
  H->data[parent] = Huff;  // 这一步又是怎么操作的呢
}

// 建堆
MinHeap CreatHeap() {
  MinHeap H;
  H = (MinHeap) malloc(sizeof(struct Heap));
  // H->data = (HuffmanTree*)malloc(sizeof(struct TreeNode) * HeapCapacity);  // 这个地址的分配没看明白
  H->data = (HuffmanTree*)malloc(sizeof(HuffmanTree) * HeapCapacity);  // 我觉得应该是这样的
  H->size = 0;
  HuffmanTree Huff = CreateHuffmanTree();  // 设置哨兵？？？作用是？
  H->data[0] = Huff;
  return H;
}

// 建立哈夫曼树
HuffmanTree CreateHuffmanTree() {
  HuffmanTree Huff;
  Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
  Huff->left = NULL;
  Huff->right = NULL;
  Huff->weight = MinData;  // 初始化频率最小？
  return Huff;
}

//
int main(int argc, char* argv[]) {
  int n{}, m{};  // 编码字符数n，学生数量m
  scanf("%d", &n);

  // 初始化最小堆
  MinHeap H = InitHeap(n);

  // 建立Huffman Tree
  HuffmanTree Huff = Huffman(H);

  // 计算Huffman编码的长度
  // 注意根结点是0层呢
  int codeLen = WeightPlantLength(Huff, 0);

  // 判断m个学生输入的编码方式
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    SubmitJudge(n, codeLen);
  }
  return 0;
}

