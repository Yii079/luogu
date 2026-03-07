#include <iostream>
#include <string>
using namespace std;

char onebit_add(char a, char b, int &carry)
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

char onebit_multipy(char a, char b, int& carry)
{
    int answer = (a - '0') * (b - '0') + carry;
    char res = answer % 10 + '0';
    carry = answer / 10;
    return res;
}

string multipy(string a, string b)
{
    int len_a = a.size(), len_b = b.size();
    string res;

    for (int i = 0; i < len_b; i++)
    {
        string temp;
        int carry = 0;
        for (int j = 0; j < len_a; j++)
        {
            char onebit_result = onebit_multipy(a[len_a - 1 - j], b[len_b - 1 - i], carry);
            temp = onebit_result + temp;
        }
        if (carry)
            temp = (char)(carry + '0') + temp;
        temp += string(i, '0');
        res = add(res, temp);
    }
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multipy(a, b) << endl;
    return 0;
}


/*
# P1303 A*B Problem

## 题目背景

高精度乘法模板题。

## 题目描述

给出两个非负整数，求它们的乘积。

## 输入格式

输入共两行，每行一个非负整数。

## 输出格式

输出一个非负整数表示乘积。

## 输入输出样例 #1

### 输入 #1

```
1
2
```

### 输出 #1

```
2
```

## 说明/提示

每个非负整数不超过 $10^{2000}$。
*/