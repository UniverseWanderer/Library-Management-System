#include "c1.h"
#include "define.h"
#include "function.h"
FILE *fp;
#include "xfile.h"
#include "application.h"

void main()
{
	LinkList_s student;		//ѧ����Ϣ		
	LinkList_c card;		//���Ŀ���Ϣ
	LinkList_b book;		//�ݲ�ͼ����Ϣ
	LinkList_r record;		//������Ϣ
	int flag=1;			//ϵͳ���������־
	int option=10;		//����ѡ���־
	ElemType_s es;
	ElemType_c ec;
	ElemType_b eb;
	ElemType_r er;
	InitList_s(&student);
	InitList_c(&card);
	InitList_b(&book);
	InitList_r(&record);
	//�˴������ļ���Ϣ�������ʼ��
		if((fp=fopen("STUDENTS.txt","rb"))==NULL)
          	{
                 printf("\n��STUDENTS.txtʧ��!\n");
                 fp=fopen("STUDENTS.txt","wb");
                 fclose(fp);
                 printf("��Ϊ���������ļ���\n");//ǿ�н����ļ� 
                 }
               else
               {
                 while(ReadFromFile_s(&es))
                 InsertAscend_s(student,es);
                 fclose(fp);
		}
		if((fp=fopen("CARDS.txt","rb"))==NULL)
          	{
                 printf("\n��CARDS.txtʧ��!\n");
                 fp=fopen("CARDS.txt","wb");
                 fclose(fp);
                 printf("��Ϊ���������ļ���\n");//ǿ�н����ļ� 
                 }
               else
               {
                 while(ReadFromFile_c(&ec))
                 InsertAscend_c(card,ec);
                 fclose(fp);
		}
		if((fp=fopen("BOOKS.txt","rb"))==NULL)
          	{
                 printf("\n��BOOKS.txtʧ��!\n");
                 fp=fopen("BOOKS.txt","wb");
                 fclose(fp);
                 printf("��Ϊ���������ļ���\n");//ǿ�н����ļ� 
                 }
               else
               {
                 while(ReadFromFile_b(&eb))
                 InsertAscend_b(book,eb);
                 fclose(fp);
		}
		if((fp=fopen("RECORDS.txt","rb"))==NULL)
          	{
                 printf("\n��RECORDS.txtʧ��!\n");
                 fp=fopen("RECORDS.txt","wb");
                 fclose(fp);
                 printf("��Ϊ���������ļ���\n");//ǿ�н����ļ� 
                 }
               else
               {
                 while(ReadFromFile_r(&er))
                 InsertAscend_r(record,er);
                 fclose(fp);
		}//��Ϣ��ȡ���

	printf("*******************************************\n");
	printf("  Welcome to Library Management System!  ");
	printf("\n*******************************************");
	while(flag)
	{
		printf("\n��ѡ����Ҫ���еĲ�����\n"); 
		printf("-----------------------\n");
		printf("|1)ѧ������\n");
		printf("-----------------------\n");
		printf("|2)ѧ������\n");
		printf("-----------------------\n");
		printf("|3)���Ŀ�����\n");
		printf("-----------------------\n");
		printf("|4)���Ŀ�����\n");
		printf("-----------------------\n");
		printf("|5)ͼ�����\n");
		printf("-----------------------\n");
		printf("|6)����\n");
		printf("-----------------------\n");
		printf("|7)����\n");
		printf("-----------------------\n");
		printf("|8)���������ѯ\n");
		printf("-----------------------\n");
		printf("|9)�ִ�ͼ���ѯ\n");
		printf("-----------------------\n");
		printf("|0)�˳�ϵͳ\n");
		printf("------------------------");
		scanf("%d",&option);
		fflush(stdin);
		if(option<=9&&option>=0)
		switch(option)
		{
		case 1:STUDENT_IN1(student);
			   break;
		case 2:STUDENT_DEL1(card,student);
			   break;
		case 3:CARD_IN1(card,student);
			   break;
		case 4:CARD_DEL1(card);
			   break;
		case 5:Book_in(&book);
			   break;
		case 6:RECORDS_IN1(card,book,record);
			   break;
		case 7:RECORDS_OUT1(record,book);
			   break;
		case 8:Search_Records(&record);
			   break;
		case 9:Search_Books(&book);
			   break;
		case 0:
			//���º���Ϣ�洢
			fp=fopen("STUDENTS.txt","wb");
			ListTraverse_s(student,WriteToFile_s);
			fclose(fp);

		    fp=fopen("CARDS.txt","wb");
		    ListTraverse_c(card,WriteToFile_c);
		    fclose(fp);

		    fp=fopen("BOOKS.txt","wb");
		    ListTraverse_b(book,WriteToFile_b);
		    fclose(fp);

			fp=fopen("RECORDS.txt","wb");
		    ListTraverse_r(record,WriteToFile_r);
		    fclose(fp);
			//��Ϣ�洢���
			  flag=0;
			  break;
		default:			
			  break;
		}
		else printf("�����������������룡\n\n");
	}
	printf("*****��л��ʹ��ͼ�����ϵͳ��*****\n\n\n\n\n");
}

  







