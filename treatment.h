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
		//求文件行数
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
			cout << "请选择:";
			int choose;
			int number = 1;
			//Hospitalr H;//全局变量
			InitHospital(H);//初始化医院
			CreateList_R(H, MAXK);//12个不同的科室
			while (cin>>choose) {
				if (choose == 1) {
					//挂号
					case1();
				}
				else if (choose == 2) {
					//排队
					case2();
				}
				else if (choose == 3) {
					//就诊
					case3();
				}
				else if (choose == 4) {
					//查看排队
					case4();
				}
				else if (choose == 5) {
					//统计
					case5();
				}
				else if (choose == 6) {
					//下班
					case7();
				}
				else if(choose==7){
					case6();
				}
			}
		}
		void yemian() {
			//页面函数
			cout << "****************************" << endl;
			cout << "*病人就医管理系统          *" << endl;
			cout << "*1、挂号                   *" << endl;
			cout << "*2、排队                   *" << endl;
			cout << "*3、就诊                   *" << endl;
			cout << "*4、查看排队               *" << endl;
			cout << "*5、统计                   *" << endl;
			cout << "*6、添加新的科室           *" << endl;
			cout << "*7、退出                   *" << endl;
			cout << "****************************" << endl;
		}
		void readText(string file)
		{
			//创建infile对象
			ifstream infile;
			infile.open(file.data());
			string s;
			//flag必须是全局变量，否则每一次while都会清空
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
			infile.close();             //关闭文件输入流 
		}
		void case1() {
			cout << "请输入患者姓名:";
			string name; cin >> name;
			cout << "请输入患者性别:";
			string sex; cin >> sex;
			cout << "请输入患者年龄:";
			string age; cin >> age;
			cout << "科室:" << endl;
			readText("keshi.txt");
			cout << "请选择科室:";
			int choose2;//科室号
			cin >> choose2;
			ifstream outfile;
			outfile.open("keshi.txt", ios::in);
			string s;
			string str[MAXK];
			int i = 0, j = 0;//while前要全局变量
			Hospital* p;
			p = H;
			while (getline(outfile, s))
			{
				s.erase(0, 4);
				p->next->keshi = s;
				p = p->next;
				str[i] = s; i++;
				if (i == choose2) {
					//选中某个科室
					//在该科室里选择医生
					cout << "请选择医生:" << endl;
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
							//选择的医生
							//队列数组中的第j个
							EnQueue(p->doctor[j - 1], str1[j - 1] + " " + name + "  " + sex + " " + age + "岁");
							string all;
							all = p->doctor[j - 1].base[p->doctor[j - 1].rear - 1];
							cout << "号码:" << p->keshi << all.erase(13, 19) << p->doctor[j - 1].rear << "号" << endl;
						}
					}
				}
			}
			cout << "请继续选择";
			outfile.close();
			//system("cls");
			//yemian();
		}
		void case2() {
			//排队
			system("cls");
			yemian();
			cout << "当前选择排队" << endl;
			cout << "排队成功" << endl;
		}
		void case3() {
			Hospital* p;
			p = H;
			int choose1, choose2;
			cout << "就诊" << endl;
			readText("keshi.txt");
			cout << "请选择:";
			cin >> choose1;
			for (int i = 0; i < choose1; i++) {
				p = p->next;
			}
			readText("doctor.txt");
			cout << "请选择";
			cin >> choose2;
			string e;
			DeQueue(p->doctor[choose2 - 1], e);
			ofstream file;
			file.open("jiuzheng.txt", ios::out | ios::app);
			file << p->keshi << " " << e << "\n";
			cout << "就诊成功" << endl;
		}
		void case4() {
			//查看排队
			system("cls");
			yemian();
			cout << "查看排队" << endl;
			Hospital* q;
			q = H;
			while (q) {
				for (int i = 0; i < 20; i++) {
					//医生
					if (q->doctor[i].number > 0) {
						for (int j = q->doctor[i].front; j < q->doctor[i].rear; j++) {
							string all; all = q->doctor[i].base[j];
							cout << q->keshi << all.erase(13, 19) << j + 1 << "号" << endl;
						}
					}
				}
				q = q->next;
			}
			cout << "请选择:";
		}
		void case5() {
			system("cls");
			yemian();
			cout << "查看排队" << endl;
			Hospital* q;
			q = H;
			while (q) {
				for (int i = 0; i < 20; i++) {
					//医生
					if (q->doctor[i].number > 0) {
						string all; all = q->doctor[i].base[q->doctor[i].rear - 1];
						cout << q->keshi << all.erase(7, 19) << q->doctor[i].number << "人" << endl;
					}
				}
				q = q->next;
			}
			cout << "请选择:";
		}
		void case6() {
			cout << "下班啦！";
			free(H);
			Sleep(1000);
		}
		void case7() {
			cout << "请输入科室";
			int n;
			n = textline();
			ofstream ofile;
			string keshi;
			cin >> keshi;
			ofile.open("keshi.txt", ios::out | ios::app);
			ofile <<n<<"、" << keshi << "\n";
			ofile.close();
			cout << "加入成功" << endl;
			cout << "请选择:";
		}
	private:
		int number;
		Hospitalr H;
};