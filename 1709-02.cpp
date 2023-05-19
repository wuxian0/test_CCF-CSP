/**
 * 公共钥匙盒
 * 
 * 不是太想写循环
 * 
 * 
 * 一个想法 类似于邻接链表 顶点表为每个时间点排序后的挂钩
 * 另一个想法 一个数组存放每个时间段 第一个挂钩以及对应的时间段
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct 
{
    int keyno;
    int start;
    int end;
}Teacher;

bool startOrder( Teacher a, Teacher b)
{
    if(a.end == b.end && a.start < b.start)
    {
        return true;
    }
    else if(a.start == b.start && a.keyno < b.keyno)
    {
        return true;
    }
    return false;
}

bool endOrder( Teacher a, Teacher b)
{
    if(a.end < b.end)
    {
        return true;
    }
    else if((a.end == b.end) && (a.keyno < b.keyno))
    {
        return true;
    }
    return false;
}


int main()
{
    int N,K;
    int kn,st,last;

    Teacher teacher[1010];
    int posList[1010];
    int tmin;
    int tmax;
    int getKey[1010];


    scanf("%d%d",&N,&K);

    for(int i = 1; i <= K; i++)
    {
        scanf("%d%d%d",&kn, &st, &last);
        teacher[i].keyno = kn;
        teacher[i].start = st;
        teacher[i].end = st+last;
    }
    //
    for(int i = 1; i <= N; i++)
    {
        posList[i] = i;
    }

    sort(teacher+1, teacher+K+1, endOrder);
    tmax = teacher[K].end;
    sort(teacher+1, teacher+K+1, startOrder);
    tmin = teacher[1].start;
    
    
    for(int i = tmin; i <= max; i++)
    {


    }

    // for(int i = 1; i <= K; i++)
    // {
    //     getKey[i] = teacher[i].keyno;
    // }
    // for(int i = 1; i <= K; i++)
    // {
    //     printf("%d ",getKey[i]);
    // }
    // printf("\n");

    // sort(teacher+1, teacher+K+1, endOrder);
    // for(int i = 1; i <= K; i++)
    // {
    //     keyList[getKey[i]] = teacher[i].keyno;
    //     printf("%d ",teacher[i].keyno);

    // }
    // printf("\n");
    
    for(int i = 1; i <= N; i++)
    {
        printf("%d ",keyList[i]);
    }

	return 0;
}