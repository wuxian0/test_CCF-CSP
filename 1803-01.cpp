/**
 * 跳一跳
 * 
 * 100
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int getScore(int p, int lastS)
{
    if(p == 1)
    {
        return 1;
    }
    else if( p == 2 )
    {
        if(lastS == 0 || lastS == 1)
        {
            return 2;
        }
        else
        {
            return lastS+2;
        }
    }
    return 0;
}

int main()
{
    int pos;
    int lastPos = 0;
    int lastScore = 0;
    int sum = 0;
    int score = 0;

    scanf("%d",&pos);
    
    while( pos != 0 )
    {
        score = getScore(pos, lastScore);
        sum += score;
        lastScore = score;
        lastPos = pos;
        scanf("%d",&pos);
    }

    printf("%d",sum);
    
	

	return 0;
}