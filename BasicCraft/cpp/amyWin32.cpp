#include"amyWin32.h"
#include"windows.h"
void amyFolder::Open(const char* name,bool isiter)
{
	WIN32_FIND_DATAA FindFileData;
	char foldername[MAX_PATH];
	char filename[MAX_PATH];
	strcpy(foldername,name);
	strcpy(filename,foldername);
	strcat(filename,"\\*.*");
	HANDLE hFind; 
	hFind=FindFirstFileA(filename,&FindFileData);   
	if(hFind==INVALID_HANDLE_VALUE)                               //���hFind�������ʧ�ܣ����������Ϣ   
	{  
		FindClose(hFind);   
		return;    
	}  
	else   
	{  
		while(FindNextFileA(hFind,&FindFileData)!=0)                            //���ļ������ļ��д���ʱ   
		{  
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)!=0
				&&strcmp(FindFileData.cFileName,".")==0
				||strcmp(FindFileData.cFileName,"..")==0)        //�ж����ļ���&&��ʾΪ"."||��ʾΪ"."   
			{  
				continue;  
			}  
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)!=0&&isiter==1)      //�ж�������ļ���   
			{  
				char DirAdd[MAX_PATH];  
				strcpy(DirAdd,foldername);  
				strcat(DirAdd,"\\");  
				strcat(DirAdd,FindFileData.cFileName);       //ƴ�ӵõ����ļ��е�����·��   
				Open(DirAdd);                                  //ʵ�ֵݹ����   
			}  
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)==0)    //��������ļ���   
			{  
				char DirAdd[MAX_PATH]; 
				strcpy(DirAdd,foldername);  
				strcat(DirAdd,"\\");  
				strcat(DirAdd,FindFileData.cFileName);       //ƴ�ӵõ����ļ��е�����·��  
				OnFindFile(DirAdd);
			}  
		}  
		FindClose(hFind);  
	}  

}

void amyFolder::OnFindFile(const char* name)
{

}