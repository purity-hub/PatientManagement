#include <iostream>
#include "Enter.h"
#include "treatment.h"
#include "Regist.h"

//using namespace std;

int main()
{
    cout << "****************************"<< endl;
    cout << "*请先登录                  *" << endl;
    cout << "*1、登录                   *" << endl;
    cout << "*2、注册                   *" << endl;
    cout << "*0、退出                   *" << endl;
    cout << "****************************" << endl;
    int choose;
    cout << "请选择:";
    while (cin >> choose) {
        if (choose == 1) {
            string username, password;
            cout << "用户名:";
            cin >> username;
            cout << "密码:";
            cin >> password;
            Users user(username, password);
            //调用user对象的Check方法
            if (user.Check() == true) {
                system("cls");
                Treat();
            }
            else {
                cout << "密码错误" << endl;
            }
            cout << "请选择:";
        }
        else if (choose == 2) {
            cout << "注册" << endl;
            string regname, regpwd;
            cout << "请输入用户名:";
            cin >> regname;
            cout << "请输入密码:";
            cin >> regpwd;
            Regist regist(regname, regpwd);
            cout << "注册成功" << endl;
            cout << "请选择:";
        }
        else if (choose == 0) {
            return 0;
        }
        else {
            cout << "没有这个选项，请重新选择:";
        }
    }
}