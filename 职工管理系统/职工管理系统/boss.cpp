#include"boss.h"


Boss::Boss(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

//��ʾ������Ϣ
void Boss::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->mname
		<< "\t��λ�� " << this->getdeptname()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string Boss::getdeptname() {
	return string("�ϰ�");
}