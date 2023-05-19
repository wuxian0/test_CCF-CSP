/**
 * 未初始化警告
 * 
 * 100
 * 
 * 只要在左值出现，不管右值是否初始化，左值都被视为初始化
*/

#include<stdio.h>

int main()
{
    int n,k;
    int a[100001]= {0};
    a[0] = 1;

    int count = 0;

    scanf("%d%d",&n,&k);
    int left,right;
    for(int i = 1; i <= k; i++ )
    {
        scanf("%d%d",&left,&right);
        if(a[right] == 0)
        {
            count ++;
        }

        a[left] = 1;

    }
    printf("%d",count);

    return 0;
}