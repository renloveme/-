#include"manager.h"

Manager::Manager(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

//��ʾ������Ϣ
void Manager::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->mname
		<< "\t��λ�� " << this->getdeptname()
		<< "\t��λְ������ϰ彻��������,���·��������ͨԱ��" << endl;
 }

//��ȡ��λ����
string Manager::getdeptname() {
	return string("����");
  }