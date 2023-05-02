/**
 * 寻宝！大冒险！
 * 100
 * 暴力 空间不够分配
 * 只存储有树的坐标
 * 
*/

#include<stdio.h>

int main()
{
    int n,L,S;
    int mapFull[1000][3];
    int mapPart[50][50];
    int count = 0;
    
    int row,col;
    int temp;

    scanf("%d%d%d",&n,&L,&S);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&row,&col);
        mapFull[i][0] = row;
        mapFull[i][1] = col;
    }
    for (int i = 0; i < n; i++ )
    {
        for (int j = i+1; j < n; j++ )
        if(mapFull[i][0] >= mapFull[j][0])
        {
            if(mapFull[i][1] > mapFull[j][1])
            {
                temp = mapFull[i][0];
                mapFull[i][0] =mapFull[j][0];
                mapFull[j][0] = temp;
                temp = mapFull[i][1];
                mapFull[i][1] =mapFull[j][1];
                mapFull[j][1] = temp;
            }
        }
    }

    for (int i = S; i >=0; i-- )
    {
        for (int j = 0; j <= S; j++ )
        {
            scanf("%d",&mapPart[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(mapFull[i][0] > L-S || mapFull[i][1] > L-S)
        {continue;}
        int flag = 1;
        int hasTree = 0;
        row = mapFull[i][0];
        col = mapFull[i][1];
        for(int p = 0; p<=S; p++)
        {
            if(flag == 0)
            {
                break;
            }
            for (int q = 0;q <= S;q++)
            {
                hasTree = 0;
                for(int j = 0; j<n; j++)
                {
                    if(mapFull[j][0] == row+p && mapFull[j][1] == col+q)
                    {
                        hasTree = 1;
                        break;
                    }    
                }
                if (hasTree != mapPart[p][q])
                {
                    flag = 0;
                    break;
                }
                
            }   
        }
        if(flag == 1)
        {count++;}
    }

    printf("%d",count);
    
    



    return 0;
}