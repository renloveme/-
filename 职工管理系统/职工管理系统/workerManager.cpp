#include"WorkerManager.h"


WorkerManager::WorkerManager() {
	//1、文件不存在

	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //读文件
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;   //测试
		//初始化属性
		//初始化记录人数
		this->mEmpnum = 0;
		//初始化数组指针
		this->mEmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		//cout << "文件为空" << endl;
		//初始化记录人数
		this->mEmpnum = 0;
		//初始化数组指针
		this->mEmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在， 并且记录数据
	int num = this->getEmpnum();
	//cout << "职工人数为：" << num << endl;
	this->mEmpnum = num; 

	//开辟空间
	this->mEmpArray = new Worker*[this->mEmpnum];
	//将文件中的数据，存到数组中
	this->init_Emp();
	/*//测试代码
	for (int i = 0; i < mEmpnum; i++)
	{
		cout << "职工号： " << this->mEmpArray[i]->mid
			<< " 职工姓名： " << this->mEmpArray[i]->mname
			<< " 部门编号： " << this->mEmpArray[i]->mdeptid << endl;
	}*/

}

//展示菜单
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManager::Exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}
//添加职工
void WorkerManager::addEmp() {
	cout << "请输入添加职工人数：" << endl;
	int addnum = 0; //保存用户的输入数量
	cin >> addnum;
	if (addnum > 0) {
		//添加
		//计算添加新空间大小
		int newSize = this->mEmpnum + addnum;   //新空间人数=原来记录人数+新增人数
		//开辟新空间
		Worker ** newSpace=new Worker*[newSize];
		//将原空间下内容，拷贝到新空间下
		if (this->mEmpArray != NULL) {
			for (int i = 0; i < this->mEmpnum; i++) {
				newSpace[i] = this->mEmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addnum; i++) {
			int id; //职工编号
			string name;  //职工姓名
			int dSelect;//部门选择
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->mEmpnum + i] = worker;
		}
		//释放原有空间
		delete[] this->mEmpArray;

		//更改新空间的指向
		this->mEmpArray = newSpace;

		//更新新的个数
		this->mEmpnum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//成功添加后，保存到文件中
		//提示信息
		cout << "成功添加" << addnum << "名新职工！" << endl;

		//保存数据到文件中
		this->save();
	}
	else {
		cout << "输入数据有误" << endl;
	}
	//清屏返回
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //用输出的方式打开文件 --写文件
	//将每个人数据写入文件中
	for (int i = 0; i < this->mEmpnum; i++) {
		ofs << this->mEmpArray[i]->mid << " "
			<< this->mEmpArray[i]->mname << " "
			<< this->mEmpArray[i]->mdeptid << endl;
	}
	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::getEmpnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //打开文件 读
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//统计人数变量
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (did == 1)  // 1普通员工
		{
			worker = new Employee(id, name, did);

		}
		else if (did == 2) //经理
		{
			worker=new Manager(id, name, did);
		}
		else   //老板
		{
			worker = new Boss(id, name, did);
		}
		this->mEmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}
//显示职工
void WorkerManager::showemp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < mEmpnum; i++) {
			//利用多态调用程序接口
			this->mEmpArray[i]->showinfo();
		}
	}
	//按任意键返回
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::delemp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexixt(id);
		if (index != -1) {
			
			for (int i = index; i < this->mEmpnum; i++) {
				//数据前移
				this->mEmpArray[i] = this->mEmpArray[i+1];
			}
			this->mEmpnum--; //更新数组中记录人数
			//数据更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}

	}
	//按任意键清屏返回
	system("pause");
	system("cls");
}

//判断职工是否存在，如果存在返回职工所在数组位置，不存在返回-1
int WorkerManager::isexixt(int id) {
	int index = -1;
	for (int i = 0; i < this->mEmpnum; i++) {
		if (this->mEmpArray[i]->mid == id) {
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
//修改职工信息
void WorkerManager::modemp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {

		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isexixt(id);
		if (ret != -1) {
			//查找到编号的职工

			delete this->mEmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker *worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->mEmpArray[ret] = worker;
			cout << "修改成功" << endl;

			this->save();

		}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isexixt(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->mEmpArray[ret]->showinfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < mEmpnum; i++)
			{
				if (mEmpArray[i]->mname == name)
				{
					cout << "查找成功,职工编号为："
						<< mEmpArray[i]->mid
						<< " 号的信息如下：" << endl;

					flag = true;

					this->mEmpArray[i]->showinfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}
//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < mEmpnum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < mEmpnum; j++)
			{
				if (select == 1) //升序
				{
					if (mEmpArray[minOrMax]->mid > mEmpArray[j]->mid)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (mEmpArray[minOrMax]->mid < mEmpArray[j]->mid)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker * temp = mEmpArray[i];
				mEmpArray[i] = mEmpArray[minOrMax];
				mEmpArray[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->showemp();
	}

}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->mEmpArray != NULL)
		{
			for (int i = 0; i < this->mEmpnum; i++)
			{
				if (this->mEmpArray[i] != NULL)
				{
					delete this->mEmpArray[i];
				}
			}
			this->mEmpnum = 0;
			delete[] this->mEmpArray;
			this->mEmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->mEmpArray != NULL)
	{
		for (int i = 0; i < this->mEmpnum; i++) {
			if (this->mEmpArray[i] != NULL) {
				delete this->mEmpArray[i];
			}
		}
		delete[] this->mEmpArray;
		this->mEmpArray = NULL;
	}
}