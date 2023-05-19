/**
 * 小明上学
 * 
 * 100
 * 
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int r,y,g;
    int n;
    int sum = 0;
    int k,t;


    scanf("%d%d%d", &r, &y, &g);
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &k, &t);

        switch(k)
        {
            case 2: sum += (t+r);
            break;
            case 1: sum += t;
            break;
            case 0: sum += t;
            break;
        }
    }

    printf("%d",sum);
	

	return 0;
}