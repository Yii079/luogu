#include <iostream>
#include <string>
using namespace std;

string factorial(int n)
{
    static string result[51];
    if (n == 0 || n == 1)
        return "1";
    if (result[n] != "")
        return result[n];
    
    string prev = factorial(n - 1);
    int num[501] = {0};
    int len = prev.size();
    for (int i = 0; i < len; i++)
    {
        num[i] = (prev[len - 1 - i] - '0') * n;
    }
    for (int i = 0; i < 500; i++)
    {
        num[i + 1] += num[i] / 10;
        while (num[i] >= 10)
        {
            num[i] %= 10;
        }
    }
    for (int i = 500; i >= 0; i--)
    {
        if (num[i] != 0)
        {
            len = i;
            break;
        }
    }
    for (int i = len; i >= 0; i--)
    {
        result[n] += (num[i] + '0');
    }
    return result[n];
}

string add(const string& a, const string& b)
{
    int answer[500] = {0};
    int lena = a.size(), lenb = b.size();
    for (int i = 0; i < lena; i++)
    {
        answer[i] += a[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; i++)
    {
        answer[i] += b[lenb - i - 1] - '0';
    }
    int len = max(lena, lenb);
    for (int i = 0; i < len; i++)
    {
        answer[i + 1] += answer[i] / 10;
        answer[i] %= 10;
    }
    while (len > 0 && answer[len] == 0)
    {
        len--;
    }
    string res;
    for (int i = len; i >= 0; i--)
    {
        res += (answer[i] + '0');
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    string sum = "0";
    for (int i = 0; i < n; i++)
    {
        sum = add(sum, factorial(i + 1));
    }
    cout << sum << endl;
    return 0;
}

/*
# P1009 [NOIP 1998 普及组] 阶乘之和

## 题目描述

用高精度计算出 $S = 1! + 2! + 3! + \cdots + n!$（$n \le 50$）。

其中 `!` 表示阶乘，定义为 $n!=n\times (n-1)\times (n-2)\times \cdots \times 1$。例如，$5! = 5 \times 4 \times 3 \times 2 \times 1=120$。

## 输入格式

一个正整数 $n$。

## 输出格式

一个正整数 $S$，表示计算结果。

## 输入输出样例 #1

### 输入 #1

```
3

```

### 输出 #1

```
9
```

## 说明/提示

**【数据范围】**

对于 $100 \%$ 的数据，$1 \le n \le 50$。

**【其他说明】**

注，《深入浅出基础篇》中使用本题作为例题，但是其数据范围只有 $n \le 20$，使用书中的代码无法通过本题。

如果希望通过本题，请继续学习第八章高精度的知识。

NOIP1998 普及组 第二题
*/