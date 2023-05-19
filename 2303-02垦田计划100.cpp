/**
 * 垦田计划
 * 
 * 100%
 * 
 * 70卡住了两天，发现是数组写错了,10^5 一直用10^4存储 一直报错 -_-!
 * 
 * 设置数组，读入数据是，索引对应最初天数，值为所需资源，相同天数所需资源进行叠加
 * 记录最长时间
 * 从最长时间开始遍历，资源足够时，a[i]消耗资源，时间-1，所需资源并入a[i-1]
*/
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int n,m,k;
    int ans = -1;
    long totalNeed = 0;
    int day = 0;
    int need = 0;
    long long a[100001]={0};

    scanf("%d%d%d",&n,&m,&k);
    for(int i =1; i <= n; i++)
    {
        // 读入数据
        scanf("%lld%lld",&day,&need);
        // 记录最长时间
        a[day]+= need;
        if(ans < day)
        {
            ans = day;
        }
    }

    while(ans > k && m > 0)
    {
        // 判断资源是否足够
        if( m/a[ans] >= 1)
        {
            // 消耗资源缩短天数
            m -= a[ans];
            a[ans-1] += a[ans];
            ans--;
        }
        else
        {
            break;
        }
    }
    printf("%d",ans);

    return 0;
}
// int main(){
//     int n,m,k;
//     int ans = -1;
//     int totalNeed = 0;


//     scanf("%d%d%d",&n,&m,&k);
//     for(int i =0; i < n; i++)
//     {
//         // 读入数据
//         scanf("%d%d",&a[i][0],&a[i][1]);
//         // 记录最长时间
//         if(ans < a[i][0])
//         {
//             ans = a[i][0];
//         }
//     }
//     while(true)
//     {
//         totalNeed = 0;
//         if(ans == k)
//         {
//             break;
//         }
//         // 遍历最大值所需要的资源总量
//         for(int i = 0; i<n; i++){
//             if(a[i][0] == ans)
//             {
//                 totalNeed += a[i][1];
//             }
//         }
//         // 判断资源是否足够
//         if( m/totalNeed >= 1)
//         {
//             // 消耗资源缩短天数
//             m -= totalNeed;
//             for(int i = 0; i<n; i++)
//             {
//                 if(a[i][0] == ans)
//                 {
//                     a[i][0]--;
//                 }
//             }
//             // 更新最小值
//             ans--;
//         }
//         else
//         {
//             break;
//         }
//     }
//     printf("%d",ans);

//     return 0;
// }