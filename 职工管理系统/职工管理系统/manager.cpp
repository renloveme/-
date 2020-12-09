#include"manager.h"

Manager::Manager(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

//显示个人信息
void Manager::showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->mname
		<< "\t岗位： " << this->getdeptname()
		<< "\t岗位职责：完成老板交给的任务,并下发任务给普通员工" << endl;
 }

//获取岗位名称
string Manager::getdeptname() {
	return string("经理");
  }