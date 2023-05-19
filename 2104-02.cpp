/**
 * 邻域均值
 * 
 * 100
 * 
 * 
 * 70
 * 超时
 * 搜了一下，前缀数组，又是前缀和，这个方法出现很多次
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,L,r,t;
    const int N = 610;
    int A[N][N] = {0};
    double sum[N][N] = {0.0};
    int answer = 0;
    int temp;

    scanf("%d%d%d%d",&n,&L,&r,&t);

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            scanf("%d",&temp);
            A[i][j] = A[i-1][j] + A[i][j-1] - A[i-1][j-1] + temp;
        }
        

    }
    // printf("`````````````````````````\n");
    // for(int i = 1 ; i <= n; i++)
    // {
    //     for(int j = 1 ; j <= n; j++)
    //     {
    //         printf("%d ",A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("`````````````````````````\n");
    double avg = 0.0;
    int count = 0;
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            int x1,y1,x2,y2;
            x1 = (i-r > 1 ? i-r : 1);
            y1 = (j-r > 1 ? j-r : 1);
            x2 = (i+r > n ? n : i+r);
            y2 = (j+r > n ? n : j+r);
            avg = A[x2][y2] - A[x1-1][y2] - A[x2][y1-1] + A[x1-1][y1-1];
            count = (x2-x1+1) * (y2-y1+1);
            if(avg/count <= t)
            {
                answer++;
            }
        }
    }



    // 暴力
    // for(int i = 0 ; i < n; i++)
    // {
    //     for(int j = 0 ; j < n; j++)
    //     {
    //         int nei = 0;
    //         for(int x = i-r ; x <= i+r ; x++)
    //         {
    //             for(int y = j-r ; y <= j+r ; y++)
    //             {
    //                 if(x < 0 || y < 0 || x>=n||y>=n)
    //                 {continue;}
    //                 else
    //                 {
    //                     sum[i][j] += A[x][y]; 
    //                     nei++;
    //                 }
                    
    //             }
    //         }
    //         sum[i][j] /= nei;
    //         if(sum[i][j] <= t)
    //         {
    //             answer++;
    //         }

    //     }

    // }
    printf("%d",answer);


	return 0;
}