/**
 * 报数
 * 
 * 100
 * 
 * 70 写了个count<=n
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

bool func7(int m)
{
    if(m%7 == 0)
    {
        return true;
    }
    else
    while(m)
    {
        if(m%10 == 7)
        {
            return true;
        }
        m /= 10;
    }
    return false;
}
int main()
{
    int a[5] = {0};

    int n;
    scanf("%d",&n);
    int count= 0;

    for(int i = 1 ; count < n;i++ )
    {
        // count++;
        if(func7(i))
        {
            if(i%4 == 0)
            {
                a[4]++;
            }
            else
            {a[i%4]++;}
        }
        else{
            count++;
        }
    }
    for(int i = 1; i < 5; i++)
    {
        printf("%d\n",a[i]);
    }


	return 0;
}