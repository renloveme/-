#include"employee.h"


Employee::Employee(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;

}

//显示个人信息
	void Employee::showinfo(){
		cout << "职工编号：" << this->mid
			<< "\t职工姓名：" << this->mname
			<< "\t岗位： " << this->getdeptname()
			<<"\t岗位职责：完成经理交给的任务"<< endl;
	}

//获取岗位名称
 string Employee::getdeptname() {
	 return string("员工");
 }