#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager {
public:
	WorkerManager();
	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void Exitsystem();

	//��¼ְ������
	int mEmpnum;
	//ְ������ָ��
	Worker ** mEmpArray;

	//���ְ��
	void addEmp();


	//�����ļ�
	void save();


	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int getEmpnum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void showemp();

	//ɾ��ְ��
	void delemp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ����������λ�ã������ڷ���-1
	int isexixt(int id);

	//�޸�ְ����Ϣ
	void modemp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();
	
};