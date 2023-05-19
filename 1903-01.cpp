/**
 * 小中大
 * 
 * 100
 * 
 * 中位数 除以2可能为小数，所以直接比较 2min 2mid 2max，输出时确定小数位
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool comp(int a, int b)
{
    if(a > b)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    int min,max;
    int midtemp = 0;
    int temp;
    int flag = 0;
    int a[3] = {0};
    scanf("%d",&n);
    if(n%2 == 0)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    scanf("%d",&min);

    for(int i = 2; i < n; i++)
    {
        scanf("%d",&temp);
        if(flag)
        {
            if(i == n/2)
            {
                midtemp += temp;
            }
            if(i == (n/2 +1))
            {
                midtemp += temp;
            }
        }
        else
        {
            if( i == (n/2 +1) )
            {
                midtemp += temp;
                midtemp *= 2;
            }
        }
    }

    scanf("%d",&max);
    a[0] = min * 2;
    a[1] = midtemp;
    a[2] = max * 2;

    sort(a,a+3,comp);

    for(int i = 0; i < 3; i++)
    {
        if(a[i]%2 == 0)
        {
            printf("%d ",a[i]/2);
        }
        else
        {
            printf("%.1f ", 1.0*(a[i]+0.05)/2);
        }
    }

	

	return 0;
}