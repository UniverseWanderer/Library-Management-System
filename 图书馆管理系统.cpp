#include "c1.h"
#include "define.h"
#include "function.h"
FILE *fp;
#include "xfile.h"
#include "application.h"

void main()
{
	LinkList_s student;		//学生信息		
	LinkList_c card;		//借阅卡信息
	LinkList_b book;		//馆藏图书信息
	LinkList_r record;		//借书信息
	int flag=1;			//系统进入结束标志
	int option=10;		//功能选择标志
	ElemType_s es;
	ElemType_c ec;
	ElemType_b eb;
	ElemType_r er;
	InitList_s(&student);
	InitList_c(&card);
	InitList_b(&book);
	InitList_r(&record);
	//此处读入文件信息，链表初始化
		if((fp=fopen("STUDENTS.txt","rb"))==NULL)
          	{
                 printf("\n打开STUDENTS.txt失败!\n");
                 fp=fopen("STUDENTS.txt","wb");
                 fclose(fp);
                 printf("已为您创建此文件！\n");//强行建立文件 
                 }
               else
               {
                 while(ReadFromFile_s(&es))
                 InsertAscend_s(student,es);
                 fclose(fp);
		}
		if((fp=fopen("CARDS.txt","rb"))==NULL)
          	{
                 printf("\n打开CARDS.txt失败!\n");
                 fp=fopen("CARDS.txt","wb");
                 fclose(fp);
                 printf("已为您创建此文件！\n");//强行建立文件 
                 }
               else
               {
                 while(ReadFromFile_c(&ec))
                 InsertAscend_c(card,ec);
                 fclose(fp);
		}
		if((fp=fopen("BOOKS.txt","rb"))==NULL)
          	{
                 printf("\n打开BOOKS.txt失败!\n");
                 fp=fopen("BOOKS.txt","wb");
                 fclose(fp);
                 printf("已为您创建此文件！\n");//强行建立文件 
                 }
               else
               {
                 while(ReadFromFile_b(&eb))
                 InsertAscend_b(book,eb);
                 fclose(fp);
		}
		if((fp=fopen("RECORDS.txt","rb"))==NULL)
          	{
                 printf("\n打开RECORDS.txt失败!\n");
                 fp=fopen("RECORDS.txt","wb");
                 fclose(fp);
                 printf("已为您创建此文件！\n");//强行建立文件 
                 }
               else
               {
                 while(ReadFromFile_r(&er))
                 InsertAscend_r(record,er);
                 fclose(fp);
		}//信息读取完毕

	printf("*******************************************\n");
	printf("  Welcome to Library Management System!  ");
	printf("\n*******************************************");
	while(flag)
	{
		printf("\n请选择您要进行的操作：\n"); 
		printf("-----------------------\n");
		printf("|1)学生建档\n");
		printf("-----------------------\n");
		printf("|2)学生销档\n");
		printf("-----------------------\n");
		printf("|3)借阅卡发卡\n");
		printf("-----------------------\n");
		printf("|4)借阅卡销户\n");
		printf("-----------------------\n");
		printf("|5)图书入库\n");
		printf("-----------------------\n");
		printf("|6)借书\n");
		printf("-----------------------\n");
		printf("|7)还书\n");
		printf("-----------------------\n");
		printf("|8)借阅情况查询\n");
		printf("-----------------------\n");
		printf("|9)现存图书查询\n");
		printf("-----------------------\n");
		printf("|0)退出系统\n");
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
			//更新后信息存储
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
			//信息存储完毕
			  flag=0;
			  break;
		default:			
			  break;
		}
		else printf("输入有误，请重新输入！\n\n");
	}
	printf("*****感谢您使用图书管理系统！*****\n\n\n\n\n");
}

  







