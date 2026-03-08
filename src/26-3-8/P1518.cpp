#include <iostream>
using namespace std;

void next_step(int& posX, int& posY, int& dirX, int& dirY, int map[10][10])
{
    int nextPosX = posX + dirX, nextPosY = posY + dirY;
    int nextDirX = dirX, nextDirY = dirY;
    if (nextPosX < 0 || nextPosX > 9 || nextPosY < 0 || nextPosY > 9 || map[nextPosX][nextPosY] == 1)
        nextDirX = dirY, nextDirY = -dirX;
    else posX = nextPosX, posY = nextPosY;
    dirX = nextDirX, dirY = nextDirY;
}

int main()
{
    int map[10][10];
    int C_posX, C_posY, F_posX, F_posY;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char c; cin >> c;
            switch (c)
            {
                case '.': map[i][j] = 0; break;
                case '*': map[i][j] = 1; break;
                case 'C': C_posX = i, C_posY = j; break;
                case 'F': F_posX = i, F_posY = j; break;
            }
        }
    }
    // int C_initPosX = C_posX, C_initPosY = C_posY;
    // int F_initPosX = F_posX, F_initPosY = F_posY;
    int C_dirX = -1, C_dirY = 0;
    int F_dirX = -1, F_dirY = 0;
    int t = 0;
    while (C_posX != F_posX || C_posY != F_posY)
    {
        if (t >= 10000)
        {
            t = 0;
            break;
        }
        next_step(C_posX, C_posY, C_dirX, C_dirY, map);
        next_step(F_posX, F_posY, F_dirX, F_dirY, map);
        // if (C_posX == C_initPosX && C_posY == C_initPosY && C_dirX == -1 && C_dirY == 0 &&
        //     F_posX == F_initPosX && F_posY == F_initPosY && F_dirX == -1 && F_dirY == 0)
        // {
        //     t = 0;
        //     break;
        // }
        t++;
    }
    cout << t << endl;
    return 0;
}
/*
# P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two

## 题目描述

两只牛逃跑到了森林里。Farmer John 开始用他的专家技术追捕这两头牛。你的任务是模拟他们的行为（牛和 John）。

追击在 $10 \times 10$ 的平面网格内进行。一个格子可以是：空地，一个障碍物，两头牛（它们总在一起），或者 Farmer John。两头牛和 Farmer John 可以在同一个格子内（当他们相遇时），但是他们都不能进入有障碍的格子。

一个格子可以是：
- `.` 空地；
- `*` 障碍物；
- `C` 两头牛；
- `F` Farmer John。

这里有一个地图的例子：

```plain
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

牛在地图里以固定的方式游荡。每分钟，它们可以向前移动或是转弯。如果前方无障碍（地图边沿也是障碍），它们会按照原来的方向前进一步。否则它们会用这一分钟顺时针转 $90$ 度。 同时，它们不会离开地图。

Farmer John 深知牛的移动方法，他也这么移动。

每次（每分钟）Farmer John 和两头牛的移动是同时的。如果他们在移动的时候穿过对方，但是没有在同一格相遇，我们不认为他们相遇了。当他们在某分钟末在某格子相遇，那么追捕结束。

读入十行表示地图。每行都只包含 $10$ 个字符，表示的含义和上面所说的相同。保证地图中只有一个 `F` 和一个 `C`。`F` 和 `C` 一开始不会处于同一个格子中。

计算 Farmer John 需要多少分钟来抓住他的牛，假设牛和 Farmer John 一开始的行动方向都是正北（即上）。 如果 John 和牛永远不会相遇，输出 $0$。

## 输入格式

输入共十行，每行 $10$ 个字符，表示如上文描述的地图。

## 输出格式

输出一个数字，表示 John 需要多少时间才能抓住牛们。如果 John 无法抓住牛，则输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

### 输出 #1

```
49
```

## 说明/提示

翻译来自NOCOW

USACO 2.4
*/