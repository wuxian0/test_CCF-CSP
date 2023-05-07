/**
 * 出行计划
 * 
 * 70 遍历，运行超时
 * 100 前缀和
 * 前缀和计算后，恢复原始数据时循环结束位置不是n，对整个数组计算
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

// 前缀和
int main()
{
    int n,m,k;
    int t,c;
    int q;
    int qstart,qend;
    int answer[200001] = {0};

    
    scanf("%d%d%d",&n,&m,&k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&t,&c);
        qstart = (t-k-c+1 > 1) ? (t-k-c+1) : 1;
        qend = (t-k+1 > 1) ? (t-k+1) : 1;
        answer[qstart]++;
        answer[qend]--;
    }
    for(int i = 1; i <= 200000; i++)
    {
        answer[i] += answer[i-1];
    }


    for(int i = 1; i <= m; i++)
    {
        scanf("%d",&q);
        printf("%d\n",answer[q]);
    }
    

	return 0;
}

// 70

// int main()
// {
//     int n,m,k;
//     int a[100001][2];
//     int start,limit;
//     int q;
//     int qstart,qend;
//     int answer[100001] = {0};

    
//     scanf("%d%d%d",&n,&m,&k);

//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d%d",&a[i][0],&a[i][1]);
//     }

//     for(int i = 1; i <= m; i++)
//     {
//         scanf("%d",&q);
//         qstart = q + k;
//         for(int j = 1; j <= n; j++)
//         {
//             if(qstart <= a[j][0] && (qstart + a[j][1] -1 ) >= a[j][0])
//             {
//                 answer[i]++;
//             }
//         }
//     }
    
//     for(int i = 1; i <= m; i++)
//     {
//         printf("%d\n",answer[i]);
//     }

// 	return 0;
// }