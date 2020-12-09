#pragma once  //防止头文件重复包含
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager {
public:
	WorkerManager();
	//展示菜单
	void showMenu();

	//退出系统
	void Exitsystem();

	//记录职工人数
	int mEmpnum;
	//职工数组指针
	Worker ** mEmpArray;

	//添加职工
	void addEmp();


	//保存文件
	void save();


	//判断文件是否为空 标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int getEmpnum();

	//初始化员工
	void init_Emp();

	//显示职工
	void showemp();

	//删除职工
	void delemp();

	//判断职工是否存在，如果存在返回职工所在数组位置，不存在返回-1
	int isexixt(int id);

	//修改职工信息
	void modemp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();
	
};