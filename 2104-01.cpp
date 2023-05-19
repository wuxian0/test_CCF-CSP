/**
 * 灰度直方图
 * 
 * 100
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,m,L;
    int h[250000] = {0};
    int max = 0;
    int temp;
    
    scanf("%d%d%d",&n,&m,&L);

    for(int i = 0 ; i < n*m; i++)
    {
        scanf("%d",&temp);
        if(temp > max)
        {
            max = temp;
        }
        h[temp]++;
    }
    for(int i = 0; i <= max; i++)
    {
        printf("%d ",h[i]);
    }

	return 0;
}