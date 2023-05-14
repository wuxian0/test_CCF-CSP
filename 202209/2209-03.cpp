/**
 * 防疫大数据
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

typedef struct 
{
    int area;
    int start;
    int end;
}RangArea;

bool comp(RangArea A, RangArea B)
{
    if(A.area < B.area)
    {
        return true;
    }
    else if(A.area == B.area && A.start < B.start)
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    int a[10010][3];
    // int answer[10010][]
    int p;
    int d,u,r;
    RangArea range[100010];
    int rangeAreaCnt = 0;
    int rangeAreaCntLast = 1;

    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d",a[i][0],a[i][1]);
        for(int j = 0; j < a[i][1]; j++);
        {
            scanf("%d",&p);
            rangeAreaCnt++;
            range[rangeAreaCnt].area = p;
            range[rangeAreaCnt].start = i;
            range[rangeAreaCnt].end = i+7-1;
        }
        if(rangeAreaCntLast <= rangeAreaCnt)
        {
            sort(range+rangeAreaCntLast,range+rangeAreaCnt,comp);
        }
        
        for(int h = 0; h < a[i][0]; h++)
        {
            scanf("%d%d%d",&d,&u,&r);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i][0] == 0)
        printf("%d ",i);
        else{
            printf("%d 1",i);
        }
        printf("\n");
    }

	

	return 0;
}