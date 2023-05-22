/**
 * 火车购票
 * 
 * 100
 * 
 * 最近两道写着繁琐，不过不难
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int a[30][6] = {0};

    int n;
    int temp;
    // 标志位
    int flag = 0;

    scanf("%d",&n);

    for(int i = 1; i <= n; i++)
    {
        flag = 0;
        scanf("%d",&temp);

        // 连票
        for(int j = 1; j <= 20; j++)
        {
            // 座位足够
            if(temp <= ( 5 - a[j][0]) )
            {
                // 判断相连
                if( (temp == 5))
                {
                    a[j][1] = 1;a[j][2] = 1;a[j][3] = 1;a[j][4] = 1;a[j][5] = 1;
                    a[j][0] = 5;
                    printf("%d %d %d %d %d\n", (j-1)*5+1, (j-1)*5+2,(j-1)*5+3,(j-1)*5+4,(j-1)*5+5);
                    flag = 1;
                    break;
                }
                else if( (temp == 4) && (a[j][1] != 1 || a[j][5] != 1))
                {
                    for(int h = 1; h <= 2; h++)
                    {
                        if( (a[j][h] == 0) && (a[j][h+1] == 0) && (a[j][h+2] == 0) && (a[j][h+3] == 0) )
                        {
                            printf("%d %d %d %d\n", (j-1)*5 + h, (j-1)*5 + h + 1, (j-1)*5 + h +2, (j-1)*5 + h + 3);
                            a[j][h] = 1;a[j][h+1] = 1;a[j][h+2] = 1;a[j][h+3] = 1;
                            a[j][0]+=4;
                            flag = 1;
                            break;
                        } 
                    }
                    if(flag)
                    {break;}
                }
                else if((temp == 3) && (a[j][3] != 1))
                {
                    for(int h = 1; h <= 3; h++)
                    {
                        if( (a[j][h] == 0) && (a[j][h+1] == 0) && (a[j][h+2] == 0) )
                        {
                            printf("%d %d %d\n", (j-1)*5 + h, (j-1)*5 + h + 1, (j-1)*5 + h +2);
                            a[j][h] = 1;a[j][h+1] = 1;a[j][h+2] = 1;
                            a[j][0]+=3;
                            flag = 1;
                            break;
                        }  
                    }
                    if(flag)
                    {break;}
                }
                else if(temp == 2)
                {
                    for(int h = 1; h <= 4; h++)
                    {
                        if( (a[j][h] == 0) && (a[j][h+1] == 0) )
                        {
                            printf("%d %d\n", (j-1)*5 + h, (j-1)*5 + h +1);
                            a[j][h] = 1;
                            a[j][h+1] = 1;
                            a[j][0]+=2;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag)
                    {break;}
                }
            }
        }
        if(flag == 1)
        {
            continue;
        }

        // 间隔
        int count = 0;
        for(int j = 1; j <= 20; j++)
        {
            if(a[j][0] == 5)
            {continue;}
            for(int h = 1; h <= 5; h++)
            {
                if(a[j][h] == 0)
                {
                    printf("%d ",(j-1)*5 + h);
                    a[j][h] = 1;
                    a[j][0]++;
                    count++;
                    if(count == temp)
                    {
                        break;
                    }
                }
            }
            if(count == temp)
            {
                printf("\n");
                break;
            }
        }

    }
	

	return 0;
}