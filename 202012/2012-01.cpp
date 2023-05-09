
/**
 * 期末预测之安全指数
 * 
 * 100
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;
    int sum = 0;

    scanf("%d",&n);

    int s,ww;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d",&ww,&s);
        sum += ww * s;
    }
    sum = sum > 0 ? sum : 0;

    printf("%d",sum);
	

	return 0;
}