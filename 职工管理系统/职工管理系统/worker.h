#pragma once
#include<iostream>
using namespace std;
#include<string>


//职工抽象类
class Worker {
public:
	//显示个人信息

	virtual void showinfo() = 0;

	//获取岗位名称
	virtual string getdeptname() = 0;



	//职工编号
	int mid;

	//职工姓名
	string mname;
	//部门编号
	int mdeptid;
};