/*��ͷ�ļ�Ϊ��������������������ɽӿ�*/

/*��������_s(student) _c(card) _b(book) _r(record)���� 
��ʼ������������������롢ɾ����(s��c����)�󳤶� �����ӿ�*/


Status InitList_s(LinkList_s *L) //��ʼ������LinkList_s 
{ /* �������������һ���յ����Ա�L */
   *L=(LinkList_s)malloc(sizeof(struct LNode_s)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
}

void Print_s(ElemType_s e)/*���ѧ����Ϣ*/
{
      printf("ѧ��ѧ��: %s\n",e.STU_ID);
      printf("ѧ������: %s\n",e.STU_Name);
      printf("ѧ��Ժϵ: %s\n",e.STU_Dept);
      printf("ѧ��רҵ: %s\n",e.STU_Major);
      printf("ѧ���Ա�: %s\n",e.STU_Sex);               
}

Status ListTraverse_s(LinkList_s L,void(*Print_s)(ElemType_s)) 
{ /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���Print_s��һ��Print_sʧ��,�����ʧ�� */
   LinkList_s p=L->next;
   while(p)
   {
     Print_s(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_s(LinkList_s L,ElemType_s e) /* ��Ԫ��e����Ϣ���뵽�����еĵ�һ���ڵ��� */
{ 
   LinkList_s q=L,p=L->next;
   q->next=(LinkList_s)malloc(sizeof(struct LNode_s)); /* ����L�� */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_s(LinkList_s L,ElemType_s e) 
{ LinkList_s p=L,q;
   while(p->next&&strcmp(p->next->data.STU_ID,e.STU_ID)) 
   {
     p=p->next;
   }
   if(!p->next) /* ɾ��λ�ò����� */
     return ERROR;
   q=p->next; /* ɾ�����ͷŽ�� */
   p->next=q->next;
   free(q);
   return OK;
}

int ListLength_s(LinkList_s L)
{ /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList_s p=L->next; /* pָ���һ����� */
   while(p) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
}



Status InitList_c(LinkList_c *L) //��ʼ������LinkList_c 
{ /* �������������һ���յ����Ա�L */
   *L=(LinkList_c)malloc(sizeof(struct LNode_c)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
}

void Print_c(ElemType_c e)/*�����Ƭ��Ϣ*/
{
      printf("ѧ��ѧ��: %s\n",e.STU_ID);
      printf("ѧ������: %s\n",e.CARD_ID);              
}

Status ListTraverse_c(LinkList_c L,void(*Print_c)(ElemType_c)) 
{ /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���Print_c��һ��Print_cʧ��,�����ʧ�� */
   LinkList_c p=L->next;
   while(p)
   {
     Print_c(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_c(LinkList_c L,ElemType_c e) /* ��Ԫ��e����Ϣ���뵽�����еĵ�һ���ڵ��� */
{ 
   LinkList_c q=L,p=L->next;
   q->next=(LinkList_c)malloc(sizeof(struct LNode_c)); /* ����L�� */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_c(LinkList_c L,ElemType_c e) 
{   
   LinkList_c p=L,q;
   while(p->next&&strcmp(p->next->data.STU_ID,e.STU_ID)) 
   {
     p=p->next;
   }
   if(!p->next) /* ɾ��λ�ò����� */
     return ERROR;
   q=p->next; /* ɾ�����ͷŽ�� */
   p->next=q->next;
   free(q);
   return OK;
}

int ListLength_c(LinkList_c L)
{ /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList_c p=L->next; /* pָ���һ����� */
   while(p) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
}



Status InitList_b(LinkList_b *L) //��ʼ������LinkList_b 
{ /* �������������һ���յ����Ա�L */
   *L=(LinkList_b)malloc(sizeof(struct LNode_b)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
}

void Print_b(ElemType_b e)/*���ͼ����Ϣ*/
{
       printf("�����: %s\n",e.BOOK_ISBN);
      printf("����: %s\n",e.BOOK_Name);
	  printf("����: %s\n",e.BOOK_Authors);
	  printf("������: %s\n",e.BOOK_Publisher);
	  printf("�۸�: %f\n",e.BOOK_Price);
	  printf("����: %u\n",e.BOOK_Amount);
	printf("\n");
}

Status ListTraverse_b(LinkList_b L,void(*Print_b)(ElemType_b)) 
{ /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���Print_b��һ��Print_bʧ��,�����ʧ�� */
   LinkList_b p=L->next;
   while(p)
   {
     Print_b(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_b(LinkList_b L,ElemType_b e) /* ��Ԫ��e����Ϣ���뵽�����еĵ�һ���ڵ��� */
{ 
   LinkList_b q=L,p=L->next;
   q->next=(LinkList_b)malloc(sizeof(struct LNode_b)); /* ����L�� */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_b(LinkList_b L,ElemType_b e) 
{ LinkList_b p=L,q;
   while(p->next&&strcmp(p->next->data.BOOK_ISBN,e.BOOK_ISBN)) 
   {
     p=p->next;
   }
   if(!p->next) /* ɾ��λ�ò����� */
     return ERROR;
   q=p->next; /* ɾ�����ͷŽ�� */
   p->next=q->next;
   free(q);
   return OK;
}



Status InitList_r(LinkList_r *L) //��ʼ������LinkList_r 
{ /* �������������һ���յ����Ա�L */
   *L=(LinkList_r)malloc(sizeof(struct LNode_r)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
}

void Print_r(ElemType_r e)/*���ͼ�������Ϣ*/
{     printf("ѧ��: %s\n",e.STU_ID);
      printf("�����: %s\n",e.BOOK_ISBN);
	  printf("����ʱ��: %d��%d��%d��\n",e.StartTime.year,e.StartTime.month,e.StartTime.day);
	  printf("�黹ʱ��: %d��%d��%d��\n",e.ExpiredTime.year,e.ExpiredTime.month,e.ExpiredTime.day);
	  printf("����: %u\n",e.amount);
}

Status ListTraverse_r(LinkList_r L,void(*Print_r)(ElemType_r)) 
{ /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���Print_r��һ��Print_rʧ��,�����ʧ�� */
   LinkList_r p=L->next;
   while(p)
   {
     Print_r(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_r(LinkList_r L,ElemType_r e) /* ��Ԫ��e����Ϣ���뵽�����еĵ�һ���ڵ��� */
{ 
   LinkList_r q=L,p=L->next;
   q->next=(LinkList_r)malloc(sizeof(struct LNode_r)); /* ����L�� */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_r(LinkList_r L,ElemType_r e) 
{ LinkList_r p=L,q;
   while(p->next&&strcmp(p->next->data.BOOK_ISBN,e.BOOK_ISBN)&&strcmp(p->next->data.STU_ID,e.STU_ID)) 
   {
     p=p->next;
   }
   if(!p->next) /* ɾ��λ�ò����� */
     return ERROR;
   q=p->next; /* ɾ�����ͷŽ�� */
   p->next=q->next;
   free(q);
   return OK;
}
















































