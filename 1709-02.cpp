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
    if(a.start < b.start)
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

int posList[1010];
int N,K;
int kn,st,last;

Teacher teacher[1010];
Teacher tcopy[1010];

int tmin;
int tmax;
int getKey[1010];

void putKey(int kno)
{
    for(int i = 1; i <= N; i++)
    {
        if(posList[i] == 0)
        {
            posList[i] = kno;
            // printf("归还钥匙%d，位置:%d\n",kno, i);
            break;
        }
    }
}

void getKeyy(int kno)
{
    for(int i = 1; i <= N; i++)
    {
        if(posList[i] == kno)
        {
            posList[i] = 0;
            // printf("获取钥匙%d，位置:%d\n",kno, i);
            break;
        }
    }
}

int main()
{
    scanf("%d%d",&N,&K);

    for(int i = 1; i <= K; i++)
    {
        scanf("%d%d%d",&kn, &st, &last);
        teacher[i].keyno = kn;
        teacher[i].start = st;
        teacher[i].end = st+last;
        tcopy[i] = teacher[i];
    }
    // printf("%d %d %d\n",tcopy[1].keyno,tcopy[1].start,tcopy[1].end);

    for(int i = 1; i <= N; i++)
    {
        posList[i] = i;
    }

    sort(tcopy+1, tcopy+K+1, endOrder);
    tmax = tcopy[K].end;
    sort(teacher+1, teacher+K+1, startOrder);
    tmin = teacher[1].start;

    int it = 1;
    int itc = 1;
    int time = 1;
    while(time <= tmax)
    {
        // printf("时间：%d\n",time);
        for(int i = itc; i <= K; i++)
        {
            if(tcopy[i].end == time)
            {
                putKey(tcopy[i].keyno);
                itc = i;
            }
            else if(tcopy[i].end > time)
            {
                itc = i;
                break;
            }
        }

        for(int i = it; i <= K; i++)
        {
            if(teacher[i].start == time)
            {
                getKeyy(teacher[i].keyno);
                it = i;
            }
            else if(teacher[i].end > time)
            {
                it = i;
                break;
            }
        }

        time++; 

    }
    
    
    for(int i = 1; i <= N; i++)
    {
        printf("%d ",posList[i]);
    }

	return 0;
}