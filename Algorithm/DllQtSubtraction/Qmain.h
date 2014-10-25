#pragma once
#include"amyAlgorithm.h"
#include<QApplication>
class amyAlgorithmStack;
class amyDLLSubtractionAlgorithm:public amyAlgorithm
{
public:
	amyDLLSubtractionAlgorithm(amyAlgorithmStack* input);
	virtual bool   CheckArgumetType(int index,VTYPE t)
	{
		if(t==VTYPE_CUBE)return 1;
		else return 0;
	}
	virtual string GetAlgorithmName(){return "QtDllSubtraction";}
	virtual int    GetOutputNum(){return 1;}
	virtual int    GetInputNum(){return 2;}
	virtual void   Run();
	QApplication *m_App;
};
extern "C"
{
_declspec(dllexport) amyAlgorithm*   GetAlgorithm(amyAlgorithmStack* input);
}

BOOL APIENTRY DllMain( HANDLE hModule,     //HANDLE�Ǿ�����͵Ĺؼ���
       DWORD ul_reason_for_call,       //DWORD��˫��
       LPVOID lpReserved       //LPVOID��һ��û�����͵�ָ�룬Ҳ����˵����Խ��������͵�ָ�븳ֵ��LPVOID���͵ı�����һ����Ϊ�������ݣ���Ȼ����ʹ�õ�ʱ����ת��������
       )
{
switch(ul_reason_for_call) 
{ 
case DLL_PROCESS_ATTACH: 
	{
	int a;
  // QApplication *app=new QApplication(a,(char**)0);
	}
   break; 
case DLL_PROCESS_DETACH: 
   break; 
}
return TRUE;
}