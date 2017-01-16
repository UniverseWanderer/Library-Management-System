/*该头文件为实现系统功能的函数*/

#define EQ(a,b) (strcmp((a).BOOK_ISBN,(b).BOOK_ISBN))//标识两本书相同

//学生信息建档
void STUDENT_IN(LinkList_s l)
{LinkList_s p=l->next;
 ElemType_s e;
 int flag1=1,flag2=1;
 printf("请输入学号: ");
 scanf("%s",e.STU_ID);
 while(flag2)
 {while(p)
 {if(!strcmp(p->data.STU_ID,e.STU_ID)) 
 {flag1=0;
  break;
 }
 p=p->next;
 }
 if(!flag1)
 {printf("\n输入有误，该用户已注册，请重新输入学号:");
  flag1=1;
  p=l->next;
  scanf("%s",e.STU_ID);
 }
 else flag2=0;
 }
 printf("\n请输入姓名: ");
 scanf("%s",e.STU_Name);
 printf("\n请输入院系: ");
 scanf("%s",e.STU_Dept);
 printf("\n请输入专业: ");
 scanf("%s",e.STU_Major);
 printf("\n请输入性别: ");
 scanf("%s",e.STU_Sex);
 printf("\n");
 InsertAscend_s(l,e);
 printf("输入完毕，信息注册成功\n");
 printf("输出新信息\n");
 Print_s(e);
 }

//借阅卡建档
 void CARD_IN(LinkList_c l1,LinkList_s l2)
 {if(ListLength_c(l1)<ListLength_s(l2))
 {
  LinkList_c p=l1->next;
  LinkList_s q=l2->next;
  ElemType_c e;
  int flag1=0,flag2=1,i=0,j=0;
  printf("请输入学号:");
  scanf("%s",e.STU_ID);
  while(i==0||j==0)
  {flag1=0;
   flag2=1;
   while(flag2)
  {while(q)
  {if(!strcmp(q->data.STU_ID,e.STU_ID))
  {flag1=1;
   break;
  }
  q=q->next;
  }
  if(!flag1)
  {printf("\n输入有误，记录无该信息，请重新输入学号:");
   scanf("%s",e.STU_ID);
   j=0;
   q=l2->next;
  }
  else 
  {flag2=0;
   i++;
  }
   }
  flag1=1;
  flag2=1;
  p=l1->next;
  q=l2->next;
  while(flag2)
  {while(p)
  {if(!strcmp(p->data.STU_ID,e.STU_ID)) 
  {flag1=0;
   break;
  }
  p=p->next;
  }
  if(!flag1)
  {printf("\n输入有误，该用户已发卡，请重新输入学号:");
   flag1=1;
   p=l1->next;
   i=0;
   scanf("%s",e.STU_ID);
 }
  else 
  {flag2=0;
   j++;
 }
  }
  }
  printf("请输入卡号:");
  scanf("%s",e.CARD_ID);
  flag1=1;
  flag2=1;
  p=l1->next;
  q=l2->next;
  while(flag2)
  {while(p)
  {if(!strcmp(p->data.CARD_ID,e.CARD_ID)) 
  {flag1=0;
   break;
  }
  p=p->next;
  }
  if(!flag1)
  {printf("\n输入有误，该卡号已有用户使用，请重新输入卡号:");
   flag1=1;
   p=l1->next;
   scanf("%s",e.CARD_ID);
  }
  else flag2=0;
 }
 InsertAscend_c(l1,e);
 printf("发卡成功\n");
 printf("\n输出新信息\n");
 Print_c(e);
 }
 else printf("记录中所有学生均以被发卡或学生基础档案已空，请按0退出,");
 }

//学生建档（辅助）
 void STUDENT_IN1(LinkList_s l)
 {int flag=1;
  while(flag)
  {printf("请添加个人信息\n");
   STUDENT_IN(l);
   printf("\n\n是否继续添加:(1.是,0.否)");
   while(1)
   {scanf("%d",&flag);
    if(flag==0||flag==1)
		break;
	printf("\n输入有误，请重新输入:");
   }
  }
 }

//借阅卡建档（辅助）
  void CARD_IN1(LinkList_c l1,LinkList_s l2)
 {int flag=1;
  while(flag)
  {printf("请完成发卡操作\n");
   CARD_IN(l1,l2);
   printf("是否继续添加:(1.是,0.否)");
   while(1)
   {scanf("%d",&flag);
    if(flag==0||flag==1)
		break;
	printf("\n输入有误，请重新输入:\n");
   }
  }
 }

//学生信息销档
 void STUDENT_DEL(LinkList_c l1,LinkList_s l2)
 {if(ListLength_s(l2)>0)
 {ElemType_s e;
  ElemType_c e1;
  Status i=0,j=0;
  while(1)
  {printf("请输入要删除的学号:");
   scanf("%s",e.STU_ID);
   strcpy(e1.STU_ID,e.STU_ID);
   i=ListDelete_s(l2,e);
   ListDelete_c(l1,e1);
   if(i)
   {printf("\n删除成功");
	break;
   }
   else printf("\n删除失败，无该记录，请重新输入:");
  }
 }
  else
  printf("\n记录已空，请按0退出:\n");
 }

//借阅卡销档
  void CARD_DEL(LinkList_c l)
  {if(ListLength_c(l)>0)
  {ElemType_c e;
   Status i=0;
   while(1)
   {printf("请输入要删除图书卡所对应的学号:");
    scanf("%s",e.STU_ID);
	i=ListDelete_c(l,e);
	if(i)
	{printf("\n删除成功");
	 break;
	}
	else printf("\n删除失败，无该项记录，请重新输入:");
   }
  }
  else printf("\n图书卡记录已空，请按0退出:\n");
  }

  void STUDENT_DEL1(LinkList_c l1,LinkList_s l2)
  {int flag=1;
   while(flag)
   {printf("请完成删除操作\n");
    STUDENT_DEL(l1,l2);
	printf("是否继续删除(1.是,0.否)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n输入有误，请重新输入:");
    }
   }
  }

//借阅卡销档（辅助）
  void CARD_DEL1(LinkList_c l)
  {int flag=1;
   while(flag)
   {printf("请完成销卡操作\n");
    CARD_DEL(l);
	printf("是否继续删除(1.是,0.否)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n输入有误，请重新输入:");
    }
   }
  }

//图书入库
 void Book_in(LinkList_b *L)
{
	ElemType_b temp;
	LinkList_b p;
	int flag=1;
	while(flag)
	{		
	printf("请输入插入信息：\n索书号:");
	scanf("%s",&temp.BOOK_ISBN);
	printf("书名：");
	scanf("%s",&temp.BOOK_Name);
	printf("作者：");
	scanf("%s",&temp.BOOK_Authors);
	printf("出版社：");
	scanf("%s",&temp.BOOK_Publisher);
	printf("价格：");
	scanf("%f",&(temp.BOOK_Price ));
	printf("数量：");
	scanf("%d",&(temp.BOOK_Amount));

	p=(*L)->next;
	while(p&&EQ(p->data,temp)) p=p->next;
	if(p)//有该图书
	{
		p->data.BOOK_Amount+=temp.BOOK_Amount;
		printf("\n新信息为：\n");
		Print_b(p->data);
		printf("\n入库成功！\n");
	}
	else//无该图书
	{
		InsertAscend_b(*L,temp);
		printf("\n新信息为：\n");
		Print_b(temp);
		printf("入库成功！\n");
	}
	printf("\n是否继续入库？是（1）/否（0）");
	while(1)
	{scanf("%d",&flag);
	 if(flag==1||flag==0)
	  break;
	 else printf("输入不合法，请重新输入\n");
	}
	}
  }

//借书记录信息建立	
void RECORDS_IN(LinkList_c l1,LinkList_b l2,LinkList_r l3)
{ElemType_r e1;
 ElemType_b e2;
 ElemType_c e3;
 LinkList_r p1=l3->next;
 LinkList_b p2=l2->next;
 LinkList_c p3=l1->next;
 if(p2)
 {int flag1=1,flag2=1,flag3=1;
 printf("请输入学号:");
 scanf("%s",e1.STU_ID);
 strcpy(e3.STU_ID,e1.STU_ID);
 while(flag1)
 {while(p3)
 {if(!strcmp(p3->data.STU_ID,e3.STU_ID))
 {flag1=0;
  break;
 }
 else p3=p3->next;
 }
 if(flag1)
 {printf("\n输入有误，该用户不存在，请重新输入:");
  scanf("%s",e1.STU_ID);
  strcpy(e3.STU_ID,e1.STU_ID);
  p3=l1->next;
 }
 }
 printf("\n请输入图书ISBN:");
 scanf("%s",e1.BOOK_ISBN);
 strcpy(e2.BOOK_ISBN,e1.BOOK_ISBN);
 while(flag2)
 {while(p2)
 {if(!strcmp(p2->data.BOOK_ISBN,e2.BOOK_ISBN)&&(p2->data.BOOK_Amount)>0)
 {flag2=0;
  (p2->data.BOOK_Amount)--;
  break;
 }
 else p2=p2->next;
 }
 if(flag2)
 {printf("\n图书信息库无该项记录或该项记录不可借，请重新输入:");
  scanf("%s",e1.BOOK_ISBN);
  strcpy(e2.BOOK_ISBN,e1.BOOK_ISBN);
  p2=l2->next;
 }
 }
 p1=l3->next;
 while(flag3)
 {while(p1)
 {if(!strcmp(p1->data.BOOK_ISBN,e1.BOOK_ISBN)&&!strcmp(p1->data.STU_ID,e1.STU_ID))
 {flag3=0;
  break;
 }
 else p1=p1->next;
 }
 if(flag3)
 {e1.amount=1;
  flag3=0;
 }
 else e1.amount=++(p1->data.amount);
 }
 //调用time.h库获取当前年月日
	time_t timer; 
	struct tm *t; 
	timer=time(NULL); 
	t=localtime(&timer); 
	e1.StartTime.year=e1.ExpiredTime.year=(*t).tm_year+1900;
	e1.StartTime.month=(*t).tm_mon+1;
	e1.ExpiredTime.month=(e1.StartTime.month+2)%12;
	e1.ExpiredTime.day=e1.StartTime.day=(*t).tm_mday;

 InsertAscend_r(l3,e1);
 printf("\n新信息为:\n");
 Print_r(e1);
 printf("添加借阅信息成功!");
 }
 else printf("图书信息库已空,请按0退出\n");
}

//借书记录信息建立（辅助）
 void RECORDS_IN1(LinkList_c l1,LinkList_b l2,LinkList_r l3)
  {int flag=1;
   while(flag)
   {printf("请完成图书借阅操作\n");
    RECORDS_IN(l1,l2,l3);
	printf("\n是否继续添加借阅记录(1.是,0.否)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n输入有误，请重新输入:");
    }
   }
  }

//还书记录信息建立
 void RECORDS_OUT(LinkList_r l1,LinkList_b l2)
 {ElemType_r e1;
  ElemType_b e2;
  LinkList_r p1=l1->next;
  LinkList_b p2=l2->next;
  int flag1=1;
  if(p1)
  {printf("请输入学号:");
  scanf("%s",e1.STU_ID);
  printf("\n请输入要归还图书的ISBN:");
  scanf("%s",e1.BOOK_ISBN);
  strcpy(e2.BOOK_ISBN,e1.BOOK_ISBN);
  while(flag1)
  {while(p1)
  {if(!strcmp(p1->data.STU_ID,e1.STU_ID)&&!strcmp(p1->data.BOOK_ISBN,e1.BOOK_ISBN))
  {flag1=0;
   break;
  }
  p1=p1->next;
  }
  if(flag1)
  {printf("\n无该项借书记录，请重新输入学号:");
   scanf("%s",e1.STU_ID);
   printf("\n请输入要归还图书的ISBN:");
   scanf("%s",e1.BOOK_ISBN);
   strcpy(e2.BOOK_ISBN,e1.BOOK_ISBN);
   p1=l1->next;
  }
  }
  if(p1->data.amount>=1)
  {p1->data.amount--;
   while(p2&&strcmp(p2->data.BOOK_ISBN,e2.BOOK_ISBN))
   p2=p2->next;
   p2->data.BOOK_Amount++;
   printf("\n归还成功");
  }
  if(p1->data.amount==0)
  {ListDelete_r(l1,e1);
   while(p2&&strcmp(p2->data.BOOK_ISBN,e2.BOOK_ISBN))
   p2=p2->next;
   p2->data.BOOK_Amount++;
   printf("\n该学生这类书已归还完全");
  }
   else Print_r(p1->data);
  }
  printf("无学生借阅信息，请按0退出\n");
 }

//还书记录信息建立（辅助）
 void RECORDS_OUT1(LinkList_r l1,LinkList_b l2)
 {int flag=1;
   while(flag)
   {printf("请完成图书归还操作\n");
    RECORDS_OUT(l1,l2);
	printf("是否继续归还图书(1.是,0.否)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n输入有误，请重新输入:");
    }
   }
  } 

//查询借阅记录
 void Search_Records(LinkList_r *L)
{       char flag='`';
	LinkList_r p=(*L)->next;
	int i=0;
	printf("\n当借阅信息：\n");
	if(!p)
		printf("无任何借阅记录！");
	else//输出
	{
		while(p)
		{
			if(p->data.amount!=0)
			{
				Print_r(p->data);
				i++;
			}
			p=p->next;
		}
		printf("\n");
	}
	printf("<<共有 %d 条借阅记录>>\n",i);
	while(flag=='`')
	{
		printf("请按任意键结束该操作\n");
 		scanf("%c",&flag);
	}
}

//查询库存图书
void Search_Books(LinkList_b *L)
{
	LinkList_b p=(*L)->next;
	int i=0;
	char flag='`';
	printf("\n当前图书信息：\n");
	if(!p)
		printf("无任何图书！");
	else//输出图书信息
	{
		while(p)
		{
			if(p->data.BOOK_Amount!=0)
			{
				Print_b(p->data);
				i++;
			}
			p=p->next;
		}
		printf("\n");
	}
	printf("<<共有 %d 种图书>>\n",i);
	while(flag=='`')
	{
		printf("请按任意键结束该操作\n");
 		scanf("%c",&flag);
	}
}