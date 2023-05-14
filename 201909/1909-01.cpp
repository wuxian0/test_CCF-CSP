/**
 * 小明种苹果
 * 
 * 100
 * 
 * 注意给的负数
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,m;

    int a[1010][3] = {0};
    int max = -1;
    int maxid = 0;
    int sum = 0;

    scanf("%d%d",&n,&m);
    
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i][0]);
        int temp = 0;
        for(int j = 1; j <= m; j++)
        {
            scanf("%d",&temp);
            a[i][1] += temp;
        }
        sum += (a[i][0] + a[i][1]);
        if(max < abs(a[i][1]))
        {
            max = abs(a[i][1]);
            maxid = i;
        }

    }
    printf("%d %d %d", sum, maxid, max);
	

	return 0;
}