#ifndef ENTER_H
#define ENTER_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;

class Users{
	public:
		Users(string name="admin", string pwd="123456") {
			username = name;
			password = pwd;
		}
		bool Check() {
			std::map<string, string> usermessage;
			string n;
			string p;
			ifstream infile;
			infile.open("regist.txt",ios::in);
			while (infile>>n>>p) {
				usermessage[n] = p;
			}
			if (usermessage[username]==password) {
				return true;
			}
			else {
				return false;
			}
		}
	private:
		string username;
		string password;
};
#endif