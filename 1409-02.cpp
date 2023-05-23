/**
 * 画图
 * 
 * 100
 * 
 * 区别 坐标点和方格的差异
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int a[110][110] = {0};
    int n;
    scanf("%d", &n);
    int sum = 0;

    int x1,x2,y1,y2;
    for(int h = 1; h <= n; h++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int i = x1; i <= x2-1; i++)
        {
            for(int j = y1; j <= y2-1; j++)
            {
                if(a[i][j] == 0)
                {
                    sum++;
                    a[i][j] = 1;
                }
                
            }
        }
    }
    printf("%d\n", sum);

	return 0;
}