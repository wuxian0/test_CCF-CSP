/**
 * 数组推导
 * 
 * 100
 * 
 * last存储上次读入数据，与当前值比较
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;
    int summax = 0;
    int summin = 0;

    int now = 0;
    int last = 0;

    scanf("%d",&n);
    
    scanf("%d",&now);
    last = now;
    summax+=now;
    summin+=now;

    for(int i = 1; i < n; i++)
    {
        scanf("%d",&now);
        if(now == last)
        {
            summax += now;
            summin += 0;
        }
        else{
            summax += now;
            summin += now;
            last = now;
        }
    }
    
    printf("%d\n%d",summax,summin);

	return 0;
}