#include<iostream>
using namespace std;
#include"WorkerManager.h"

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


int main() {
	/*//���Դ���
	Worker *worker = NULL;
	worker = new Employee(1, "�����ͽ", 1);
	worker->showinfo();
	delete worker;
	worker = new Manager(2, "����", 2);
	worker->showinfo();
	delete worker;
	worker = new Boss(3, "������", 3);
	worker->showinfo();
	delete worker;*/


	
	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0; //�����洢�û���ѡ��

	while (true) {
		//����չʾ�˵���Ա����
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice; //�����û���ѡ��

		switch (choice)
		{
		case 0:  //�˳�ϵͳ
			wm.Exitsystem();
			break;
		case 1:  //����ְ��
			wm.addEmp();
			break;
		case 2:  //��ʾְ��
			wm.showemp();
			break;
		case 3:  //ɾ��ְ��
			wm.delemp();
			break; 
		case 4:  //�޸�ְ��
			wm.modemp();
			break;
		case 5:  //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");  //����
			break;
		}
	}

	


	
	system("pause");
	return 0;
}