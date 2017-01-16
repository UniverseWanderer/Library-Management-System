/*该头文件为文件操作辅助函数*/

Status ReadFromFile_s(ElemType_s *e)
{ /* 由fp指定的文件读取结点信息到e */
   int i;
   i=fread(e,sizeof(ElemType_s),1,fp);
   if(i==1) /* 读取文件成功 */
     return OK;
   else
     return ERROR;
}
void WriteToFile_s(ElemType_s e)/* 将结点信息写入fp指定的文件 */
{
   fwrite(&e,sizeof(ElemType_s),1,fp);
}


Status ReadFromFile_c(ElemType_c *e)
{ /* 由fp指定的文件读取结点信息到e */
   int i;
   i=fread(e,sizeof(ElemType_c),1,fp);
   if(i==1) /* 读取文件成功 */
     return OK;
   else
     return ERROR;
}
void WriteToFile_c(ElemType_c e)/* 将结点信息写入fp指定的文件 */
{
   fwrite(&e,sizeof(ElemType_c),1,fp);
}


Status ReadFromFile_b(ElemType_b *e)
{ /* 由fp指定的文件读取结点信息到e */
   int i;
   i=fread(e,sizeof(ElemType_b),1,fp);
   if(i==1) /* 读取文件成功 */
     return OK;
   else
     return ERROR;
}
void WriteToFile_b(ElemType_b e)/* 将结点信息写入fp指定的文件 */
{
   fwrite(&e,sizeof(ElemType_b),1,fp);
}


Status ReadFromFile_r(ElemType_r *e)
{ /* 由fp指定的文件读取结点信息到e */
   int i;
   i=fread(e,sizeof(ElemType_r),1,fp);
   if(i==1) /* 读取文件成功 */
     return OK;
   else
     return ERROR;
}
void WriteToFile_r(ElemType_r e)/* 将结点信息写入fp指定的文件 */
{
   fwrite(&e,sizeof(ElemType_r),1,fp);
}
