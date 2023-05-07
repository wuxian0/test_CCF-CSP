/**
 * 序列查询新解
 * 
 * 70
 * 运行错误，没报超时，不知道哪个细节被忽略了
 * 修改了f的存储，直接报错
 * 
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

// 修改f保存方法，本地可以，提交报错
int main()
{
    long n,N;
    // int f[1000000001] = {0};
    long A[100001] = {0};
    long f[3][100001] = {0};
    long g = 0;
    long long sum = 0;
    long r;

    scanf("%ld%ld",&n,&N);
    r = N/(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%ld",&A[i]);   
    }

    // 存储值及起始终止坐标
    for(int i = 0; i <= n; i++)
    {
        f[i][0] = i;
        f[i][1] = A[i];
        if(i == n)
        {
            f[i][2] = N-1;
        }
        else{
            f[i][2] = A[i+1]-1;
        }
        
    }
    long temp;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <=n; j++)
        {
            if(i>= f[j][1] && i<= f[j][2])
            {
                temp = f[j][0];
                break;
            }
        }
        g = i/r; 
        sum += abs(temp - g);
    }

    printf("%lld",sum);

	return 0;
}

// 70 
// #include<stdio.h>
// #include<math.h>
// #include<string.h>

// int main()
// {
//     long n,N;
//     // int f[1000000001] = {0};
//     long A[100001] = {0};
//     long f[10000001] = {0};
//     long g = 0;
//     long long sum = 0;
//     long r;

//     scanf("%ld%ld",&n,&N);
//     r = N/(n+1);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%ld",&A[i]);   
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
//         g = i/r; 

//         sum += abs(f[i] - g);

//     }

//     printf("%lld",sum);

// 	return 0;
// }