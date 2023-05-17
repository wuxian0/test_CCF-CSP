/**
 * 卖菜
 * 
 * 100
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;
    int a[1010] = {0};

    scanf("%d",&n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("%d ", (a[1] + a[2])/2);

    for(int i = 2; i < n; i++)
    {
        printf("%d ", (a[i-1] + a[i] + a[i+1])/3);
    }

    printf("%d ", (a[n-1] + a[n])/2);
	

	return 0;
}