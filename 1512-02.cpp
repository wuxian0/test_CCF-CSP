/**
 * 消除类游戏
 * 
 * 100
 * 
 * 前缀和的思想？分别记录连续相同数字的数量
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    int a[31][31] = {0};
    int left[31][31] = {0};
    int up[31][31] = {0};
    int deleteList[(31*31)][4] = {0};//[0][1]坐标 [2]数量 [3]方向1上 2左
    int total = 0;

    scanf("%d%d",&n, &m);

    for(int i =1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] == a[i-1][j])
            {
                up[i][j] = up[i-1][j] + 1;                
            }
            else
            {
                up[i][j] = 1;
            }
            if(up[i][j] < up[i-1][j] && up[i-1][j] >= 3)
            {
                total++;
                deleteList[total][0] = i-1;
                deleteList[total][1] = j;
                deleteList[total][2] = up[i-1][j];
                deleteList[total][3] = 1;
            }
            else if( i == n && up[i][j] >=3)
            {
                total++;
                deleteList[total][0] = i;
                deleteList[total][1] = j;
                deleteList[total][2] = up[i][j];
                deleteList[total][3] = 1;

            }



            if(a[i][j] == a[i][j-1])
            {
                left[i][j] = left[i][j-1] + 1;                
            }
            else
            {
                left[i][j] = 1;
            }
            if(left[i][j] < left[i][j-1] && left[i][j-1] >= 3)
            {
                total++;
                deleteList[total][0] = i;
                deleteList[total][1] = j-1;
                deleteList[total][2] = left[i][j-1];
                deleteList[total][3] = 2;
            }
            else if( j == m && left[i][j] >=3)
            {
                total++;
                deleteList[total][0] = i;
                deleteList[total][1] = j;
                deleteList[total][2] = left[i][j];
                deleteList[total][3] = 2;
            }
        }
    }
    for(int i = 1; i <= total; i++)
    {
        if(deleteList[i][3] == 1)
        {
            for(int cnt = (deleteList[i][2]-1); cnt >= 0; cnt --)
            {
                a[ deleteList[i][0]-cnt ][deleteList[i][1]] = 0;
            }
        }
        else if(deleteList[i][3] == 2)
        {
            for(int cnt = (deleteList[i][2]-1); cnt >= 0; cnt --)
            {
                a[ deleteList[i][0] ][deleteList[i][1]-cnt] = 0;
            }
        }
    }

    for(int i =1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    }


    
	

	return 0;
}