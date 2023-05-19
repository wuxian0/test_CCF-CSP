/**
 * 线性分类器
 * 
 * 100
 * 
 * 判断 点到直线距离公式的分子去掉绝对值符号
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct 
{
    int x;
    int y;
    char c;
} Dot;
int main()
{
    int n,m;
    Dot dotA[1000];
    Dot dotB[1000];
    int countA = 0;
    int countB = 0;
    int answer[21] = {0};

    int param1,param2,param3;


    scanf("%d%d",&n,&m);

    int p,q;
    char ch;
    for(int i = 1; i <= n; i++ )
    {
        scanf("%d %d %c",&p,&q,&ch);
        if(ch == 'A')
        {
            countA++;
            dotA[countA].x = p;
            dotA[countA].y = q;
            dotA[countA].c = ch;
        }
        else
        {
            countB++;
            dotB[countB].x = p;
            dotB[countB].y = q;
            dotB[countB].c = ch;

        }
    }
    bool flagA = false;
    bool flagB = true;
    int dist = 0.0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&param1,&param2,&param3);
        for(int j = 1; j <= countA; j++)
        {
            dist = param1 + param2 * dotA[j].x + param3 * dotA[j].y;
            if(j == 1)
            {
                flagA = dist > 0;
            }
            else
            {
                if(flagA != (dist > 0))
                {
                    answer[i] = 1;
                    break;
                }
            }
        }
        if(answer[m] == 0)
        {
            for(int j = 1; j <= countB; j++)
            {
                dist = param1 + param2 * dotB[j].x + param3 * dotB[j].y;
                // printf("%d %d %d\n",dotB[j].x,dotB[j].y,dist);
                if(j == 1)
                {
                    flagB = (dist > 0);
                    if(flagB == flagA)
                    {
                        answer[i] = 1;
                        break;
                    }
                }
                else
                {
                    if(flagB != (dist > 0))
                    {
                        answer[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(answer[i] == 0)
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