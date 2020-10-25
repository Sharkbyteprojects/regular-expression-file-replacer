#include "regular expression replacer.h"

using namespace std;

bool fileca(char*, char*, char*, char*);
void autowhile(ifstream&, ofstream&, regex&, char*);
void autowhile(ofstream&, regex&, char*);
void autowhile(ifstream&, regex&, char*);
void autowhile(regex&, char*);

int main(int argc, char* argv[]) {
	cout << initxt << endl;
	if (argc > argsneeded) {
		if (argc > argsneeded + 1) {
			if (!fileca(argv[0 + toappendcount], argv[2 + toappendcount], argv[1 + toappendcount], argv[3 + toappendcount])) {
				return -1;
			}
			else {
				cout << enccode << endl;
			}
		}
		else {
			if (!fileca(argv[0 + toappendcount], argv[2 + toappendcount], argv[1 + toappendcount])) {
				return -1;
			}
			else {
				cout << enccode << endl;
			}
		}
	}
	else {
		cout << helpstr << endl;
	}
	return 0;
}

bool fileca(char* filename, char* regexp, char* outfile, char* tolll = nothing) {
	regex e(regexp);
	if (filename == pipe && outfile != pipe) {
		ofstream data(outfile, ios::trunc);
		if (data.fail()) {
			cerr << errtext << outfile << errtextb << "Writing" << endl;
			return false;
		}
		autowhile(data, e, tolll);
		data.close();
	}
	else if (filename != pipe && outfile == pipe) {
		ifstream infile(filename);
		if (infile.fail()) {
			cerr << errtext << filename << errtextb << "Reading" << endl;
			return false;
		}
		autowhile(infile, e, tolll);
		infile.close();
	}
	else if (filename == pipe && outfile == pipe) {
		autowhile(e, tolll);
	}
	else {
		ifstream infile(filename);
		ofstream data(outfile, ios::trunc);
		if (infile.fail()) {
			cerr << errtext << filename << errtextb << "Reading" << endl;
			return false;
		}
		if (data.fail()) {
			cerr << errtext << outfile << errtextb << "Writing" << endl;
			return false;
		}
		autowhile(infile, data, e, tolll);
		data.close();
		infile.close();
	}
	return true;
}

void autowhile(ifstream& inf, ofstream& dat, regex& e, char* toit) {
	string line;
	while (getline(inf, line)) {
		dat << regex_replace(line, e, toit) << endl;
	}
}

void autowhile(ofstream& dat, regex& e, char* toit) {
	string line;
	while (getline(cin, line)) {
		dat << regex_replace(line, e, toit) << endl;
	}
}

void autowhile(ifstream& inf, regex& e, char* toit) {
	string line;
	while (getline(inf, line)) {
		cout << regex_replace(line, e, toit) << endl;
	}
}

void autowhile(regex& e, char* toit) {
	string line;
	while (getline(cin, line)) {
		cout << regex_replace(line, e, toit) << endl;
	}
}
