#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100
#define isLetter(a)  ((((a) >='a') && (a <= 'z')) || (((a) >='A') && (a <= 'Z')))
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

// 
typedef struct _ENode
{
    int ivex; // 下一个定点索引位置
    int weight;  // 该边的权值
    struct _ENode *next_edge; // 下下个索引点位置
} ENode, * PENode ;

// 邻接表中的顶点
typedef struct _VNode
{
    char data;  // 数据
    ENode *first_edge; // 指向第一条边
} VNode;

typedef struct _LGraph
{
    int vexnum;
    int edgnum;
    VNode vexs[MAX];
} LGraph;

static int get_postion(LGraph G,char ch) {
    int i;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i].data == ch) return i;
    }
    return -1;
}

static char read_char() {
    char ch;

    do {
        ch = getchar();
    } while(!isLetter(ch));

    return ch;
}

static void link_last(ENode *list, ENode *node) {
    ENode *p = list;

    while (p->next_edge)
    {
        p = p->next_edge;
    }
    p->next_edge = node;
    
}


// 边的结构体
typedef struct _edata
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
}EData;


// 顶点
static char  gVexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
// 边
static EData gEdges[] = {
  // 起点 终点 权
    {'A', 'B', 12}, 
    {'A', 'F', 16}, 
    {'A', 'G', 14}, 
    {'B', 'C', 10}, 
    {'B', 'F',  7}, 
    {'C', 'D',  3}, 
    {'C', 'E',  5}, 
    {'C', 'F',  6}, 
    {'D', 'E',  4}, 
    {'E', 'F',  2}, 
    {'E', 'G',  8}, 
    {'F', 'G',  9}, 
};

/*
 * 创建邻接表对应的图(用已提供的数据)
 */
LGraph* create_example_lgraph()
{
    char c1, c2;
    int vlen = LENGTH(gVexs);
    int elen = LENGTH(gEdges);
    int i, p1, p2;
    int weight;
    ENode *node1, *node2;
    LGraph* pG;

    if ((pG=(LGraph*)malloc(sizeof(LGraph))) == NULL )
        return NULL;
    memset(pG, 0, sizeof(LGraph));

    // 初始化"顶点数"和"边数"
    pG->vexnum = vlen;
    pG->edgnum = elen;
    // 初始化"邻接表"的顶点
    for(i=0; i<pG->vexnum; i++)
    {
        pG->vexs[i].data = gVexs[i];
        pG->vexs[i].first_edge = NULL;
    }

    // 初始化"邻接表"的边
    for(i=0; i<pG->edgnum; i++)
    {
        // 读取边的起始顶点,结束顶点,权
        c1 = gEdges[i].start;
        c2 = gEdges[i].end;
        weight = gEdges[i].weight;

        p1 = get_position(*pG, c1);
        p2 = get_position(*pG, c2);

        // 初始化node1
        node1 = (ENode*)malloc(sizeof(ENode));
        node1->ivex = p2;
        node1->weight = weight;
        // 将node1链接到"p1所在链表的末尾"
        if(pG->vexs[p1].first_edge == NULL)
            pG->vexs[p1].first_edge = node1;
        else
            link_last(pG->vexs[p1].first_edge, node1);
        // 初始化node2
        node2 = (ENode*)malloc(sizeof(ENode));
        node2->ivex = p1;
        node2->weight = weight;
        // 将node2链接到"p2所在链表的末尾"
        if(pG->vexs[p2].first_edge == NULL)
            pG->vexs[p2].first_edge = node2;
        else
            link_last(pG->vexs[p2].first_edge, node2);
    }

    return pG;
}

/*
 * 深度优先搜索遍历图的递归实现
 */
static void DFS(LGraph G, int i, int *visited)
{
    int w;
    ENode *node;

    visited[i] = 1;
    printf("%c ", G.vexs[i].data);
    node = G.vexs[i].first_edge;
    while (node != NULL)
    {
        if (!visited[node->ivex])
            DFS(G, node->ivex, visited);
        node = node->next_edge;
    }
}

/*
 * 深度优先搜索遍历图
 */
void DFSTraverse(LGraph G)
{
    int i;
    int visited[MAX];       // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("DFS: ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}




