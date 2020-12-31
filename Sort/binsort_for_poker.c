#include <stdio.h>
#include <stdlib.h>

/** 
 * 为扑克设计一个bucket排序， 也叫箱排序
 * 
 * 相同元素在箱子中以链表实现，尾插入
 **/

//扑克花色
typedef enum {
    RED_HEART, //红心
    RED_BLOCK, //方块
    BLACK, //黑桃
    PLUM //梅花
} Poker_Color;

typedef struct {
    Poker_Color color; //扑克花色
    int val; //扑克的数值
} Poker;

typedef struct Node
{
    Poker* poker;
    struct Node* next;
} PokerLinkerNode;

Poker *createPoker(Poker_Color color, int val)
{
    Poker *item = malloc(sizeof(Poker));
    item->color = color;
    item->val = val;

    return item;
}

/** 
 * 将一堆扑克，进行按顺序排列，相同数值扑克，不要求顺序
 **/
Poker *sortPoker(Poker *arr[], int len)
{    
    PokerLinkerNode **alloc_arr = malloc(sizeof(PokerLinkerNode*) * 14);
    //对箱子进行初始化
    for (int i = 0; i < 14; i++) {
        alloc_arr[i] = NULL;
    }

    for (int i = 0; i < len; i++) {
        int poker_val = arr[i]->val;
        if (alloc_arr[poker_val] == NULL) { //是链表第一个节点
            PokerLinkerNode *temp = malloc(sizeof(PokerLinkerNode));
            temp->poker = arr[i];
            temp->next = NULL;

            alloc_arr[poker_val] = temp;
        } else {
            // 找到对应对尾节点
            // PokerLinkerNode *tail = NULL;
            PokerLinkerNode *tail = alloc_arr[poker_val];
            while (tail->next != NULL) {
                tail = tail->next;
            }

            // 插入尾节点，作为最新的尾巴
            PokerLinkerNode *temp = malloc(sizeof(PokerLinkerNode));
            temp->poker = arr[i];
            temp->next = NULL;

            tail->next = temp;
        }
    }

    // 生成结果集
    // Poker *result[len];
    Poker *result = malloc(sizeof(PokerLinkerNode *) * len);
    int j = 0;
    for (int i = 1; i < 14; i++) {
        PokerLinkerNode *head = alloc_arr[i];
        while (head != NULL) {
            result[j++] = *(head->poker);
            head = head->next;
        }
    }

    return result;
}

int main(void)
{
    Poker *poker1 = createPoker(RED_HEART, 2);
    Poker *poker2 = createPoker(RED_BLOCK, 2);
    Poker *poker3 = createPoker(PLUM, 2);
    Poker *poker4 = createPoker(BLACK, 5);
    Poker *poker7 = createPoker(RED_BLOCK, 6);
    Poker *poker8 = createPoker(RED_HEART, 6);
    Poker *rand_pokers[] = {poker7, poker4, poker2, poker1, poker8, poker3};

    Poker *result = sortPoker(rand_pokers, sizeof(rand_pokers)/sizeof(Poker));

    for (int i = 0; i < sizeof(rand_pokers)/sizeof(Poker); i++) {
        printf("val=%d, color=%d\n", result[i].val, result[i].color);
    }

    return 0;
}