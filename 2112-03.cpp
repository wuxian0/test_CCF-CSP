/**
 * 登机牌条码
 * 
 * 20
 * 
 * 第2题没做100，就试试第3题，一步一步来还是不难，就是花点时间
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int w,s;
char str[10000010];
int answer[10000010] = {0};
int result[10000010] = {0};
int totalLen = 0;

// 大写为0，小写为1,数字为2
int getType(char * pt)
{
    if( *pt >= '0' & *pt <= '9')
    {return 2;}
    else if( *pt >= 'A' & *pt <= 'Z' )
    {return 0;}
    else if( *pt >= 'a' & *pt <= 'z' )
    {return 1;}
    return 3;
}

// 根据内容获取值
int getValue(char * pt)
{
    if( *pt >= '0' & *pt <= '9')
    {return (*pt) - '0';}
    else if( *pt >= 'A' & *pt <= 'Z' )
    {return (*pt) - 'A';}
    else if( *pt >= 'a' & *pt <= 'z' )
    {return (*pt) - 'a';}
    return 0;
}

// 模式切换插入数据
void changeMode( int last, int now, int * pindex)
{
    // 大写转其他
    if(last == 0)
    {
        // lower
        if(now == 1)
        {
            (*pindex)++;
            answer[*pindex] = 27;
        }
        // num
        else if(now == 2)
        {
            (*pindex)++;
            answer[*pindex] = 28;
        }
    }
    // 小写转其他
    else if(last == 1)
    {
        // upper
        if(now == 0)
        {
            (*pindex)++;
            answer[*pindex] = 28;
            (*pindex)++;
            answer[*pindex] = 28;
        }
        // num
        else if(now == 2)
        {
            (*pindex)++;
            answer[*pindex] = 28; 
        }
    }
    // 数字转其他
    else if(last == 2)
    {
        // upper
        if(now == 0)
        {
            (*pindex)++;
            answer[*pindex] = 28;
            
        }
        // lower
        else if(now == 1)
        {
            (*pindex)++;
            answer[*pindex] = 27;
            
        }
    }
}
int main()
{
    scanf("%d%d",&w,&s);
    scanf("%s",str);

    char * p = str;
    int lastType = 0;
    int pType = 0;

    int k = 0;
    // 获取校验码字数量
    if( s == (-1))
    {
        k = 0;
    }
    else
    {
        k = pow(2,s+1);
    }
    
    

    // 获得数字序列
    int index = 0;
    while(*p)
    {
        if(index == 0)
        {
            index++;
            answer[index] = getValue(p);

            pType = getType(p);
            lastType = pType;

            p++;

            continue;
        }
        lastType = pType;
        pType = getType(p);
        // 模式切换插入
        changeMode(lastType, pType, &index);
        // 获取当前值
        index++;
        answer[index] = getValue(p);
        p++;
        
    }
    // 数字序列奇数 填充29
    if(index%2 == 1)
    {
        index++;
        answer[index] = 29;

    }

    // 数字序列组队获取码字，result[0]存储有效码字数量
    for(int i = 1; i <= index/2; i++)
    {
        result[i] = answer[2*i-1] * 30 + answer[2*i];
    }

    // 填充码字 900
    result[0] = index/2 +1;
    int needLen = result[0] + k;
    // 填充时更新result[0]
    while( needLen % w != 0)
    {
        // 填充
        result[result[0]] = 900;
        result[0]++;
        needLen++;
    }

    // 校验码字获取
    int dn[1000] = {0};
    int g[20] = {0};
    int r[1000] = {0};
    int dnIndex = result[0];
    // 获得g系数
    // 每次乘(x - 3^k)，乘x相当于右移一位，-3^k系数倍乘，然后合并
    // 
    // for(int i = k)
    for(int i = 0; i < result[0]; i++)
    {
        dn[result[0] - i] = result[i];
    }


    // 输出结果
    for(int i = 0; i < needLen; i++)
    {
        printf("%d\n",result[i]); 
    }
	

	return 0;
}