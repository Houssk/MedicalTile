#include"amyAlgorithmRunner.h"
#include"amyAlgorithmThread.h"
#include"amyVariableLing.h"
#include<vector>
#include"amyAlgorithm.h"
#include"amyVariableArea.h"
#include"amyAlgorithmStack.h"
#include"amyVariableView.h"
#include<QThreadPool>
using namespace std;
amyAlgorithmRunner::amyAlgorithmRunner(amyVariableView* a)
{
	m_VariableArea=a;
	m_Thread=new amyAlgorithmThread;
	connect(m_Thread,SIGNAL(finished()),this,SLOT(ProcessOutput()));
}
void amyAlgorithmRunner::RunAlgorithm()
{
	if(0==ProcessInput())
		return;
	
	
	emit s_run_begin();
	m_Algo->Run();
	ProcessOutput();

	//m_Thread->SetAlgorithm(m_Algo);
	////QObject::moveToThread(m_Thread);
	//m_Thread->start();
	
}

bool amyAlgorithmRunner::ProcessInput()
{
	amyAlgorithm *algo=m_Algo;
	vector<amyVariableItem*> lings;
	m_VariableArea->GetSelectedItemArr(lings);
	//////////������
	//if(!algo->CheckInputNum(lings.size()))
	//{
	//	emit s_invalid_inputnum();
	//	return 0;
	//}
	////////��λ������
	qSort(lings.begin(),lings.end(),ItemCompareRight2Left);///��������
	vector<amyVariable> inputarr;
	for(int i=lings.size()-1;i>=0;i--)
	{
		inputarr.push_back(lings[i]->GetInput());
	}
	////////����������
	if(!algo->CheckInputs(inputarr))
	{
		emit s_invalid_inputtype();
		return 0;
	}
	//for(int i=0;i<lings.size();i++)
	//{
	//	if(!algo->CheckArgumetType(lings.size()-1-i,lings[i]->GetInput().GetType()))
	//	{
	//		emit s_invalid_inputtype();
	//		return 0;
	//	}
	//}
	////////ѹ�����ջ
	amyAlgorithmStack* as=amyAlgorithmStack::GetInstance();
	for(int i=0;i<lings.size();i++)       //��ջ���ұߵ�����
	{
		as->Push(lings[i]->GetInput());
	}

	////////������λ���Ƿ�������Ling
	int x=0,y=0;
	if(lings.size()>0)
		m_VariableArea->GetItemPosition(lings[0],x,y);
	int add=x+80;
	while(1)
	{
		lings.clear();
		m_VariableArea->GeItemArrAt(add,y,lings);
		if(lings.size()==0)
			break;
		else
			add+=80;
	}
	m_PosForOutput=QPoint(add,y);
	return 1;
}
void amyAlgorithmRunner::ProcessOutput()
{
	amyAlgorithm *algo=m_Algo;
	amyAlgorithmStack* as=amyAlgorithmStack::GetInstance();
		///////������
	if(!algo->CheckOutputNum(as->GetSize()))
	{
		emit s_invalid_outputnum();
	}

	int add=m_PosForOutput.x();
	int y=m_PosForOutput.y();
	while(1)
	{
		if(as->GetSize()==0)
			break;
		amyVariable v=as->Pop();
		m_VariableArea->AddVariable(v,add,y);
		add+=80;
	}
	emit s_run_end();
}