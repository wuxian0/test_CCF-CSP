/**
 * 风险人群筛查
 * 
 * 100
 * 
 * 关键在于连续，多设几个标志位，连续停留次数（flag记录上次坐标，用于重置连续停留记录），经过标志，逗留标志，
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int n,k,t,xl,yd,xr,yu;
    int countCross = 0;
    int countStay = 0;

    scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yd,&xr,&yu);
    for(int i = 1; i <= n; i++)
    {
        int x,y;
        int count = 0;
        int flag = 0;
        int cross = 0;
        int stay = 0;
        for(int j = 1; j <= t; j++)
        {
            scanf("%d%d",&x,&y);

            if( ( x >= xl && x <= xr ) && ( y >= yd & y <= yu) )
            {
                if(flag == 0)
                {
                    count = 0;
                }
                flag = 1;
                count++;
                cross++;
                if(count >= k)
                {
                    stay++;
                }
                // printf(":::%d\n",count);
            }
            else{
                flag = 0;
            }
        }
        if(cross)
        {
            if(stay)
            {
                countStay++;
            }
            countCross++; 
        }
        
    }
    printf("%d\n%d",countCross,countStay);

	return 0;
}