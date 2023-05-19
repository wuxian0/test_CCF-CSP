/**
 * 小明种苹果（续）
 * 
 * 100
 * 
 * 同一棵树可能多次检查到脱落情况，需要判断之前是否脱落，或者遍历时在统计D
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,m;

    // 依次为 总数 蔬果数量 脱落标志位
    int a[1010][3] = {0};
    int max = -1;
    int maxid = 0;
    int sum = 0;
    int D = 0;
    int E = 0;

    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        scanf("%d",&a[i][0]);
        int temp = 0;
        for(int j = 1; j < m; j++)
        {
            scanf("%d",&temp);
            // 蔬果
            if(temp <= 0)
            {
                a[i][1] += temp;
            }
            else
            {
                a[i][2] = ((a[i][0] + a[i][1]) == temp)?0:1;
                // 发生脱落 更新总数，蔬果置0
                if(a[i][2])
                {
                    a[i][0] = temp;
                    a[i][1] = 0;
                }
            }
            
        }
        // sum += (a[i][0] + a[i][1]);
        // if(max < abs(a[i][1]))
        // {
        //     max = abs(a[i][1]);
        //     maxid = i;
        // }
    }

    for(int i = 0; i < n; i++)
    {
        sum += (a[i][0] + a[i][1]);
        if(a[i][2] == 1)
        {
            D++;
            // printf("+%d\n",i);
        }
        if( (a[i][2] == 1) && (a[(i+1)%n][2] == 1) && (a[(i+2)%n][2] == 1))
        {
            // printf("%d %d %d\n",i,(i+1)%n,(i+2)%n);
            E++;
        }
    }
    printf("%d %d %d", sum, D, E);
	

	return 0;
}