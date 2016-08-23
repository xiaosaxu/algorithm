    
/*开始时间： 2016-07-21 14:45:47
实现功能：
*/


	#ifndef DList_H  
    #define DList_H  
    typedef  int Item;  
    typedef struct Node * PNode;  //节点指针
    typedef PNode Position;  //节点位置
    /*定义节点类型*/  
    typedef struct Node  
    {  
        Item data;      /*数据域*/  
        PNode previous; /*指向前驱*/  
        PNode next;     /*指向后继*/  
    }Node;  
    /*定义链表类型*/  
    typedef struct  
    {  
        PNode head;     /*指向头节点*/  
        PNode tail;     /*指向尾节点*/  
        int size; //链表长度
    }DList;  
      
    /*分配值为i的节点，并返回节点地址*/  
    Position MakeNode(Item i);  
      
    /*释放p所指的节点*/  
    void FreeNode(PNode p);  
      
    /*构造一个空的双向链表*/  
    DList* InitList();  
      
    /*删除一个双向链表*/  
    void DestroyList(DList *plist);  
      
    /*将一个链表置为空表，释放原链表节点空间*/  
    void ClearList(DList *plist);  
      
    /*返回头节点地址*/  
    Position GetHead(DList *plist);  
      
    /*返回尾节点地址*/  
    Position GetTail(DList *plist);  
      
    /*返回链表大小*/  
    int GetSize(DList *plist);  
      
    /*返回p的直接后继位置*/  
    Position GetNext(Position p);  
      
    /*返回p的直接前驱位置*/  
    Position GetPrevious(Position p);  
      
    /*将pnode所指节点插入第一个节点之前*/  
    PNode InsFirst(DList *plist,PNode pnode);  
      
    /*将链表第一个节点删除并返回其地址*/  
    PNode DelFirst(DList *plist);  
      
    /*获得节点的数据项*/  
    Item GetItem(Position p);  
      
    /*设置节点的数据项*/  
    void SetItem(Position p,Item i);  
      
    /*删除链表中的尾节点并返回其地址，改变链表的尾指针指向新的尾节点*/  
    PNode Remove(DList *plist);  
      
    /*在链表中p位置之前插入新节点S*/  
    PNode InsBefore(DList *plist,Position p,PNode s);  
      
    /*在链表中p位置之后插入新节点s*/  
    PNode InsAfter(DList *plist,Position p,PNode s);  
      
    /*返回在链表中第i个节点的位置*/  
    PNode LocatePos(DList *plist,int i);  
      
    /*依次对链表中每个元素调用函数visit()*/  
    void ListTraverse(DList *plist,void (*visit)());
    /*打印data*/
    void print(Item data);   
    #endif  



/*dlist.c*/


    #include<malloc.h>  
    #include<stdlib.h>  
    /*分配值为i的节点，并返回节点地址*/  
    Position MakeNode(Item i)  //创建节点，并设置数据i
    {  
        PNode p = NULL;   //定义一个节点p指向空
        p = (PNode)malloc(sizeof(Node));  //为该节点分配Ｎode结构体大小的空间
        if(p!=NULL) //分配成功后
        {  
            p->data = i;  //设置数据域为i
            p->previous = NULL;//节点p前继指针指向空  
            p->next = NULL; //节点p后继指针指向空
        }     
        return p;  //返回创建好的p节点指针地址
    }  
    /*释放p所指的节点*/  
    void FreeNode(PNode p)  
    {  
         free(p);  
    }  
    /*构造一个空的双向链表*/  
    DList * InitList()  
    {  
        DList *plist = (DList *)malloc(sizeof(DList));//为新的双向链表分配DList结构体大小的空间  
        PNode head = MakeNode(0);  //调用上面的MakeNode（）函数创建数据域为0的头指针指向头节点
        if(plist!=NULL)//成功分配新链表空间后  
        {  
            if(head!=NULL) //头指针不为空
            {  
                plist->head = head;//新链表的头指针指向头节点
                plist->tail = head; //先链表的尾指针也指向头节点
                plist->size = 0; //链表长度为0
            }  
            else  
                return NULL; //头指针创建失败
        }  
        return plist; //返回创建好的空链表
    }  
      
    /*删除一个双向链表*/  
    void DestroyList(DList *plist)  
    {  
        ClearList(plist); //因为 DList *plist = (DList *)malloc(sizeof(DList))为链表分配了空间，所以必须调用清空链表函数，释放链表节点的空间
        free(GetHead(plist)); //因为 PNode head = MakeNode(0)为头节点分配了空间，所以必须调用GetHead（）函数获取当前链表的头节点地址然后进行释放
        free(plist);  
    }  
      
    /*判断链表是否为空表*/  
    int IsEmpty(DList *plist)  
    {  
        if(GetSize(plist)==0&&GetTail(plist)==GetHead(plist)) //如果调用 GetSize（）函数获取的链表大小为0并且调用GetTail函数获取的尾节点和调用
                                  //GetHead函数获取的头节点指向同一个地址，那么就是空表
            return 1;  
        else  
            return 0;  
    }  
    /*将一个链表置为空表，释放原链表节点空间*/  
    void ClearList(DList *plist) //清空链表
    {  
        PNode temp,p;  
        p = GetTail(plist); //将节点指针p指向尾指针指向的节点地址
        while(!IsEmpty(plist))  //如果该链表不为空
        {     
            temp = GetPrevious(p); //将节点指针temp指向p指针的前继指针所指向的地址
            free(p); //将 p指针指向的尾节点释放
            p = temp; //p指针重新指向刚才释放的尾节点的前一个节点
            plist->tail = temp; //尾指针重新指向刚才释放的尾节点的前一个节点
            plist->size--;  //从后往前一个一个释放节点空间，释放一个链表大小就减1
        }  
    }  
      
    /*返回头节点地址*/  
    Position GetHead(DList *plist)  
    {  
        return plist->head;  
    }  
      
    /*返回尾节点地址*/  
    Position GetTail(DList *plist)  
    {  
        return plist->tail;  
    }  
      
    /*返回链表大小*/  
    int GetSize(DList *plist)  
    {  
        return plist->size;  
    }  
      
    /*返回p的直接后继位置*/  
    Position GetNext(Position p)  
    {  
        return p->next;  
    }  
      
    /*返回p的直接前驱位置*/  
    Position GetPrevious(Position p)  
    {  
        return p->previous;  
    }  
      
    /*在第一个节点前插入新节点pnode*/  
    PNode InsFirst(DList *plist,PNode pnode)  
    {  
        Position head = GetHead(plist);//获取头节点位置
      
        if(IsEmpty(plist))  //若链表为空，链表的尾指针就指向pnode节点，直接插入新节点
            plist->tail = pnode;  
        plist->size++;//链表大小加1,给新加的pnode节点  
          pnode->next = head->next; //新加的pnode节点的后继指针指向头节点指向的第一个节点  
        pnode->previous = head;//新加的pnode节点的前继指针指向头节点  
          if(head->next!=NULL)  //如果第一个节点不为空
            head->next->previous = pnode;  //第一个节点的前继指针就指向新加的pnode节点
        head->next = pnode; //头节点的后继指针指向新加的pnode节点
          return pnode;   
    }  
      
    /*删除第一个节点,返回该节点的地址*/  
    PNode DelFirst(DList *plist)  
    {  
        Position head = GetHead(plist);//获取头节点位置  
        Position p=head->next; //获取第一个节点位置
        if(p!=NULL)  //第一个节点存在
        {  
            if(p==GetTail(plist))  //若第一个节点就是尾节点
                plist->tail = p->previous; //尾指针直接指向第一个节点的前继节点即头节点
            head->next = p->next; //头节点的后继指针直接指向第一个节点的后一个节点也就是第二个节点
            head->next->previous = head; //第二个节点的前继指针指向头节点
            plist->size--;  //删除第一个节点后链表大小减1
              
        }     
        return p;  
    }  
      
    /*获得节点的数据项*/  
    Item GetItem(Position p)  
    {  
        return p->data;  
    }  
      
    /*设置节点的数据项*/  
    void SetItem(Position p,Item i)  
    {  
        p->data = i;  
    }  
      
    /*删除链表中的尾节点并返回地址，改变链表的尾指针指向新的尾节点*/  
    PNode Remove(DList *plist)  
    {  
        Position p=NULL;  
        if(IsEmpty(plist))  
            return NULL;  
        else  
        {  
            p = GetTail(plist);  //让p指向尾节点
            p->previous->next = p->next;//p的前一个节点的后继指针也就是指向尾节点的指针跳过原尾节点指向头节点  
            plist->tail = p->previous;  //尾指针重新指向原尾节点的前一个节点
            plist->size--;//删除尾节点后链表大小减1  
            return p;  
        }  
    }  
    /*在链表中p位置之前插入新节点s*/  
    PNode InsBefore(DList *plist,Position p,PNode s)  
    {  
        s->previous = p->previous; //s节点的前继指针指向 p节点的前一个节点
        s->next = p; //s节点的后继指针指向p节点
        p->previous->next = s; //原p节点的前一个节点的后继指针指向s节点     
        p->previous = s; //p节点的前继指针指向s节点
      
        plist->size++; //插入新节点s后，链表大小加1
        return s;  
    }  
    /*在链表中p位置之后插入新节点s*/  
    PNode InsAfter(DList *plist,Position p,PNode s)  
    {  
        s->next = p->next;  //s节点的后继指针原p节点的下一个节点
        s->previous = p;  //s节点的前继指针指向p节点
          
        if(p->next != NULL)  //原p节点下一个节点存在
            p->next->previous = s;  //原p节点下一个节点的前继指针指向新加的s节点
        p->next = s;//原p节点的后继指针指向s节点  
          
        if(p = GetTail(plist)) //如果p是尾节点
            plist->tail = s;  //那么尾指针重新指向新加的s节点，让s节点作为尾节点
          
        plist->size++; //插入新节点s后，链表大小加1  
        return s;  
    }  
      
    /*返回在链表中第i个节点的位置*/  
    PNode LocatePos(DList *plist,int i)  
    {  
        int cnt = 0;  
        Position p = GetHead(plist); //p指向头节点
        if(i>GetSize(plist)||i<1)  //判断i大小是否在链表大小之间
            return NULL;  
      
        while(++cnt<=i) //p指针位置从头节点开始往后移动，直至第i个节点的位置
        {  
            p=p->next;  
        }  
      
        return p;  //p最后指向的位置就是所求的第i个节点的位置
    }  
      
      /*依次对链表中每个元素调用函数visit()打印链表元素值*/  
    void ListTraverse(DList *plist,void (*visit)())  
    {  
        Position p = GetHead(plist);//p指向头节点   
        if(IsEmpty(plist))  //空链表无数据就退出
            printf("NULL");  
        else  
        {  
              
            while(p->next!=NULL)  //p不断往下遍历输出元素值
            {  
                p = p->next;  
                visit(p->data);            
            }         
        }  
    }
     /*打印data*/
    void print(Item data)
    {
        printf("%d ",data);
    }


/*test.c*/

#include"dlist.h"
    #include"dlist.c"  
    #include<stdio.h>
    #include<stdlib.h>   
    main()  
    {  
        int i,n;
        int select;
        DList *plist = NULL;  
        PNode p = NULL;  
        printf("开始创建空双向链表。。。。。\n");
        plist = InitList();  //创建双向链表
        system("sleep 2");
        printf("创建空双向链表完成！\n");
        printf("请输入你想创建的节点数目:");
        scanf("%d",&n);
        if(n==0)
        {
            printf("空表不能进行任何操作！\n");
            exit(0);
        }
        int a[n];
        printf("开始创建头节点。。。。。。\n");
        printf("请输入头节点的数据（空头节点请写0继续）:");
        scanf("%d",&a[0]);
        printf("正在创建头节点。。。。。。\n");
        p = InsFirst(plist,MakeNode(a[0]));
        printf("头节点创建完成！数据为：%d\n",a[0]);  
           for(i=1;i<n;i++)
        {
            printf("开始创建第%d个节点。。。。。。\n",i);
            printf("请输入第%d个节点的数据:",i);
            scanf("%d",&a[i]);
            printf("正在创建第%d个节点。。。\n",i);
            p = InsAfter(plist,p,MakeNode(a[i]));
            system("sleep 1");
            printf("创建第%d个节点完成\n",i);
        }
        printf("%d个节点创建完成！",n);
        printf("遍历输出各节点数据项:");  
        ListTraverse(plist,print);  
         printf("\n");
        printf("该链表共有%d个节点\n",GetSize(plist));
        while(1)
        {
        printf("请选择您想要做的操作：\n1.在链表中p位置之前插入新节点s \n2.删除第一个节点 \n3.将链表置空 \n4.删除链表\n5.退出：\n");
        scanf("%d",&select);
        switch(select)
            {
                case 1:printf("p位置的值为:%d\n",GetItem(p));
                printf("开始创建新节点s。。。。。。\n");
                printf("请输入新节点s的数据:");
                scanf("%d",&a[n+1]);
                printf("正在创建新节点s。。。\n");
                p = InsBefore(plist,p,MakeNode(a[n+1]));
                system("sleep 1");
                printf("创建新节点s完成！数据为:%d\n",a[n+1]);
                printf("遍历输出各节点数据项:");ListTraverse(plist,print);printf("\n");break;
                case 2:DelFirst(plist);system("sleep 1");printf("删除完成\n"); printf("遍历输出各节点数据项:");ListTraverse(plist,print);printf("\n");break;
                case 3:ClearList(plist);system("sleep 1");printf("清空完成\n"); printf("遍历输出各节点数据项:");ListTraverse(plist,print);printf("\n");exit(0);
                case 4:DestroyList(plist); printf("链表已被销毁\n");printf("\n");exit(0);
                case 5:exit(0);
                default:printf("您的输入有误!\n");
                }
        }
   }
      