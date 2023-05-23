/**
 * 窗口
 * 
 * 100
 * 
 * 链表，太久没看，都忘完了
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct Win
{
    int no;
    int x1;
    int x2;
    int y1;
    int y2;
    struct Win * next;
} Windows;


int main()
{
    int n,m;
    
    scanf("%d%d",&n,&m);

    Windows * head = (Windows*) malloc(sizeof(Windows));
    head->next = NULL;
    Windows * p = NULL;

    for(int i = 1; i <= n; i++)
    {
        p = head->next;
        head->next = (Windows*) malloc(sizeof(Windows));
        head->next->next = p;
        p = head->next;
        

        p->no = i;
        scanf("%d%d%d%d", &(p->x1), &(p->y1), &(p->x2), &(p->y2));
    }

    
    int xx;
    int yy;
    int flag = 0;
    Windows * q = NULL;
    for(int i = 1; i <= m; i++)
    {
        flag = 0;
        scanf("%d%d",&xx,&yy);

        p = head->next;
        while(p)
        {
            if( (xx >= p->x1 && xx <= p->x2) && (yy >= p->y1 && yy <= p->y2))
            {
                if(head->next != p)
                {
                    q->next = p->next;
                    p->next = head->next;
                    head->next = p;
                }
                printf("%d\n", p->no);
                flag = 1;
                break;
            }
            q = p;
            p = p->next;
        }
        if( flag == 0)
        {
            printf("IGNORED\n");
        }
    }
	

	return 0;
}