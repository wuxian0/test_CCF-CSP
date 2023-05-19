/**
 * 稀疏向量
 * 
 * 100
 * 
 * sort(a[1],a[n])排序不包括a[n]
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

typedef struct node
{
    int index;
    int value;

}Node;

bool comp(Node A,Node B)
{
    if(A.index < B.index)
    {
        return true;
    }
    return false;
}

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int tindex,tvalue;
    long answer = 0;

    Node * pa = (Node *) malloc(sizeof(Node) * (a+10));
    Node * pb = (Node *) malloc(sizeof(Node) * (b+10));

    for(int i = 1; i <= a; i++)
    {
        scanf("%d%d",&tindex,&tvalue);

        (*(pa+i)).index = tindex;
        (*(pa+i)).value = tvalue;
    }
    std::sort(pa+1,pa+a+1,comp);

    for(int i = 1; i <= b; i++)
    {
        scanf("%d%d",&tindex,&tvalue);

        pb[i].index = tindex;
        pb[i].value = tvalue;
    }
    std::sort(pb+1,pb+b+1,comp);
    int ia = 1;
    int ib = 1;
    while( ia <= a && ib <= b)
    {
        if( pa[ia].index == pb[ib].index)
        {
            // printf("%d * %d\n",pa[ia].value,pb[ib].value);
            answer += (pa[ia].value * pb[ib].value );
            ia++;
            ib++;
        }
        else if(pa[ia].index < pb[ib].index)
        {
            ia++;
        }
        else
        {
            ib++;
        }
    }
    printf("%ld",answer);

	

	return 0;
}