/**
 * 何以包邮
 * 
 * 85
 * 
 * 运行超时，提示枚举就嵌套一下
*/

#include<stdio.h>

int a[30];
int min = 1000000;
int main()
{
    int n,x;

    scanf("%d%d",&n,&x);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == x)
        {
            printf("%d",x);
            return 0;
        }
    }
    for(int a0 = 0; a0 <= 1; a0++)
    {
           for(int a1 = 0; a1 <= 1; a1++)
    {
            for(int a2 = 0; a2 <= 1; a2++)
    {
            for(int a3 = 0; a3 <= 1; a3++)
    {
            for(int a4 = 0; a4 <= 1; a4++)
    {
           for(int a5 = 0; a5 <= 1; a5++)
    {
            for(int a6 = 0; a6 <= 1; a6++)
    {
            for(int a7 = 0; a7 <= 1; a7++)
    {
            for(int a8 = 0; a8 <= 1; a8++)
    {
           for(int a9 = 0; a9 <= 1; a9++)
    {
            for(int a10 = 0; a10 <= 1; a10++)
    {
            for(int a11 = 0; a11 <= 1; a11++)
    {
            for(int a12 = 0; a12 <= 1; a12++)
    {
            for(int a13 = 0; a13 <= 1; a13++)
    {
            for(int a14 = 0; a14 <= 1; a14++)
    {
            for(int a15 = 0; a15 <= 1; a15++)
    {
           for(int a16 = 0; a16 <= 1; a16++)
    {
            for(int a17 = 0; a17 <= 1; a17++)
    {
            for(int a18 = 0; a18 <= 1; a18++)
    {
            for(int a19 = 0; a19 <= 1; a19++)
    {
           for(int a20 = 0; a20 <= 1; a20++)
    {
            for(int a21 = 0; a21 <= 1; a21++)
    {
            for(int a22 = 0; a22 <= 1; a22++)
    {
            for(int a23 = 0; a23 <= 1; a23++)
    {
           for(int a24 = 0; a24 <= 1; a24++)
    {
            for(int a25 = 0; a25 <= 1; a25++)
    {
            for(int a26 = 0; a26 <= 1; a26++)
    {
            for(int a27 = 0; a27 <= 1; a27++)
    {
            for(int a28 = 0; a28 <= 1; a28++)
    {
            for(int a29 = 0; a29 <= 1; a29++)
    {
        int total = a0*a[0]+ a1*a[1]+ a2*a[2]+ a3*a[3]+ a4*a[4]+ a5*a[5]+ a6*a[6]+ a7*a[7]+ a8*a[8]+ a9*a[9]+ a10*a[10]+ a11*a[11]+ a12*a[12]+ a13*a[13]+a14*a[14]+a15*a[15]+ a16*a[16]+ a17*a[17]+ a18*a[18]+ a19*a[19]+ a20*a[20]+ a21*a[21]+ a22*a[22]+ a23*a[23]+ a24*a[24]+ a25*a[25]+ a26*a[26]+ a27*a[27]+ a28*a[28]+a29*a[29];
        if(total >= x && total<min)
        {
            min = total;
        }
        if(min == x)
        {
            return 0;
        }
    }
    }
    } 
    }
    }
    } 
    }
    }
    }
    } 
    }
    }
    }
    } 
    }
    }
    }
    } 
    }
    }
    } 
    }
    }
    }
    } 
    }
    }
    }
    } 
    }
    printf("%d",min);

    return 0;
}