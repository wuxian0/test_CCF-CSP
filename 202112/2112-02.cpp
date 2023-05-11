/**
 * 序列查询新解
 * 
 * 
 * 
 * 70
 * 
 * 放弃了 分段做了5分
 * 
 * 昨天做太多了，脑子烧了，转不过弯
 * ----------------------------------------
 * 运行错误，没报超时，不知道哪个细节被忽略了
 * 修改了f的存储，直接报错
 * 
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,N;
    int A[100010] = {0};
    int g;
    int f;
    long sumf = 0;
    long sumg = 0;
    long sum = 0;
    scanf("%d%d",&n,&N);
    int r = N/(n+1);

    int index = 1;

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&A[i]);
        for(int j = A[i-1]; j < A[i]; )
        {
            g = j/r;
            if(g < i-1)
            {
                if(j%r == 0)
                {
                    if( j+r < A[i])
                    {
                        sumg += g * r;
                        sumf += (n) * r;
                        j += r;
                    }
                    else if( j+r == A[i])
                    {
                        sumg += g * r;
                        sumf += (n) * r;
                        j = A[i]+1;
                    }
                    else
                    {
                        sumg += (A[i]-i)*g;
                        sumf += (A[i]-i) * (n);
                        j = A[i]+1;
                    }
                }
                else
                {
                    sumg += g * (j%r);
                    sumf += (i) * r;
                    j += (j%r);
                }
            }
            else if( g == i-1)
            {
                sum = abs(sumf-sumg);
                sumf = 0;
                sumg = 0;
                j++;

            }
            else
            {
                if(j%r == 0)
                {
                    if( j+r < A[i])
                    {
                        sumg += g * r;
                        sumf += (n) * r;
                        j += r;
                    }
                    else if( j+r == A[i])
                    {
                        sumg += g * r;
                        sumf += (n) * r;
                        j = A[i]+1;
                    }
                    else
                    {
                        sumg += (A[i]-i)*g;
                        sumf += (A[i]-i) * (n);
                        j = A[i]+1;
                    }
                }
                else
                {
                    sumg += g * (j%r);
                    sumf += (i) * r;
                    j += (j%r);
                }
            }
        }
        // sumf += (A[i]-A[i-1])*(i-1);  
    }
    sum += abs(sumf - sumg);

    sumg = 0;
    sumf = 0;
    for(int i = A[n]; i <= N;)
    {
        g = i / r;
        if(g < n)
        {
            if(i%r == 0)
            {
                if( i+r < N)
                {
                    sumg += g * r;
                    sumf += (n) * r;
                    i += r;
                }
                else if( i+r == N)
                {
                    sumg += g * r;
                    sumf += (n) * r;
                    i = N+1;
                }
                else
                {
                    sumg += (N-i)*g;
                    sumf += (N-i) * (n);
                    i = N+1;
                }
            }
            else
            {
                    sumg += g * (i%r);
                    sumf += (n) * r;
                    i += (i%r);
            }
        }
        else if( g == n)
        {
            sum += abs( sumg - sumf);
            sumg = 0;
            sumf = 0;
            i++;
        }
        else
        {
            if(i%r == 0)
            {
                if( i+r < N)
                {
                    sumg += g * r;
                    sumf += (n) * r;
                    i += r;
                }
                else if( i+r == N)
                {
                    sumg += g * r;
                    sumf += (n) * r;
                    i = N+1;
                }
                else
                {
                    sumg += (N-i)*g;
                    sumf += (N-i) * (n);
                    i = N+1;
                }
            }
            else
            {
                    sumg += g * (i%r);
                    sumf += (n) * r;
                    i += (i%r);
            }

        }

    }
    sum = sum + abs(sumg - sumf);

    // int index = 0;
    // for(int i = 0; i < N; i++)
    // {
    //     g = i / r;
    //     if(i < A[index])
    //     {
    //         f = (index - 1 > 0)?(index-1):0;
    //     }
    //     else if( i == A[index])
    //     {
    //         f= index;
    //         if(index <= n)
    //         {
    //             index++;
    //         }
            
    //     }
    //     sum += abs(g-f);   
    // }
    printf("%ld",sum);
    return 0;
}

//     scanf("%d%d",&n,&N);
//     int r = N/(n+1);

//     int index = 1;

//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d",&A[i]);
//     }

//     int index = 0;
//     for(int i = 0; i < N; i++)
//     {
//         g = i / r;
//         if(i < A[index])
//         {
//             f = (index - 1 > 0)?(index-1):0;
//         }
//         else if( i == A[index])
//         {
//             f= index;
//             if(index <= n)
//             {
//                 index++;
//             }
            
//         }
//         sum += abs(g-f);   
//     }
//     printf("%ld",sum);
//     return 0;
// }

// // 修改f保存方法，本地可以，提交报错
// int main()
// {
//     long n,N;
//     // int f[1000000001] = {0};
//     long A[100001] = {0};
//     long f[3][100001] = {0};
//     long g = 0;
//     long long sum = 0;
//     long r;

//     scanf("%ld%ld",&n,&N);
//     r = N/(n+1);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%ld",&A[i]);   
//     }

//     // 存储值及起始终止坐标
//     for(int i = 0; i <= n; i++)
//     {
//         f[i][0] = i;
//         f[i][1] = A[i];
//         if(i == n)
//         {
//             f[i][2] = N-1;
//         }
//         else{
//             f[i][2] = A[i+1]-1;
//         }
        
//     }
//     long temp;
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; j <=n; j++)
//         {
//             if(i>= f[j][1] && i<= f[j][2])
//             {
//                 temp = f[j][0];
//                 break;
//             }
//         }
//         g = i/r; 
//         sum += abs(temp - g);
//     }

//     printf("%lld",sum);

// 	return 0;
// }

// 70 
// #include<stdio.h>
// #include<math.h>
// #include<string.h>

// int main()
// {
//     int n,N;
//     // int f[1000000001] = {0};
//     long A[100001] = {0};
//     long f[10000001] = {0};
//     long g = 0;
//     long long sum = 0;
//     long r;

//     scanf("%d%ld",&n,&N);
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