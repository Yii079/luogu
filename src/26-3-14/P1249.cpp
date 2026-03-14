#include <iostream>
#include <string>
using namespace std;

string multipy(string str, int num)
{
    int len = str.size();
    int long_num[1000] = {0};
    for (int i = 0; i < len; i++)
    {
        long_num[i] = (str[len - i - 1] - '0') * num;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (long_num[i] > 9)
        {
            long_num[i + 1] += (long_num[i] / 10);
            long_num[i] %= 10;
        }
    }
    len = 1000;
    while (!long_num[len - 1]) len--;
    string ans;
    for (int i = len - 1; i >= 0; i--)
    {
        ans += (long_num[i] + '0');
    }
    return ans;
}

int main()
{
    int n; cin >> n;
    int ans[1000] = {0};
    int i = 2;
    while (n >= i)
    {
        n -= i;
        ans[i-2] = i;
        i++;
    }
    int len = i - 2;
    for (int j = len - 1; n > 0 && j >= 0; j--)
    {
        ans[j]++;
        n--;
    }
    if (n) ans[len - 1]++;
    string str = "1";
    for (i = 0; ans[i] != 0; i++)
    {
        str = multipy(str, ans[i]);
        cout << ans[i] << ' ';
    }
    cout << '\n' << str << '\n';
    return 0;
}

/*
# P1249 最大乘积

## 题目描述

一个正整数一般可以分为几个互不相同的自然数的和，如 $3=1+2$，$4=1+3$，$5=1+4=2+3$，$6=1+5=2+4$。

现在你的任务是将指定的正整数 $n$ 分解成若干个互不相同的自然数（也可以不分解，就是这个数字本身）的和，且使这些自然数的乘积最大。

## 输入格式

只有一个正整数 $n$，（$3 \leq n \leq 10000$）。

## 输出格式

第一行是分解方案，相邻的数之间用一个空格分开，并且按由小到大的顺序。

第二行是最大的乘积。

## 输入输出样例 #1

### 输入 #1

```
10

```

### 输出 #1

```
2 3 5
30
```
*/