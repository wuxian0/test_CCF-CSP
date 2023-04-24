/**
 * 
 * 100
 * 
 * 关键路径问题
 * 每项科目最多只依赖一项别的科目，理解错了，以为是一对一依赖，可以是多个依赖同一个
 * 对于当前项被多个依赖时，会被多次更新
*/

#include<stdio.h>

int main()
{
    int m,n;
    int a[4][101] = {0};
    //标志位，n天完成为1，否则为0
    int flag = 1;

    scanf("%d%d",&n,&m);

    //依赖
    for(int i = 1; i<=m; i++)
    {
        scanf("%d",&a[0][i]);
    }

    //天数
    for(int i = 1; i<=m; i++)
    {
        scanf("%d",&a[1][i]);
    }

    //最早完成
    for(int i = 1; i <= m; i++)
    {
        //无依赖
        if(a[0][i] == 0)
        {
            a[2][i] = 1;
        }
        else{
            a[2][i] = a[2][a[0][i]] + a[1][a[0][i]];

        }
        if( (a[2][i]+a[1][i]-1) > n)
        {
            flag = 0;
        }
        printf("%d ",a[2][i]);
    }
    printf("\n"); 
    

    if( flag == 1)
    {
        for(int i =m; i >= 1; i--)
        {
            if( a[3][i] == 0)
            {
                a[3][i] = n - a[1][i] + 1;
            }
            if( a[0][i] != 0)
            {
                if(a[3][a[0][i]] != 0)
                {
                    a[3][a[0][i]] =  (a[3][a[0][i]] )<(a[3][i] - a[1][a[0][i]])?(a[3][a[0][i]] ):(a[3][i] - a[1][a[0][i]]);
                }
                else{
                    a[3][a[0][i]] = a[3][i] - a[1][a[0][i]];
                }      
            }

        }
        for(int i = 1; i <= m; i++)
        {
            printf("%d ",a[3][i]);
        }
            printf("\n"); 
    }
    return 0;
}