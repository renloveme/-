#include"boss.h"


Boss::Boss(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

//显示个人信息
void Boss::showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->mname
		<< "\t岗位： " << this->getdeptname()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::getdeptname() {
	return string("老板");
}