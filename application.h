/*��ͷ�ļ�Ϊʵ��ϵͳ���ܵĺ���*/

#define EQ(a,b) (strcmp((a).BOOK_ISBN,(b).BOOK_ISBN))//��ʶ��������ͬ

//ѧ����Ϣ����
void STUDENT_IN(LinkList_s l)
{LinkList_s p=l->next;
 ElemType_s e;
 int flag1=1,flag2=1;
 printf("������ѧ��: ");
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
 {printf("\n�������󣬸��û���ע�ᣬ����������ѧ��:");
  flag1=1;
  p=l->next;
  scanf("%s",e.STU_ID);
 }
 else flag2=0;
 }
 printf("\n����������: ");
 scanf("%s",e.STU_Name);
 printf("\n������Ժϵ: ");
 scanf("%s",e.STU_Dept);
 printf("\n������רҵ: ");
 scanf("%s",e.STU_Major);
 printf("\n�������Ա�: ");
 scanf("%s",e.STU_Sex);
 printf("\n");
 InsertAscend_s(l,e);
 printf("������ϣ���Ϣע��ɹ�\n");
 printf("�������Ϣ\n");
 Print_s(e);
 }

//���Ŀ�����
 void CARD_IN(LinkList_c l1,LinkList_s l2)
 {if(ListLength_c(l1)<ListLength_s(l2))
 {
  LinkList_c p=l1->next;
  LinkList_s q=l2->next;
  ElemType_c e;
  int flag1=0,flag2=1,i=0,j=0;
  printf("������ѧ��:");
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
  {printf("\n�������󣬼�¼�޸���Ϣ������������ѧ��:");
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
  {printf("\n�������󣬸��û��ѷ���������������ѧ��:");
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
  printf("�����뿨��:");
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
  {printf("\n�������󣬸ÿ��������û�ʹ�ã����������뿨��:");
   flag1=1;
   p=l1->next;
   scanf("%s",e.CARD_ID);
  }
  else flag2=0;
 }
 InsertAscend_c(l1,e);
 printf("�����ɹ�\n");
 printf("\n�������Ϣ\n");
 Print_c(e);
 }
 else printf("��¼������ѧ�����Ա�������ѧ�����������ѿգ��밴0�˳�,");
 }

//ѧ��������������
 void STUDENT_IN1(LinkList_s l)
 {int flag=1;
  while(flag)
  {printf("����Ӹ�����Ϣ\n");
   STUDENT_IN(l);
   printf("\n\n�Ƿ�������:(1.��,0.��)");
   while(1)
   {scanf("%d",&flag);
    if(flag==0||flag==1)
		break;
	printf("\n������������������:");
   }
  }
 }

//���Ŀ�������������
  void CARD_IN1(LinkList_c l1,LinkList_s l2)
 {int flag=1;
  while(flag)
  {printf("����ɷ�������\n");
   CARD_IN(l1,l2);
   printf("�Ƿ�������:(1.��,0.��)");
   while(1)
   {scanf("%d",&flag);
    if(flag==0||flag==1)
		break;
	printf("\n������������������:\n");
   }
  }
 }

//ѧ����Ϣ����
 void STUDENT_DEL(LinkList_c l1,LinkList_s l2)
 {if(ListLength_s(l2)>0)
 {ElemType_s e;
  ElemType_c e1;
  Status i=0,j=0;
  while(1)
  {printf("������Ҫɾ����ѧ��:");
   scanf("%s",e.STU_ID);
   strcpy(e1.STU_ID,e.STU_ID);
   i=ListDelete_s(l2,e);
   ListDelete_c(l1,e1);
   if(i)
   {printf("\nɾ���ɹ�");
	break;
   }
   else printf("\nɾ��ʧ�ܣ��޸ü�¼������������:");
  }
 }
  else
  printf("\n��¼�ѿգ��밴0�˳�:\n");
 }

//���Ŀ�����
  void CARD_DEL(LinkList_c l)
  {if(ListLength_c(l)>0)
  {ElemType_c e;
   Status i=0;
   while(1)
   {printf("������Ҫɾ��ͼ�鿨����Ӧ��ѧ��:");
    scanf("%s",e.STU_ID);
	i=ListDelete_c(l,e);
	if(i)
	{printf("\nɾ���ɹ�");
	 break;
	}
	else printf("\nɾ��ʧ�ܣ��޸����¼������������:");
   }
  }
  else printf("\nͼ�鿨��¼�ѿգ��밴0�˳�:\n");
  }

  void STUDENT_DEL1(LinkList_c l1,LinkList_s l2)
  {int flag=1;
   while(flag)
   {printf("�����ɾ������\n");
    STUDENT_DEL(l1,l2);
	printf("�Ƿ����ɾ��(1.��,0.��)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n������������������:");
    }
   }
  }

//���Ŀ�������������
  void CARD_DEL1(LinkList_c l)
  {int flag=1;
   while(flag)
   {printf("�������������\n");
    CARD_DEL(l);
	printf("�Ƿ����ɾ��(1.��,0.��)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n������������������:");
    }
   }
  }

//ͼ�����
 void Book_in(LinkList_b *L)
{
	ElemType_b temp;
	LinkList_b p;
	int flag=1;
	while(flag)
	{		
	printf("�����������Ϣ��\n�����:");
	scanf("%s",&temp.BOOK_ISBN);
	printf("������");
	scanf("%s",&temp.BOOK_Name);
	printf("���ߣ�");
	scanf("%s",&temp.BOOK_Authors);
	printf("�����磺");
	scanf("%s",&temp.BOOK_Publisher);
	printf("�۸�");
	scanf("%f",&(temp.BOOK_Price ));
	printf("������");
	scanf("%d",&(temp.BOOK_Amount));

	p=(*L)->next;
	while(p&&EQ(p->data,temp)) p=p->next;
	if(p)//�и�ͼ��
	{
		p->data.BOOK_Amount+=temp.BOOK_Amount;
		printf("\n����ϢΪ��\n");
		Print_b(p->data);
		printf("\n���ɹ���\n");
	}
	else//�޸�ͼ��
	{
		InsertAscend_b(*L,temp);
		printf("\n����ϢΪ��\n");
		Print_b(temp);
		printf("���ɹ���\n");
	}
	printf("\n�Ƿ������⣿�ǣ�1��/��0��");
	while(1)
	{scanf("%d",&flag);
	 if(flag==1||flag==0)
	  break;
	 else printf("���벻�Ϸ�������������\n");
	}
	}
  }

//�����¼��Ϣ����	
void RECORDS_IN(LinkList_c l1,LinkList_b l2,LinkList_r l3)
{ElemType_r e1;
 ElemType_b e2;
 ElemType_c e3;
 LinkList_r p1=l3->next;
 LinkList_b p2=l2->next;
 LinkList_c p3=l1->next;
 if(p2)
 {int flag1=1,flag2=1,flag3=1;
 printf("������ѧ��:");
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
 {printf("\n�������󣬸��û������ڣ�����������:");
  scanf("%s",e1.STU_ID);
  strcpy(e3.STU_ID,e1.STU_ID);
  p3=l1->next;
 }
 }
 printf("\n������ͼ��ISBN:");
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
 {printf("\nͼ����Ϣ���޸����¼������¼���ɽ裬����������:");
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
 //����time.h���ȡ��ǰ������
	time_t timer; 
	struct tm *t; 
	timer=time(NULL); 
	t=localtime(&timer); 
	e1.StartTime.year=e1.ExpiredTime.year=(*t).tm_year+1900;
	e1.StartTime.month=(*t).tm_mon+1;
	e1.ExpiredTime.month=(e1.StartTime.month+2)%12;
	e1.ExpiredTime.day=e1.StartTime.day=(*t).tm_mday;

 InsertAscend_r(l3,e1);
 printf("\n����ϢΪ:\n");
 Print_r(e1);
 printf("��ӽ�����Ϣ�ɹ�!");
 }
 else printf("ͼ����Ϣ���ѿ�,�밴0�˳�\n");
}

//�����¼��Ϣ������������
 void RECORDS_IN1(LinkList_c l1,LinkList_b l2,LinkList_r l3)
  {int flag=1;
   while(flag)
   {printf("�����ͼ����Ĳ���\n");
    RECORDS_IN(l1,l2,l3);
	printf("\n�Ƿ������ӽ��ļ�¼(1.��,0.��)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n������������������:");
    }
   }
  }

//�����¼��Ϣ����
 void RECORDS_OUT(LinkList_r l1,LinkList_b l2)
 {ElemType_r e1;
  ElemType_b e2;
  LinkList_r p1=l1->next;
  LinkList_b p2=l2->next;
  int flag1=1;
  if(p1)
  {printf("������ѧ��:");
  scanf("%s",e1.STU_ID);
  printf("\n������Ҫ�黹ͼ���ISBN:");
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
  {printf("\n�޸�������¼������������ѧ��:");
   scanf("%s",e1.STU_ID);
   printf("\n������Ҫ�黹ͼ���ISBN:");
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
   printf("\n�黹�ɹ�");
  }
  if(p1->data.amount==0)
  {ListDelete_r(l1,e1);
   while(p2&&strcmp(p2->data.BOOK_ISBN,e2.BOOK_ISBN))
   p2=p2->next;
   p2->data.BOOK_Amount++;
   printf("\n��ѧ���������ѹ黹��ȫ");
  }
   else Print_r(p1->data);
  }
  printf("��ѧ��������Ϣ���밴0�˳�\n");
 }

//�����¼��Ϣ������������
 void RECORDS_OUT1(LinkList_r l1,LinkList_b l2)
 {int flag=1;
   while(flag)
   {printf("�����ͼ��黹����\n");
    RECORDS_OUT(l1,l2);
	printf("�Ƿ�����黹ͼ��(1.��,0.��)");
	while(1)
    {scanf("%d",&flag);
     if(flag==0||flag==1)
		break;
	 printf("\n������������������:");
    }
   }
  } 

//��ѯ���ļ�¼
 void Search_Records(LinkList_r *L)
{       char flag='`';
	LinkList_r p=(*L)->next;
	int i=0;
	printf("\n��������Ϣ��\n");
	if(!p)
		printf("���κν��ļ�¼��");
	else//���
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
	printf("<<���� %d �����ļ�¼>>\n",i);
	while(flag=='`')
	{
		printf("�밴����������ò���\n");
 		scanf("%c",&flag);
	}
}

//��ѯ���ͼ��
void Search_Books(LinkList_b *L)
{
	LinkList_b p=(*L)->next;
	int i=0;
	char flag='`';
	printf("\n��ǰͼ����Ϣ��\n");
	if(!p)
		printf("���κ�ͼ�飡");
	else//���ͼ����Ϣ
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
	printf("<<���� %d ��ͼ��>>\n",i);
	while(flag=='`')
	{
		printf("�밴����������ò���\n");
 		scanf("%c",&flag);
	}
}