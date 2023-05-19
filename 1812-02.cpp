/**
 * 小明放学
 * 
 * 100
 * 估摸了int不够用，已经用了 long ，没想到不够用，long long解决问题，这。。。
 * 基础不牢地动山摇
 * 60
 * 
 * 做的有点晕了
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int r,y,g;
    int n;
    long long sum;
    int k,t;
    int temp = 0;


    scanf("%d%d%d", &r, &y, &g);
    scanf("%d", &n);

    sum = 0;
    for(int i = 0; i < n; i++)
    {
        temp = 0;
        
        scanf("%d%d", &k, &t);
        // temp = (sum - t) % (r+y+g);
        if(k == 0)
        {
            sum += t;
            // printf("路段 耗时 %d,累计:%d\n",t,sum);
        }
        else if( k == 1)
        {
            if(sum >= t)
            {
                temp = ( sum - t) % (r+y+g);
                temp = r+y+g - temp;
            }
            else
            {
                temp = abs( sum - t) % (r+y+g);
            }
            if( temp < r + y)
            {
                sum += temp;
                // printf("红灯 耗时 %d,累计:%d\n",temp,sum);
            }
        }
        else if( k == 2)
        {
            if(sum >= t+r)
            {
                temp = ( sum - t - r) % (r+y+g);
                temp = r+y+g - temp;
            }
            else
            {
                temp = abs( sum - t - r) % (r+y+g);
            }
        
            if( temp < r + y)
            {
                sum += temp;
                // printf("红灯 耗时 %d,累计:%d\n",temp,sum);
            }
        }
        else if( k == 3)
        {
            if(sum >= t+r+y)
            {
                temp = ( sum - t - r - y ) % (r+y+g);
                temp = r+y+g - temp;
            }
            else
            {
                temp = abs( sum - t - r - y) % (r+y+g);
            }
            if( temp <= r + y)
            {
                sum += temp;
                // printf("红灯 耗时 %d,累计:%d\n",temp,sum);
            }
        }
        // printf("%d\n",temp);
        // printf("sum : %ld\n",sum);
    }

    printf("%lld",sum);
	

	return 0;
}