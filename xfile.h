/*��ͷ�ļ�Ϊ�ļ�������������*/

Status ReadFromFile_s(ElemType_s *e)
{ /* ��fpָ�����ļ���ȡ�����Ϣ��e */
   int i;
   i=fread(e,sizeof(ElemType_s),1,fp);
   if(i==1) /* ��ȡ�ļ��ɹ� */
     return OK;
   else
     return ERROR;
}
void WriteToFile_s(ElemType_s e)/* �������Ϣд��fpָ�����ļ� */
{
   fwrite(&e,sizeof(ElemType_s),1,fp);
}


Status ReadFromFile_c(ElemType_c *e)
{ /* ��fpָ�����ļ���ȡ�����Ϣ��e */
   int i;
   i=fread(e,sizeof(ElemType_c),1,fp);
   if(i==1) /* ��ȡ�ļ��ɹ� */
     return OK;
   else
     return ERROR;
}
void WriteToFile_c(ElemType_c e)/* �������Ϣд��fpָ�����ļ� */
{
   fwrite(&e,sizeof(ElemType_c),1,fp);
}


Status ReadFromFile_b(ElemType_b *e)
{ /* ��fpָ�����ļ���ȡ�����Ϣ��e */
   int i;
   i=fread(e,sizeof(ElemType_b),1,fp);
   if(i==1) /* ��ȡ�ļ��ɹ� */
     return OK;
   else
     return ERROR;
}
void WriteToFile_b(ElemType_b e)/* �������Ϣд��fpָ�����ļ� */
{
   fwrite(&e,sizeof(ElemType_b),1,fp);
}


Status ReadFromFile_r(ElemType_r *e)
{ /* ��fpָ�����ļ���ȡ�����Ϣ��e */
   int i;
   i=fread(e,sizeof(ElemType_r),1,fp);
   if(i==1) /* ��ȡ�ļ��ɹ� */
     return OK;
   else
     return ERROR;
}
void WriteToFile_r(ElemType_r e)/* �������Ϣд��fpָ�����ļ� */
{
   fwrite(&e,sizeof(ElemType_r),1,fp);
}
