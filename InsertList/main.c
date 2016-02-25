//
//  main.c
//  InsertList
//
//  Created by chenyufeng on 16/2/25.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  在某个指定位置pos插入一个值为x的节点,这里使用尾插法； 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct ListNode{
    int element;
    struct ListNode *next;
}Node;


//初始化链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，初始化链表成功\n",__FUNCTION__);
}

//打印链表
void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//尾插法构建链表
Node *TailInsert(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0 ) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }
        pInsert = (Node*)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        scanf("%d",&(pInsert->element));
    }//while

    printf("%s函数执行，尾插法构建链表成功\n",__FUNCTION__);

    return pNode;
}

//获取链表长度
elemType sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

Node *InsertToPosition(Node *pNode,int pos,int x){

    if (pos < 0 || pos > sizeList(pNode) ) {
        printf("%s函数执行，pos=%d非法，插入数据失败\n",__FUNCTION__,pos);
        return pNode;
    }

    Node *pMove;
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->element = x;

    pMove = pNode;
    int i = 1;

    //这里单独考虑pos=0的情况
    if (pos == 0) {
        pInsert->next = pNode;
        pNode = pInsert;
        printf("%s函数执行，在pos=%d插入x=%d成功\n",__FUNCTION__,pos,x);
        return pNode;
    }

    while (pMove != NULL) {
        if (i == pos) {
            pInsert->next = pMove->next;
            pMove->next = pInsert;
            printf("%s函数执行，在pos=%d插入x=%d成功\n",__FUNCTION__,pos,x);
            break;
        }
        i++;
        pMove = pMove->next;
    }

    return pNode;
}

int main(int argc, const char * argv[]) {

    Node *pList;

    //初始化
    initList(pList);
    printList(pList);

    //构建链表
    pList = TailInsert(pList);
    printList(pList);

    //获取链表长度
    sizeList(pList);

    //插入元素
    pList = InsertToPosition(pList,3,111);
    printList(pList);
    sizeList(pList);
    
    return 0;
}







