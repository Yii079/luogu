#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1010;
string factorial(int n)
{
    static string ans[N] = {"1", "1"};
    if (ans[n].size() != 0) return ans[n];
    string prev = factorial(n-1);
    int len = prev.size();
    vector<int> num;
    for (int i = 0; i < len; i++) num.push_back(prev[len-i-1] - '0');
    for (int i = 0; i < len; i++) num[i] *= n;
    for (int i = 0; i < len - 1; i++)
    {
        while (num[i] > 9)
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.back() > 9)
    {
        int t = num.back() / 10;
        num.back() %= 10;
        num.push_back(t);
    }
    len = num.size();
    for (int i = len - 1; i >= 0; i--)
    {
        ans[n] += (char)(num[i] + '0');
    }
    return ans[n];
}

int main()
{
    int k; cin >> k;
    while (k--)
    {
        int n; char a; 
        cin >> n >> a;
        int count = 0;
        string str = factorial(n);
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == a) count++;
        }
        cout << count << endl;
    }
    return 0;
}

/*
# P1591 阶乘数码

## 题目描述

求 $n!$ 中某个数码出现的次数。

## 输入格式

第一行为 $t(t \leq 10)$，表示数据组数。接下来 $t$ 行，每行一个正整数 $n(n \leq 1000)$ 和数码 $a$。

## 输出格式

对于每组数据，输出一个整数，表示 $n!$ 中 $a$ 出现的次数。

## 输入输出样例 #1

### 输入 #1

```
2
5 2
7 0
```

### 输出 #1

```
1
2
```
*/