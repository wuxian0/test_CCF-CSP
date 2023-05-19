/**
 * 期末预测之最佳阈值
 * 
 * 100 快排
 * 
 * 70 运行超时
 * 
 * 还是前缀和，两个数组，一个记录比自己大且值为1，一个记录比自己小且值为0.
 * 这两个也可以合并，y为1，则0~ y-1都记录一个；y为0，y+1~ 都记录一次
 * 但是y值很大,不要用他做索引
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int M[4][100010] = {0};
int recordY[2][100010] = {0};

void quicksort(int left, int right)
{
    if(left < right)
    {
        int i = left;
        int j = right;
        int tempvalue = recordY[0][i];
        int tempflag = recordY[1][i];
        while(i < j)
        {
            while( i<j && recordY[0][j] > tempvalue)
            {j--;}
            if(i<j)
            {
                recordY[0][i] = recordY[0][j];
                recordY[1][i] = recordY[1][j];
                i++;
            }
            while( i<j && recordY[0][i] < tempvalue)
            {i++;}
            if(i<j)
            {
                recordY[0][j] = recordY[0][i];
                recordY[1][j] = recordY[1][i];
                j--;
            }
        }
        recordY[0][i] = tempvalue;
        recordY[1][i] = tempflag;
        quicksort(left, i-1);
        quicksort(i+1,right);
    }

}
int main()
{

    int m;
    int max = -1;
    int y,flag;
    int answer = 0;

    scanf("%d",&m);

    // 获取数据
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d",&y,&flag);
        recordY[0][i] = y;
        recordY[1][i] = flag;
    }
    // 冒泡排序
    // int temp;
    // for(int i = 1; i < m; i++)
    // {
    //     for(int j = i+1; j<=m; j++)
    //     {
    //         if(recordY[0][i] > recordY[0][j])
    //         {
    //             temp = recordY[0][i];
    //             recordY[0][i] = recordY[0][j];
    //             recordY[0][j] = temp;
    //             temp = recordY[1][i];
    //             recordY[1][i] = recordY[1][j];
    //             recordY[1][j] = temp;
    //         }
    //     }
    // }
    // 快排
    quicksort(1,m);


    // 合并相同值 存入M
    int Mindex = 1;
    M[2][Mindex] = recordY[0][1];
    for(int i = 1; i <= m; i++)
    {

        if(M[2][Mindex] == recordY[0][i])
        {
            M[recordY[1][i]][Mindex]++;
        }
        else
        {
            M[2][++Mindex] = recordY[0][i];
            M[recordY[1][i]][Mindex]++;
        }

    }

    // 前缀和的原始数组 对M进行操作
    for(int i = 1; i <= Mindex; i++)
    {
        M[3][i] = M[3][i-1] + M[0][i-1];
        M[1][Mindex-i] += M[1][Mindex-i+1]; 
    }

    int sum = -1;
    for(int i = 1; i <= Mindex; i++)
    {
        if(sum <= M[1][i]+M[3][i])
        {
            sum = M[1][i]+M[3][i];
            answer = M[2][i];
        }
        
    }
    printf("%d",answer);

	return 0;
}