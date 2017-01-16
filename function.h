/*该头文件为关于线性链表操作的若干接口*/

/*四类数据_s(student) _c(card) _b(book) _r(record)各有 
初始化、输出、遍历、插入、删除、(s和c数据)求长度 六个接口*/


Status InitList_s(LinkList_s *L) //初始化链表LinkList_s 
{ /* 操作结果：构造一个空的线性表L */
   *L=(LinkList_s)malloc(sizeof(struct LNode_s)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
   return OK;
}

void Print_s(ElemType_s e)/*输出学生信息*/
{
      printf("学生学号: %s\n",e.STU_ID);
      printf("学生姓名: %s\n",e.STU_Name);
      printf("学生院系: %s\n",e.STU_Dept);
      printf("学生专业: %s\n",e.STU_Major);
      printf("学生性别: %s\n",e.STU_Sex);               
}

Status ListTraverse_s(LinkList_s L,void(*Print_s)(ElemType_s)) 
{ /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数Print_s。一旦Print_s失败,则操作失败 */
   LinkList_s p=L->next;
   while(p)
   {
     Print_s(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_s(LinkList_s L,ElemType_s e) /* 将元素e的信息插入到链表中的第一个节点中 */
{ 
   LinkList_s q=L,p=L->next;
   q->next=(LinkList_s)malloc(sizeof(struct LNode_s)); /* 插在L后 */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_s(LinkList_s L,ElemType_s e) 
{ LinkList_s p=L,q;
   while(p->next&&strcmp(p->next->data.STU_ID,e.STU_ID)) 
   {
     p=p->next;
   }
   if(!p->next) /* 删除位置不合理 */
     return ERROR;
   q=p->next; /* 删除并释放结点 */
   p->next=q->next;
   free(q);
   return OK;
}

int ListLength_s(LinkList_s L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
   int i=0;
   LinkList_s p=L->next; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     i++;
     p=p->next;
   }
   return i;
}



Status InitList_c(LinkList_c *L) //初始化链表LinkList_c 
{ /* 操作结果：构造一个空的线性表L */
   *L=(LinkList_c)malloc(sizeof(struct LNode_c)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
   return OK;
}

void Print_c(ElemType_c e)/*输出卡片信息*/
{
      printf("学生学号: %s\n",e.STU_ID);
      printf("学生卡号: %s\n",e.CARD_ID);              
}

Status ListTraverse_c(LinkList_c L,void(*Print_c)(ElemType_c)) 
{ /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数Print_c。一旦Print_c失败,则操作失败 */
   LinkList_c p=L->next;
   while(p)
   {
     Print_c(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_c(LinkList_c L,ElemType_c e) /* 将元素e的信息插入到链表中的第一个节点中 */
{ 
   LinkList_c q=L,p=L->next;
   q->next=(LinkList_c)malloc(sizeof(struct LNode_c)); /* 插在L后 */
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
   if(!p->next) /* 删除位置不合理 */
     return ERROR;
   q=p->next; /* 删除并释放结点 */
   p->next=q->next;
   free(q);
   return OK;
}

int ListLength_c(LinkList_c L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
   int i=0;
   LinkList_c p=L->next; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     i++;
     p=p->next;
   }
   return i;
}



Status InitList_b(LinkList_b *L) //初始化链表LinkList_b 
{ /* 操作结果：构造一个空的线性表L */
   *L=(LinkList_b)malloc(sizeof(struct LNode_b)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
   return OK;
}

void Print_b(ElemType_b e)/*输出图书信息*/
{
       printf("索书号: %s\n",e.BOOK_ISBN);
      printf("书名: %s\n",e.BOOK_Name);
	  printf("作者: %s\n",e.BOOK_Authors);
	  printf("出版社: %s\n",e.BOOK_Publisher);
	  printf("价格: %f\n",e.BOOK_Price);
	  printf("数量: %u\n",e.BOOK_Amount);
	printf("\n");
}

Status ListTraverse_b(LinkList_b L,void(*Print_b)(ElemType_b)) 
{ /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数Print_b。一旦Print_b失败,则操作失败 */
   LinkList_b p=L->next;
   while(p)
   {
     Print_b(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_b(LinkList_b L,ElemType_b e) /* 将元素e的信息插入到链表中的第一个节点中 */
{ 
   LinkList_b q=L,p=L->next;
   q->next=(LinkList_b)malloc(sizeof(struct LNode_b)); /* 插在L后 */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_b(LinkList_b L,ElemType_b e) 
{ LinkList_b p=L,q;
   while(p->next&&strcmp(p->next->data.BOOK_ISBN,e.BOOK_ISBN)) 
   {
     p=p->next;
   }
   if(!p->next) /* 删除位置不合理 */
     return ERROR;
   q=p->next; /* 删除并释放结点 */
   p->next=q->next;
   free(q);
   return OK;
}



Status InitList_r(LinkList_r *L) //初始化链表LinkList_r 
{ /* 操作结果：构造一个空的线性表L */
   *L=(LinkList_r)malloc(sizeof(struct LNode_r)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
   return OK;
}

void Print_r(ElemType_r e)/*输出图书借阅信息*/
{     printf("学号: %s\n",e.STU_ID);
      printf("索书号: %s\n",e.BOOK_ISBN);
	  printf("借阅时间: %d年%d月%d日\n",e.StartTime.year,e.StartTime.month,e.StartTime.day);
	  printf("归还时间: %d年%d月%d日\n",e.ExpiredTime.year,e.ExpiredTime.month,e.ExpiredTime.day);
	  printf("数量: %u\n",e.amount);
}

Status ListTraverse_r(LinkList_r L,void(*Print_r)(ElemType_r)) 
{ /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数Print_r。一旦Print_r失败,则操作失败 */
   LinkList_r p=L->next;
   while(p)
   {
     Print_r(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
}

void InsertAscend_r(LinkList_r L,ElemType_r e) /* 将元素e的信息插入到链表中的第一个节点中 */
{ 
   LinkList_r q=L,p=L->next;
   q->next=(LinkList_r)malloc(sizeof(struct LNode_r)); /* 插在L后 */
   q->next->data=e;
   q->next->next=p;
}

Status ListDelete_r(LinkList_r L,ElemType_r e) 
{ LinkList_r p=L,q;
   while(p->next&&strcmp(p->next->data.BOOK_ISBN,e.BOOK_ISBN)&&strcmp(p->next->data.STU_ID,e.STU_ID)) 
   {
     p=p->next;
   }
   if(!p->next) /* 删除位置不合理 */
     return ERROR;
   q=p->next; /* 删除并释放结点 */
   p->next=q->next;
   free(q);
   return OK;
}
















































