/**
 * 回收站选址
 * 
 * 100
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<algorithm>

using namespace std;


typedef struct
{
    int x;
    int y;
} Posit;

bool comp(Posit A, Posit B)
{
    if((A).x < (B).x)
    {
        return true;
    }
    else if( (A).x == (B).x && (A).y < (B).y)
    {
        return true;
    }

    return false;
}


int main()
{
    int n;
    int result[5] = {0};
    int p,q;

    scanf("%d",&n);
    Posit * posit = (Posit *)malloc( sizeof(Posit) * (n + 10));

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &((*(posit+i)).x), &((*(posit+i)).y));
        
    }

    sort(posit+1, posit+n+1, comp);

    for(int i = 1; i <= n; i++)
    {
        int count = 0;
        int score = 0;

        // 遍历
        for(int j = 1; j <= n; j++)
        {
            if( i == j)
            {
                continue;
            }
            else if( abs((posit+j)->x - ((posit+i)->x)) == 1 && (posit+j)->y == ((posit+i)->y) )
            {
                count++;
                // printf("%d %d (%d):%d %d\n",(posit+i)->x,(posit+i)->y,count,(posit+j)->x,(posit+j)->y);
            }
            else if( abs((posit+j)->y - ((posit+i)->y)) == 1 && (posit+j)->x == ((posit+i)->x))
            {
                count++;
                // printf("%d %d (%d):%d %d\n",(posit+i)->x,(posit+i)->y,count,(posit+j)->x,(posit+j)->y);
            }
            else if( abs((posit+j)->y - ((posit+i)->y)) == 1 && abs((posit+j)->x - ((posit+i)->x)) ==1)
            {
                score++;
                // printf("%d %d:%d\n",(posit+i)->x,(posit+i)->y,score);
            }
        }

        if(count == 4)
        {
            result[score]++;
            // printf("%d %d:%d\n",(posit+i)->x,(posit+i)->y,score);
        }       
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     printf("%d %d\n", (*(posit+i)).x,(*(posit+i)).y);
    // }


    for(int i = 0; i <= 4; i++)
    {
        printf("%d\n",result[i]);
    }

	

	return 0;
}