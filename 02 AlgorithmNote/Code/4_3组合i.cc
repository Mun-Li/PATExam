#include<cstdio>
#include<vector>
using namespace std;

int g_n = 0, g_k = 0;
int g_hastTable[15] = {0};
vector<int> g_resultTemp;
vector<vector<int>> g_result;

static void GetCombinationK(int start)
{
    if (g_resultTemp.size() == g_k) {
        for (int i = 0; i < g_k - 1; ++i) {
            printf("%d ", g_resultTemp[i]);
        }
        printf("%d\n", g_resultTemp[g_k - 1]);
    } else {
        for (int i = start; i <= g_n; ++i) {     // 从小到大排列
            if (g_hastTable[i] == false) {       // 还未加入组合中
                g_resultTemp.push_back(i);
                g_hastTable[i] = true;
                GetCombinationK(i + 1);          // 不允许
                g_resultTemp.pop_back();
                g_hastTable[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &g_n, &g_k);
    GetCombinationK(1);
    return 0;
}

