//普通员工
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"


class Employee :public Worker {
public:

	Employee(int id,string name,int did);
	//显示个人信息
	virtual void showinfo();

	//获取岗位名称
	virtual string getdeptname();
};
