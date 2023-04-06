#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include "queue.h"
#include <windows.h>

#define MAXK 20

using namespace std;

class Treat {
	public:
		//���ļ�����
		int textline() {
			number = 0;
			ifstream ifile;
			ifile.open("keshi.txt",ios::in);
			string s;
			while (getline(ifile,s)) {
				number++;
			}
			return number+1;
		}
		Treat() {
			yemian();
			cout << "��ѡ��:";
			int choose;
			int number = 1;
			//Hospitalr H;//ȫ�ֱ���
			InitHospital(H);//��ʼ��ҽԺ
			CreateList_R(H, MAXK);//12����ͬ�Ŀ���
			while (cin>>choose) {
				if (choose == 1) {
					//�Һ�
					case1();
				}
				else if (choose == 2) {
					//�Ŷ�
					case2();
				}
				else if (choose == 3) {
					//����
					case3();
				}
				else if (choose == 4) {
					//�鿴�Ŷ�
					case4();
				}
				else if (choose == 5) {
					//ͳ��
					case5();
				}
				else if (choose == 6) {
					//�°�
					case7();
				}
				else if(choose==7){
					case6();
				}
			}
		}
		void yemian() {
			//ҳ�溯��
			cout << "****************************" << endl;
			cout << "*���˾�ҽ����ϵͳ          *" << endl;
			cout << "*1���Һ�                   *" << endl;
			cout << "*2���Ŷ�                   *" << endl;
			cout << "*3������                   *" << endl;
			cout << "*4���鿴�Ŷ�               *" << endl;
			cout << "*5��ͳ��                   *" << endl;
			cout << "*6������µĿ���           *" << endl;
			cout << "*7���˳�                   *" << endl;
			cout << "****************************" << endl;
		}
		void readText(string file)
		{
			//����infile����
			ifstream infile;
			infile.open(file.data());
			string s;
			//flag������ȫ�ֱ���������ÿһ��while�������
			int flag = 0;
			while (getline(infile, s))
			{
				if (flag == 0) {
					cout << s; flag = 1;
					cout << "   ";
				}
				else if (flag == 1) {
					cout << s << "\n"; flag = 0;
				}
			}
			infile.close();             //�ر��ļ������� 
		}
		void case1() {
			cout << "�����뻼������:";
			string name; cin >> name;
			cout << "�����뻼���Ա�:";
			string sex; cin >> sex;
			cout << "�����뻼������:";
			string age; cin >> age;
			cout << "����:" << endl;
			readText("keshi.txt");
			cout << "��ѡ�����:";
			int choose2;//���Һ�
			cin >> choose2;
			ifstream outfile;
			outfile.open("keshi.txt", ios::in);
			string s;
			string str[MAXK];
			int i = 0, j = 0;//whileǰҪȫ�ֱ���
			Hospital* p;
			p = H;
			while (getline(outfile, s))
			{
				s.erase(0, 4);
				p->next->keshi = s;
				p = p->next;
				str[i] = s; i++;
				if (i == choose2) {
					//ѡ��ĳ������
					//�ڸÿ�����ѡ��ҽ��
					cout << "��ѡ��ҽ��:" << endl;
					readText("doctor.txt");
					int choose3;
					cin >> choose3;
					ifstream outfile1;
					outfile1.open("doctor.txt", ios::in);
					string s1;
					string str1[12];
					while (getline(outfile1, s1)) {
						s1.erase(0, 3);
						str1[j] = s1; j++;
						if (j == choose3) {
							//ѡ���ҽ��
							//���������еĵ�j��
							EnQueue(p->doctor[j - 1], str1[j - 1] + " " + name + "  " + sex + " " + age + "��");
							string all;
							all = p->doctor[j - 1].base[p->doctor[j - 1].rear - 1];
							cout << "����:" << p->keshi << all.erase(13, 19) << p->doctor[j - 1].rear << "��" << endl;
						}
					}
				}
			}
			cout << "�����ѡ��";
			outfile.close();
			//system("cls");
			//yemian();
		}
		void case2() {
			//�Ŷ�
			system("cls");
			yemian();
			cout << "��ǰѡ���Ŷ�" << endl;
			cout << "�Ŷӳɹ�" << endl;
		}
		void case3() {
			Hospital* p;
			p = H;
			int choose1, choose2;
			cout << "����" << endl;
			readText("keshi.txt");
			cout << "��ѡ��:";
			cin >> choose1;
			for (int i = 0; i < choose1; i++) {
				p = p->next;
			}
			readText("doctor.txt");
			cout << "��ѡ��";
			cin >> choose2;
			string e;
			DeQueue(p->doctor[choose2 - 1], e);
			ofstream file;
			file.open("jiuzheng.txt", ios::out | ios::app);
			file << p->keshi << " " << e << "\n";
			cout << "����ɹ�" << endl;
		}
		void case4() {
			//�鿴�Ŷ�
			system("cls");
			yemian();
			cout << "�鿴�Ŷ�" << endl;
			Hospital* q;
			q = H;
			while (q) {
				for (int i = 0; i < 20; i++) {
					//ҽ��
					if (q->doctor[i].number > 0) {
						for (int j = q->doctor[i].front; j < q->doctor[i].rear; j++) {
							string all; all = q->doctor[i].base[j];
							cout << q->keshi << all.erase(13, 19) << j + 1 << "��" << endl;
						}
					}
				}
				q = q->next;
			}
			cout << "��ѡ��:";
		}
		void case5() {
			system("cls");
			yemian();
			cout << "�鿴�Ŷ�" << endl;
			Hospital* q;
			q = H;
			while (q) {
				for (int i = 0; i < 20; i++) {
					//ҽ��
					if (q->doctor[i].number > 0) {
						string all; all = q->doctor[i].base[q->doctor[i].rear - 1];
						cout << q->keshi << all.erase(7, 19) << q->doctor[i].number << "��" << endl;
					}
				}
				q = q->next;
			}
			cout << "��ѡ��:";
		}
		void case6() {
			cout << "�°�����";
			free(H);
			Sleep(1000);
		}
		void case7() {
			cout << "���������";
			int n;
			n = textline();
			ofstream ofile;
			string keshi;
			cin >> keshi;
			ofile.open("keshi.txt", ios::out | ios::app);
			ofile <<n<<"��" << keshi << "\n";
			ofile.close();
			cout << "����ɹ�" << endl;
			cout << "��ѡ��:";
		}
	private:
		int number;
		Hospitalr H;
};