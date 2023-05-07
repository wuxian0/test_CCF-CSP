/**
 * 序列查询
 * 100
 * 
 * 下午头有点蒙 没太看明白，稀里糊涂过了，果然到下一题，又改了一次方法
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,N;
    int A[10000] = {0};

    int sum = 0;

    scanf("%d%d",&n,&N);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&A[i]); 
        sum += (A[i]-A[i-1])*(i-1);     
    }
    sum += n*(N-A[n]);
    printf("%d\n",sum);

	return 0;
}
// 为下一题，又改了一下
// int main()
// {
//     int n,N;
//     int A[10000001] = {0};
//     int f[10000001] = {0};
//     int g[10000001] = {0};
//     int sum = 0;
//     int r;

//     scanf("%d%d",&n,&N);
//     r = N/(n+1);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d",&A[i]);   
//     }

//     f[0] = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         f[ A[i]-1 ] = i-1;
//         f[ A[i] ] = i;   
//     }
//     for(int i = 0; i < N; i++)
//     {
//         if(f[i] == 0 && i>0)
//         {
//             f[i] = f[i-1];
//         }
        
//         sum+=f[i];
  
//     }
//     printf("%d",sum);

// 	return 0;
// }