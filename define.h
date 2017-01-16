/*该头文件为数据类型定义*/

#include"c1.h"

/*基本结构体定义*/
struct STUDENT		//学生信息
{
  char STU_ID[11];
  char STU_Name[20];
  char STU_Dept[40];
  char STU_Major[40];
  char STU_Sex[10];
};
typedef struct STUDENT ElemType_s;


struct CARD			//借阅卡信息
{
  char STU_ID[11];
  char CARD_ID[15];
};
typedef struct CARD ElemType_c;


struct BOOKS		//馆藏图书信息
{
  char BOOK_ISBN[11];
  char BOOK_Name[40];
  char BOOK_Authors[40];
  char BOOK_Publisher[40];
  float BOOK_Price;
  unsigned int BOOK_Amount;
};
typedef struct BOOKS ElemType_b;


struct DATE			//借书信息
{
  int year,month,day;
};
typedef struct DATE date;
struct RECORDS
{
  char STU_ID[11];
  char BOOK_ISBN[11];
  date StartTime;
  date ExpiredTime;
  unsigned int amount;
};
typedef struct RECORDS ElemType_r;

/*相应链表结点*/
struct LNode_s
{
   ElemType_s data;
   struct LNode_s *next;
};
typedef struct LNode_s *LinkList_s;


struct LNode_c
{
   ElemType_c data;
   struct LNode_c *next;
};
typedef struct LNode_c *LinkList_c;


struct LNode_b
{
   ElemType_b data;
   struct LNode_b *next;
};
typedef struct LNode_b *LinkList_b;


struct LNode_r
{
   ElemType_r data;
   struct LNode_r *next;
};
typedef struct LNode_r *LinkList_r;
















