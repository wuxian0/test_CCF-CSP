/**
 * 买菜
 * 
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int min(int x, int y)
{
    return x>y?y:x;
}

int max(int x, int y)
{
    return x>y?x:y;
}

int main()
{
    int a[2010][2] = {0};
    int b[2010][2] = {0};

    int n;

    int sum = 0;

    scanf("%d",&n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d",&b[i][0],&b[i][1]);
    }

    int ia = 1;
    int ib = 1;
    while( (ia <= n) & (ib <= n))
    {
        // 区间不相交
        if(a[ia][1] <= b[ib][0])
        {
            ia++;
            continue;
        }
        else if(a[ia][0] >= b[ib][1])
        {
            ib++;
            continue;
        }

        sum += ( min(a[ia][1],b[ib][1]) - max(a[ia][0],b[ib][0]));
        if(a[ia][1] <= b[ib][1])
        {
            ia++;
        }
        else
        {
            ib++;
        }
    }

    printf("%d",sum);
	

	return 0;
}