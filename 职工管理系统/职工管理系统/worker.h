#pragma once
#include<iostream>
using namespace std;
#include<string>


//ְ��������
class Worker {
public:
	//��ʾ������Ϣ

	virtual void showinfo() = 0;

	//��ȡ��λ����
	virtual string getdeptname() = 0;



	//ְ�����
	int mid;

	//ְ������
	string mname;
	//���ű��
	int mdeptid;
};