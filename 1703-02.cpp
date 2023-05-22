/**
 * 学生排队
 * 
 * 100 
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct Node
{
    int x;
    int pos;

} node;

bool comp(node a, node b)
{
    if(a.pos < b.pos)
    {
        return true;
    }
    return false;
}


int main()
{
    int n;
    int m;
    int index, dist;
    scanf("%d",&n);
    scanf("%d",&m);

    node list[1010];

    for(int i = 1; i <= n; i++)
    {
        list[i].pos = i;
        list[i].x = i;
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d",&index, &dist);
        for(int j = 1; j <= n; j++)
        {
            if( list[j].x == index)
            {
                list[j].pos += dist;
                if( dist > 0)
                {
                    for(int h = 1; h <= dist; h++)
                    {
                        list[j+h].pos--;
                    }
                }
                else if(dist < 0)
                {
                    for(int h = -1; h >= dist; h--)
                    {
                        list[j+h].pos++;
                    }

                }
                sort(list+1,list+n+1,comp);
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", list[i].x);
    }

	return 0;
}