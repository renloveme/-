#include"WorkerManager.h"


WorkerManager::WorkerManager() {
	//1���ļ�������

	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;   //����
		//��ʼ������
		//��ʼ����¼����
		this->mEmpnum = 0;
		//��ʼ������ָ��
		this->mEmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->mEmpnum = 0;
		//��ʼ������ָ��
		this->mEmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ����ڣ� ���Ҽ�¼����
	int num = this->getEmpnum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->mEmpnum = num; 

	//���ٿռ�
	this->mEmpArray = new Worker*[this->mEmpnum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
	/*//���Դ���
	for (int i = 0; i < mEmpnum; i++)
	{
		cout << "ְ���ţ� " << this->mEmpArray[i]->mid
			<< " ְ�������� " << this->mEmpArray[i]->mname
			<< " ���ű�ţ� " << this->mEmpArray[i]->mdeptid << endl;
	}*/

}

//չʾ�˵�
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void WorkerManager::Exitsystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}
//���ְ��
void WorkerManager::addEmp() {
	cout << "���������ְ��������" << endl;
	int addnum = 0; //�����û�����������
	cin >> addnum;
	if (addnum > 0) {
		//���
		//��������¿ռ��С
		int newSize = this->mEmpnum + addnum;   //�¿ռ�����=ԭ����¼����+��������
		//�����¿ռ�
		Worker ** newSpace=new Worker*[newSize];
		//��ԭ�ռ������ݣ��������¿ռ���
		if (this->mEmpArray != NULL) {
			for (int i = 0; i < this->mEmpnum; i++) {
				newSpace[i] = this->mEmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addnum; i++) {
			int id; //ְ�����
			string name;  //ְ������
			int dSelect;//����ѡ��
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->mEmpnum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->mEmpArray;

		//�����¿ռ��ָ��
		this->mEmpArray = newSpace;

		//�����µĸ���
		this->mEmpnum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󣬱��浽�ļ���
		//��ʾ��Ϣ
		cout << "�ɹ����" << addnum << "����ְ����" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else {
		cout << "������������" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //������ķ�ʽ���ļ� --д�ļ�
	//��ÿ��������д���ļ���
	for (int i = 0; i < this->mEmpnum; i++) {
		ofs << this->mEmpArray[i]->mid << " "
			<< this->mEmpArray[i]->mname << " "
			<< this->mEmpArray[i]->mdeptid << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::getEmpnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ� ��
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//ͳ����������
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker * worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (did == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name, did);

		}
		else if (did == 2) //����
		{
			worker=new Manager(id, name, did);
		}
		else   //�ϰ�
		{
			worker = new Boss(id, name, did);
		}
		this->mEmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}
//��ʾְ��
void WorkerManager::showemp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < mEmpnum; i++) {
			//���ö�̬���ó���ӿ�
			this->mEmpArray[i]->showinfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::delemp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexixt(id);
		if (index != -1) {
			
			for (int i = index; i < this->mEmpnum; i++) {
				//����ǰ��
				this->mEmpArray[i] = this->mEmpArray[i+1];
			}
			this->mEmpnum--; //���������м�¼����
			//���ݸ��µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	//���������������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڣ�������ڷ���ְ����������λ�ã������ڷ���-1
int WorkerManager::isexixt(int id) {
	int index = -1;
	for (int i = 0; i < this->mEmpnum; i++) {
		if (this->mEmpArray[i]->mid == id) {
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//�޸�ְ����Ϣ
void WorkerManager::modemp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {

		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isexixt(id);
		if (ret != -1) {
			//���ҵ���ŵ�ְ��

			delete this->mEmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//�������ݵ�������
			this->mEmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;

			this->save();

		}
		else {
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	//������� ����
	system("pause");
	system("cls");
}
//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = isexixt(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->mEmpArray[ret]->showinfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < mEmpnum; i++)
			{
				if (mEmpArray[i]->mname == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< mEmpArray[i]->mid
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->mEmpArray[i]->showinfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}
//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < mEmpnum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < mEmpnum; j++)
			{
				if (select == 1) //����
				{
					if (mEmpArray[minOrMax]->mid > mEmpArray[j]->mid)
					{
						minOrMax = j;
					}
				}
				else  //����
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

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showemp();
	}

}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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