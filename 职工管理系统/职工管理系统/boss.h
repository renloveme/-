#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int did);

	//显示个人信息
	virtual void showinfo();

	//获取岗位名称
	virtual string getdeptname();
};
