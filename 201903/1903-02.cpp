/**
 * 二十四点
 * 
 * 100
 * 
 * 应该用栈的，忘得差不多了
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

char str[10];
char oper[5];
int a[5];
int result[110] = {0};


int main()
{
    int n;
    char * p;
    int temp = 0;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        int aindex = -1;
        int opindex = -1;
        scanf("%s",&str);
        p = str;
        aindex++;
        a[aindex] = *p - '0';
        p++;
        opindex++;
        oper[opindex] = *p;
        p++;
        aindex++;
        a[aindex] = *p - '0';
        p++;
        if(oper[opindex] == 'x')
        {
            a[aindex-1] = a[aindex-1] * a[aindex];
            aindex--;
            opindex--;
        }
        else if(oper[opindex] == '/')
        {
            a[aindex-1] = a[aindex-1] / a[aindex];
            aindex--;
            opindex--;
        }
        opindex++;
        oper[opindex] = *p;
        p++;
        aindex++;
        a[aindex] = *p - '0';
        p++;
        if(oper[opindex] == 'x')
        {
            a[aindex-1] = a[aindex-1] * a[aindex];
            aindex--;
            opindex--;
        }
        else if(oper[opindex] == '/')
        {
            a[aindex-1] = a[aindex-1] / a[aindex];
            aindex--;
            opindex--;
        }
        opindex++;
        oper[opindex] = *p;
        p++;
        aindex++;
        a[aindex] = *p - '0';
        if(oper[opindex] == 'x')
        {
            a[aindex-1] = a[aindex-1] * a[aindex];
            aindex--;
            opindex--;
        }
        else if(oper[opindex] == '/')
        {
            a[aindex-1] = a[aindex-1] / a[aindex];
            aindex--;
            opindex--;
        }
        int sum = a[0];
        for(int ii = 0; ii <= opindex; ii++)
        {
                if(oper[ii] == '+')
                {
                    sum += a[ii+1];
                }
                else if(oper[ii] == '-')
                {
                    sum -= ( a[ii+1]);
                }
        }
        // 符号问题
        // while(opindex != -1)
        // {
        //     if(oper[opindex] == '+')
        //     {
        //         a[aindex-1] = a[aindex-1] + a[aindex];
        //         aindex--;
        //         opindex--;
        //     }
        //     else if(oper[opindex] == '-')
        //     {
        //         a[aindex-1] = a[aindex-1] - a[aindex];
        //         aindex--;
        //         opindex--;
        //     }
        // }
        // printf("%d\n",sum);
        if(sum == 24)
        {
            result[i] =1;
        }   
    }
    for(int i = 0; i < n; i++)
    {
        if(result[i])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
	

	return 0;
}