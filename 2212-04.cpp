/**
 * 聚集
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct Node
{
    // 编号
    int id = 0;
    // 成员数量
    int membercnt = 1;//Tx
    int member[310] = {0};
    // Ax = ay
    int Ax = 0;
    // Tx = Ax
    // int Tx = 0;
    int G = 0;
    int sumG = 0;
    int Ansx = 0;
}node;

int n;
node tree[310];

void initTree()
{
    for(int i = 1; i <= n; i++)
    {
        tree[i].id = i;
        tree[i].member[1] = i;
    }

}

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    scanf("%d",&n);

    initTree();

    int p;
    for(int i = 2; i <= n; i++)
    {
        scanf("%d",&p);
        tree[p].membercnt++;
        tree[p].member[tree[p].membercnt] = i;
    }

    int a[310] = {0};
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }

    int b[310] = {0};
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum = 0;
        for(int j = 1; j <= tree[i].membercnt; j++)
        {
            b[j] = a[tree[i].member[j]];
        }
        sort(b+1, b+1+tree[i].membercnt);

        // G
        for(int j = 1; j <= tree[i].membercnt; j++)
        {
            if(j == 1)
            {
                sum += ( b[2] - b[1] );
            }
            else if(j == tree[i].membercnt)
            {
                sum += ( b[j] - b[j-1]);
            }
            else
            {
                sum += min(abs(b[j] - b[j-1]),abs(b[j+1] - b[j]));
            }
        }
        tree[i].G = sum;
    }
    
	

	return 0;
}