/**
 * 称检测点查询
 * 
 * 100
 * 
 * 做了好大会，sort排序自定义比较函数，结构体熟悉
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>


typedef struct
{
    int index = 0;
    double dist = 0;
}A;

int X;
int Y;

bool comp(A i , A j)
{
    if(i.dist < j.dist)
    {
        return true;
    }
    // 正确的
    if(i.dist == j.dist && i.index < j.index)
    // 错误的
    // if(i.index < j.index)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
int p,q;
A a[210];

    scanf("%d%d%d",&n,&X,&Y);

    for(int i = 1;i <= n; i++)
    {
        scanf("%d%d",&p,&q);
        a[i].index = i;
        a[i].dist = sqrt(pow(p-X,2)+pow(q-Y,2));
        i++;
        i--;
        
    }
    std::sort(a+1,a+n,comp);
    for(int i = 1; i <= 3; i++)
    {
        printf("%d\n",a[i].index);
    }

	return 0;
}