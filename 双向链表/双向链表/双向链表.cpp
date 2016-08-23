    
/*��ʼʱ�䣺 2016-07-21 14:45:47
ʵ�ֹ��ܣ�
*/


	#ifndef DList_H  
    #define DList_H  
    typedef  int Item;  
    typedef struct Node * PNode;  //�ڵ�ָ��
    typedef PNode Position;  //�ڵ�λ��
    /*����ڵ�����*/  
    typedef struct Node  
    {  
        Item data;      /*������*/  
        PNode previous; /*ָ��ǰ��*/  
        PNode next;     /*ָ����*/  
    }Node;  
    /*������������*/  
    typedef struct  
    {  
        PNode head;     /*ָ��ͷ�ڵ�*/  
        PNode tail;     /*ָ��β�ڵ�*/  
        int size; //������
    }DList;  
      
    /*����ֵΪi�Ľڵ㣬�����ؽڵ��ַ*/  
    Position MakeNode(Item i);  
      
    /*�ͷ�p��ָ�Ľڵ�*/  
    void FreeNode(PNode p);  
      
    /*����һ���յ�˫������*/  
    DList* InitList();  
      
    /*ɾ��һ��˫������*/  
    void DestroyList(DList *plist);  
      
    /*��һ��������Ϊ�ձ��ͷ�ԭ����ڵ�ռ�*/  
    void ClearList(DList *plist);  
      
    /*����ͷ�ڵ��ַ*/  
    Position GetHead(DList *plist);  
      
    /*����β�ڵ��ַ*/  
    Position GetTail(DList *plist);  
      
    /*���������С*/  
    int GetSize(DList *plist);  
      
    /*����p��ֱ�Ӻ��λ��*/  
    Position GetNext(Position p);  
      
    /*����p��ֱ��ǰ��λ��*/  
    Position GetPrevious(Position p);  
      
    /*��pnode��ָ�ڵ�����һ���ڵ�֮ǰ*/  
    PNode InsFirst(DList *plist,PNode pnode);  
      
    /*�������һ���ڵ�ɾ�����������ַ*/  
    PNode DelFirst(DList *plist);  
      
    /*��ýڵ��������*/  
    Item GetItem(Position p);  
      
    /*���ýڵ��������*/  
    void SetItem(Position p,Item i);  
      
    /*ɾ�������е�β�ڵ㲢�������ַ���ı������βָ��ָ���µ�β�ڵ�*/  
    PNode Remove(DList *plist);  
      
    /*��������pλ��֮ǰ�����½ڵ�S*/  
    PNode InsBefore(DList *plist,Position p,PNode s);  
      
    /*��������pλ��֮������½ڵ�s*/  
    PNode InsAfter(DList *plist,Position p,PNode s);  
      
    /*�����������е�i���ڵ��λ��*/  
    PNode LocatePos(DList *plist,int i);  
      
    /*���ζ�������ÿ��Ԫ�ص��ú���visit()*/  
    void ListTraverse(DList *plist,void (*visit)());
    /*��ӡdata*/
    void print(Item data);   
    #endif  



/*dlist.c*/


    #include<malloc.h>  
    #include<stdlib.h>  
    /*����ֵΪi�Ľڵ㣬�����ؽڵ��ַ*/  
    Position MakeNode(Item i)  //�����ڵ㣬����������i
    {  
        PNode p = NULL;   //����һ���ڵ�pָ���
        p = (PNode)malloc(sizeof(Node));  //Ϊ�ýڵ�����ode�ṹ���С�Ŀռ�
        if(p!=NULL) //����ɹ���
        {  
            p->data = i;  //����������Ϊi
            p->previous = NULL;//�ڵ�pǰ��ָ��ָ���  
            p->next = NULL; //�ڵ�p���ָ��ָ���
        }     
        return p;  //���ش����õ�p�ڵ�ָ���ַ
    }  
    /*�ͷ�p��ָ�Ľڵ�*/  
    void FreeNode(PNode p)  
    {  
         free(p);  
    }  
    /*����һ���յ�˫������*/  
    DList * InitList()  
    {  
        DList *plist = (DList *)malloc(sizeof(DList));//Ϊ�µ�˫���������DList�ṹ���С�Ŀռ�  
        PNode head = MakeNode(0);  //���������MakeNode������������������Ϊ0��ͷָ��ָ��ͷ�ڵ�
        if(plist!=NULL)//�ɹ�����������ռ��  
        {  
            if(head!=NULL) //ͷָ�벻Ϊ��
            {  
                plist->head = head;//�������ͷָ��ָ��ͷ�ڵ�
                plist->tail = head; //�������βָ��Ҳָ��ͷ�ڵ�
                plist->size = 0; //������Ϊ0
            }  
            else  
                return NULL; //ͷָ�봴��ʧ��
        }  
        return plist; //���ش����õĿ�����
    }  
      
    /*ɾ��һ��˫������*/  
    void DestroyList(DList *plist)  
    {  
        ClearList(plist); //��Ϊ DList *plist = (DList *)malloc(sizeof(DList))Ϊ��������˿ռ䣬���Ա������������������ͷ�����ڵ�Ŀռ�
        free(GetHead(plist)); //��Ϊ PNode head = MakeNode(0)Ϊͷ�ڵ�����˿ռ䣬���Ա������GetHead����������ȡ��ǰ�����ͷ�ڵ��ַȻ������ͷ�
        free(plist);  
    }  
      
    /*�ж������Ƿ�Ϊ�ձ�*/  
    int IsEmpty(DList *plist)  
    {  
        if(GetSize(plist)==0&&GetTail(plist)==GetHead(plist)) //������� GetSize����������ȡ�������СΪ0���ҵ���GetTail������ȡ��β�ڵ�͵���
                                  //GetHead������ȡ��ͷ�ڵ�ָ��ͬһ����ַ����ô���ǿձ�
            return 1;  
        else  
            return 0;  
    }  
    /*��һ��������Ϊ�ձ��ͷ�ԭ����ڵ�ռ�*/  
    void ClearList(DList *plist) //�������
    {  
        PNode temp,p;  
        p = GetTail(plist); //���ڵ�ָ��pָ��βָ��ָ��Ľڵ��ַ
        while(!IsEmpty(plist))  //���������Ϊ��
        {     
            temp = GetPrevious(p); //���ڵ�ָ��tempָ��pָ���ǰ��ָ����ָ��ĵ�ַ
            free(p); //�� pָ��ָ���β�ڵ��ͷ�
            p = temp; //pָ������ָ��ղ��ͷŵ�β�ڵ��ǰһ���ڵ�
            plist->tail = temp; //βָ������ָ��ղ��ͷŵ�β�ڵ��ǰһ���ڵ�
            plist->size--;  //�Ӻ���ǰһ��һ���ͷŽڵ�ռ䣬�ͷ�һ�������С�ͼ�1
        }  
    }  
      
    /*����ͷ�ڵ��ַ*/  
    Position GetHead(DList *plist)  
    {  
        return plist->head;  
    }  
      
    /*����β�ڵ��ַ*/  
    Position GetTail(DList *plist)  
    {  
        return plist->tail;  
    }  
      
    /*���������С*/  
    int GetSize(DList *plist)  
    {  
        return plist->size;  
    }  
      
    /*����p��ֱ�Ӻ��λ��*/  
    Position GetNext(Position p)  
    {  
        return p->next;  
    }  
      
    /*����p��ֱ��ǰ��λ��*/  
    Position GetPrevious(Position p)  
    {  
        return p->previous;  
    }  
      
    /*�ڵ�һ���ڵ�ǰ�����½ڵ�pnode*/  
    PNode InsFirst(DList *plist,PNode pnode)  
    {  
        Position head = GetHead(plist);//��ȡͷ�ڵ�λ��
      
        if(IsEmpty(plist))  //������Ϊ�գ������βָ���ָ��pnode�ڵ㣬ֱ�Ӳ����½ڵ�
            plist->tail = pnode;  
        plist->size++;//�����С��1,���¼ӵ�pnode�ڵ�  
          pnode->next = head->next; //�¼ӵ�pnode�ڵ�ĺ��ָ��ָ��ͷ�ڵ�ָ��ĵ�һ���ڵ�  
        pnode->previous = head;//�¼ӵ�pnode�ڵ��ǰ��ָ��ָ��ͷ�ڵ�  
          if(head->next!=NULL)  //�����һ���ڵ㲻Ϊ��
            head->next->previous = pnode;  //��һ���ڵ��ǰ��ָ���ָ���¼ӵ�pnode�ڵ�
        head->next = pnode; //ͷ�ڵ�ĺ��ָ��ָ���¼ӵ�pnode�ڵ�
          return pnode;   
    }  
      
    /*ɾ����һ���ڵ�,���ظýڵ�ĵ�ַ*/  
    PNode DelFirst(DList *plist)  
    {  
        Position head = GetHead(plist);//��ȡͷ�ڵ�λ��  
        Position p=head->next; //��ȡ��һ���ڵ�λ��
        if(p!=NULL)  //��һ���ڵ����
        {  
            if(p==GetTail(plist))  //����һ���ڵ����β�ڵ�
                plist->tail = p->previous; //βָ��ֱ��ָ���һ���ڵ��ǰ�̽ڵ㼴ͷ�ڵ�
            head->next = p->next; //ͷ�ڵ�ĺ��ָ��ֱ��ָ���һ���ڵ�ĺ�һ���ڵ�Ҳ���ǵڶ����ڵ�
            head->next->previous = head; //�ڶ����ڵ��ǰ��ָ��ָ��ͷ�ڵ�
            plist->size--;  //ɾ����һ���ڵ�������С��1
              
        }     
        return p;  
    }  
      
    /*��ýڵ��������*/  
    Item GetItem(Position p)  
    {  
        return p->data;  
    }  
      
    /*���ýڵ��������*/  
    void SetItem(Position p,Item i)  
    {  
        p->data = i;  
    }  
      
    /*ɾ�������е�β�ڵ㲢���ص�ַ���ı������βָ��ָ���µ�β�ڵ�*/  
    PNode Remove(DList *plist)  
    {  
        Position p=NULL;  
        if(IsEmpty(plist))  
            return NULL;  
        else  
        {  
            p = GetTail(plist);  //��pָ��β�ڵ�
            p->previous->next = p->next;//p��ǰһ���ڵ�ĺ��ָ��Ҳ����ָ��β�ڵ��ָ������ԭβ�ڵ�ָ��ͷ�ڵ�  
            plist->tail = p->previous;  //βָ������ָ��ԭβ�ڵ��ǰһ���ڵ�
            plist->size--;//ɾ��β�ڵ�������С��1  
            return p;  
        }  
    }  
    /*��������pλ��֮ǰ�����½ڵ�s*/  
    PNode InsBefore(DList *plist,Position p,PNode s)  
    {  
        s->previous = p->previous; //s�ڵ��ǰ��ָ��ָ�� p�ڵ��ǰһ���ڵ�
        s->next = p; //s�ڵ�ĺ��ָ��ָ��p�ڵ�
        p->previous->next = s; //ԭp�ڵ��ǰһ���ڵ�ĺ��ָ��ָ��s�ڵ�     
        p->previous = s; //p�ڵ��ǰ��ָ��ָ��s�ڵ�
      
        plist->size++; //�����½ڵ�s�������С��1
        return s;  
    }  
    /*��������pλ��֮������½ڵ�s*/  
    PNode InsAfter(DList *plist,Position p,PNode s)  
    {  
        s->next = p->next;  //s�ڵ�ĺ��ָ��ԭp�ڵ����һ���ڵ�
        s->previous = p;  //s�ڵ��ǰ��ָ��ָ��p�ڵ�
          
        if(p->next != NULL)  //ԭp�ڵ���һ���ڵ����
            p->next->previous = s;  //ԭp�ڵ���һ���ڵ��ǰ��ָ��ָ���¼ӵ�s�ڵ�
        p->next = s;//ԭp�ڵ�ĺ��ָ��ָ��s�ڵ�  
          
        if(p = GetTail(plist)) //���p��β�ڵ�
            plist->tail = s;  //��ôβָ������ָ���¼ӵ�s�ڵ㣬��s�ڵ���Ϊβ�ڵ�
          
        plist->size++; //�����½ڵ�s�������С��1  
        return s;  
    }  
      
    /*�����������е�i���ڵ��λ��*/  
    PNode LocatePos(DList *plist,int i)  
    {  
        int cnt = 0;  
        Position p = GetHead(plist); //pָ��ͷ�ڵ�
        if(i>GetSize(plist)||i<1)  //�ж�i��С�Ƿ��������С֮��
            return NULL;  
      
        while(++cnt<=i) //pָ��λ�ô�ͷ�ڵ㿪ʼ�����ƶ���ֱ����i���ڵ��λ��
        {  
            p=p->next;  
        }  
      
        return p;  //p���ָ���λ�þ�������ĵ�i���ڵ��λ��
    }  
      
      /*���ζ�������ÿ��Ԫ�ص��ú���visit()��ӡ����Ԫ��ֵ*/  
    void ListTraverse(DList *plist,void (*visit)())  
    {  
        Position p = GetHead(plist);//pָ��ͷ�ڵ�   
        if(IsEmpty(plist))  //�����������ݾ��˳�
            printf("NULL");  
        else  
        {  
              
            while(p->next!=NULL)  //p�������±������Ԫ��ֵ
            {  
                p = p->next;  
                visit(p->data);            
            }         
        }  
    }
     /*��ӡdata*/
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
        printf("��ʼ������˫��������������\n");
        plist = InitList();  //����˫������
        system("sleep 2");
        printf("������˫��������ɣ�\n");
        printf("���������봴���Ľڵ���Ŀ:");
        scanf("%d",&n);
        if(n==0)
        {
            printf("�ձ��ܽ����κβ�����\n");
            exit(0);
        }
        int a[n];
        printf("��ʼ����ͷ�ڵ㡣����������\n");
        printf("������ͷ�ڵ�����ݣ���ͷ�ڵ���д0������:");
        scanf("%d",&a[0]);
        printf("���ڴ���ͷ�ڵ㡣����������\n");
        p = InsFirst(plist,MakeNode(a[0]));
        printf("ͷ�ڵ㴴����ɣ�����Ϊ��%d\n",a[0]);  
           for(i=1;i<n;i++)
        {
            printf("��ʼ������%d���ڵ㡣����������\n",i);
            printf("�������%d���ڵ������:",i);
            scanf("%d",&a[i]);
            printf("���ڴ�����%d���ڵ㡣����\n",i);
            p = InsAfter(plist,p,MakeNode(a[i]));
            system("sleep 1");
            printf("������%d���ڵ����\n",i);
        }
        printf("%d���ڵ㴴����ɣ�",n);
        printf("����������ڵ�������:");  
        ListTraverse(plist,print);  
         printf("\n");
        printf("��������%d���ڵ�\n",GetSize(plist));
        while(1)
        {
        printf("��ѡ������Ҫ���Ĳ�����\n1.��������pλ��֮ǰ�����½ڵ�s \n2.ɾ����һ���ڵ� \n3.�������ÿ� \n4.ɾ������\n5.�˳���\n");
        scanf("%d",&select);
        switch(select)
            {
                case 1:printf("pλ�õ�ֵΪ:%d\n",GetItem(p));
                printf("��ʼ�����½ڵ�s������������\n");
                printf("�������½ڵ�s������:");
                scanf("%d",&a[n+1]);
                printf("���ڴ����½ڵ�s������\n");
                p = InsBefore(plist,p,MakeNode(a[n+1]));
                system("sleep 1");
                printf("�����½ڵ�s��ɣ�����Ϊ:%d\n",a[n+1]);
                printf("����������ڵ�������:");ListTraverse(plist,print);printf("\n");break;
                case 2:DelFirst(plist);system("sleep 1");printf("ɾ�����\n"); printf("����������ڵ�������:");ListTraverse(plist,print);printf("\n");break;
                case 3:ClearList(plist);system("sleep 1");printf("������\n"); printf("����������ڵ�������:");ListTraverse(plist,print);printf("\n");exit(0);
                case 4:DestroyList(plist); printf("�����ѱ�����\n");printf("\n");exit(0);
                case 5:exit(0);
                default:printf("������������!\n");
                }
        }
   }
      