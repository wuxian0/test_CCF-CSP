/**
 * 非零段划分
 * 80
 * ******************************************************************************
 * 
 * 又想了一下，每次调整p时，还可以进行一次合并，小于p的进行合并，每次遍历长度都在缩短，
 * 只是用数组好像不太方便，可以用链表，直接舍去该结点每次遍历长度都在缩短
 * 
 * ******************************************************************************
 * 80 ：元素依次置0，当前p 如果判断左值小于p且右值小于p，相当于两端合并，段数-1；只有一侧小于p，保持不变。
 *      A n个数字，去掉连续重复为counta，去掉重复为B数量count
 * 搜了一下 差分，不会，就这吧
 * ******************************************************************************
 * 70
 * 读入数据存入A，并将出现的数值升序不重复存入B，从最小元素依次开始计算分段数量
 * ------------------------------------------------------------------------------
 * 本地分配较大空间测试不了，可以提交的时候在修改
 * 运行超时问题：应该优化嵌套部分，没想解决方法，
 * ------------------------------------------------------------------------------
 *      无效：先对输入处理，连续相同输入只保留一个
 * *******************************************************************************
 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;

    scanf("%d",&n);

    // 读入数据 纪录最大值，记录值
    int maxmember = -1;
    int collect[10010] = {0};
    // int A[100010] = {0};
    // int B[100010] = {0};
    int counta=0;
    int A[500010] = {0};
    int B[500010] = {0};
    int temp;
    int index = 1;
    collect[0]=1;

    int initseg = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&temp);
        collect[temp] = 1;
        if(maxmember < temp)
        {
            maxmember = temp;
        }
        if(i == 1)
        {
            A[index] = temp;
            counta++;
            if(A[index-1] == 0 && A[index] != 0)
            {
                initseg++;
            }
        }
        else{
            if(temp == A[index])
            {continue;}
            else{
                A[++index] = temp;
                counta++;
                if(A[index-1] == 0 && A[index] != 0)
                {
                    initseg++;
                }
            }
        }
        // 获取段数量 (初始数量 条件为0，后续判断依次为A中从小到大的元素)
    }
    // printf("%d\n",initseg);
    int count = 0;
    // B记录A中都有哪些元素，不重复，次序从小到大
    for(int i = 0; i <= maxmember; i++)
    {
        if(collect[i] == 1)
        {
            B[++count] = i;
        }
    }


    int maxseg = initseg;
    for(int h = 1; h <= count; h++)
    {

        if(B[h] == 0)
            continue;
        // 段数量判断代码
        for(int i = 1; i <= counta; i++)
        {
            // 等于p时判断
            // 分配空间足够，且从
            if(A[i] == B[h])
            {

                bool left = A[i-1] > B[h];
                bool right = A[i+1] > B[h];
                if(left && right)
                {
                    // 截断 数量增加
                    initseg++;
                }
                else if(!left && !right)
                {
                    // 唯一点消失，减少
                    initseg--;
                }

            }
            
        }
        if( initseg > maxseg)
        {
            maxseg = initseg;
        }

    }
    // 超时
    // for(int h = 0; h <= count; h++)
    // {
    //     initseg = 0;
    //     if(B[h] == 0)
    //         continue;
    //             // 段数量判断代码
    //     for(int i = 1; i <= n; )
    //     {
    //         if(A[i] <= B[h])
    //         {
    //             i++;
    //             continue;
    //         }
    //         else
    //         {
    //             initseg++;
    //             int j = i+1;
    //             while(A[j] > B[h])
    //             {
    //                 j++;
    //             }
    //             i = j+1;
    //         }
    //     }
    //     if( initseg > maxseg)
    //     {
    //         maxseg = initseg;
    //     }

    // }

    printf("%d",maxseg);

	return 0;
}