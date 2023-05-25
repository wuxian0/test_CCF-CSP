/**
 * 数字排序
 * 
 * 100
 * 
 * 输入数字 非负，所以会有0
 * 排序 纪录最大索引，或者所有一起排序
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct
{
    int id = 0;
    int cnt = 0;
}Node;

bool comp(Node a, Node b)
{
    if(a.cnt > b.cnt)
    {
        return true;
    }
    else if(a.cnt == b.cnt && a.id < b.id)
    {
        return true;
    }

    return false;
}

int main()
{
    Node nodes[1010];
    int n;

    scanf("%d",&n);

    int temp;

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&temp);
        nodes[temp].id = temp;
        nodes[temp].cnt++;
    }

    sort(nodes, nodes + 1010, comp);

    for(int i = 0; i < n; i++)
    {
        if(nodes[i].cnt == 0)
        {
            break;
        }
        printf("%d %d\n", nodes[i].id, nodes[i].cnt);
    }
	

	return 0;
}