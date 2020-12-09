#include<iostream>
using namespace std;
#include"WorkerManager.h"

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


int main() {
	/*//测试代码
	Worker *worker = NULL;
	worker = new Employee(1, "法外狂徒", 1);
	worker->showinfo();
	delete worker;
	worker = new Manager(2, "阿狸", 2);
	worker->showinfo();
	delete worker;
	worker = new Boss(3, "范德萨", 3);
	worker->showinfo();
	delete worker;*/


	
	//实例化管理者对象
	WorkerManager wm;

	int choice = 0; //用来存储用户的选项

	while (true) {
		//调用展示菜单成员函数
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice; //接受用户的选项

		switch (choice)
		{
		case 0:  //退出系统
			wm.Exitsystem();
			break;
		case 1:  //增加职工
			wm.addEmp();
			break;
		case 2:  //显示职工
			wm.showemp();
			break;
		case 3:  //删除职工
			wm.delemp();
			break; 
		case 4:  //修改职工
			wm.modemp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");  //清屏
			break;
		}
	}

	


	
	system("pause");
	return 0;
}