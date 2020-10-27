#include <cstdlib>
#include <fstream>
#include <iostream>
#define tfarg 1
#include <string>
#define argsneed 1
using namespace std;

int runit(const char*);

int main(int argc, char* argv[]) {
	cout << u8"exeC0mmandLines\n\u00a9Sharkbyteprojects\n\n";
	if (argc > argsneed) {
		char* filename = argv[tfarg];
		cout << u8"File choosen: \u0022" << filename << u8"\u0022" << endl;
		ifstream infile(filename);
		if (infile) {
			if (infile.fail()) {
				cerr << "Failed to Read" << argv[tfarg] << endl;
				return -2;
			}
			string line;
			while (getline(infile, line)) {
				cout << u8"Running Command \u0022" << line << u8"\u0022\n";
				int exitcode{ runit(line.c_str()) };
				cout << "Exitcode: " << exitcode << "\n";
			}
			cout << flush;
		}
		else {
			cerr << "File dosn't exist" << endl;
			return -2;
		}
		infile.close();
		cout << "Completed run!" << endl;
	}
	else {
		cerr << "Give Me Args!!!\nI need to knew where you commandfile is!!" << endl;
		return -1;
	}
	return 0;
}

int runit(const char* torun) {
	if (torun == (const char*)"") {
		return -1;
	}
	return system(torun);
}
