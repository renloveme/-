#include"employee.h"


Employee::Employee(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;

}

//��ʾ������Ϣ
	void Employee::showinfo(){
		cout << "ְ����ţ�" << this->mid
			<< "\tְ��������" << this->mname
			<< "\t��λ�� " << this->getdeptname()
			<<"\t��λְ����ɾ�����������"<< endl;
	}

//��ȡ��λ����
 string Employee::getdeptname() {
	 return string("Ա��");
 }