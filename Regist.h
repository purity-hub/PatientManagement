#include <iostream>
#include <fstream>
using namespace std;

class Regist {
	public:
		Regist(string name, string pwd) {
			registname = name;
			registpwd = pwd;
			registinfile();
		}
		void registinfile(){
			ofstream ofile;
			ofile.open("regist.txt", ios::out|ios::app);
			ofile << registname << " " << registpwd << "\n";
			ofile.close();
		}
	private:
		string registname;
		string registpwd;
};