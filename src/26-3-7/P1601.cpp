#include <iostream>
#include <string>
using namespace std;

char onebit_add(char a, char b, int& carry)
{
    int sum = (a - '0') + (b - '0') + carry;
    char res = (sum % 10) + '0';
    carry = sum / 10;
    return res;
} 

string add(string a, string b)
{
    string res;
    int len_a = a.size(), len_b = b.size();
    int carry = 0;
    for (int i = 0; i < max(len_a, len_b); i++)
    {
        char digit_a = i < len_a ? a[len_a - 1 - i] : '0';
        char digit_b = i < len_b ? b[len_b - 1 - i] : '0';
        char onebit_result = onebit_add(digit_a, digit_b, carry);
        res = onebit_result + res;
    }
    res = carry ? '1' + res : res;
    while (res.size() > 1 && res[0] == '0')
        res.erase(0, 1);
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}


/*
# P1601 高精度加法

## 题目背景

本题是高精度加法的模板题。

## 题目描述

给定两个非负整数 $a,b$，求它们的和。**不用考虑负数**。

## 输入格式

输入共两行，每行一个非负整数，分别为 $a,b$。

## 输出格式

输出一行一个非负整数，表示 $a+b$ 的值。

## 输入输出样例 #1

### 输入 #1

```
1
1
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
1001
9099
```

### 输出 #2

```
10100
```

## 说明/提示

对于 $20\%$ 的测试数据，$a,b \le 10^9$；
对于 $40\%$ 的测试数据，$a,b \le 10^{18}$；
对于 $100\%$ 的测试数据，$0\le a,b \le 10^{500}$。
*/