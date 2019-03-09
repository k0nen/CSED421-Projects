#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int getFieldLength(string str, int offset) {
	int x = 0;
	while(str[offset+x] == '-') x++;
	return x;
}

string trimString(string str) {
	const auto strBegin = str.find_first_not_of(" ");
	const auto strEnd = str.find_last_not_of(" ");
	const auto strRange = strEnd - strBegin + 1;
	return str.substr(strBegin, strRange);
}

class Customer {
private:
	static int LNAMEoffset, LNAMEsize;
	static int ZONEoffset, ZONEsize;
	static int ACTIVEoffset;

	string LNAME;
	int ZONE, ACTIVE;

public:
	Customer(string line) {
		LNAME = trimString(line.substr(LNAMEoffset, LNAMEsize));
		ZONE = stoi(line.substr(ZONEoffset, ZONEsize));
		ACTIVE = stoi(line.substr(ACTIVEoffset, 1));
	}
	static void setOffset(int LNAMEo, int LNAMEs, int ZONEo, int ZONEs, int ACTIVEo) {
		LNAMEoffset = LNAMEo;
		LNAMEsize = LNAMEs;
		ZONEoffset = ZONEo;
		ZONEsize = ZONEs;
		ACTIVEoffset = ACTIVEo;
	}
	string getLNAME(void) { return LNAME; }
	int getZONE(void) { return ZONE; }
	int getACTIVE(void) { return ACTIVE; }
};

class Zonecost {
private:
	static int ZONEIDoffset, ZONEIDsize;
	static int ZONEDESCoffset, ZONEDESCsize;

	int ZONEID;
	string ZONEDESC;

public:
	Zonecost(string line) {
		ZONEID = stoi(line.substr(ZONEIDoffset, ZONEIDsize));
		ZONEDESC = trimString(line.substr(ZONEDESCoffset, ZONEDESCsize));
	}
	static void setOffset(int ZONEIDo, int ZONEIDs, int ZONEDESCo, int ZONEDESCs) {
		ZONEIDoffset = ZONEIDo;
		ZONEIDsize = ZONEIDs;
		ZONEDESCoffset = ZONEDESCo;
		ZONEDESCsize = ZONEDESCs;
	}
	int getZONEID(void) { return ZONEID; }
	string getZONEDESC(void) { return ZONEDESC; }
};

class Lineitem {
private:
	static int UNAMEoffset, UNAMEsize;
	static int BARCODEoffset, BARCODEsize;
	static int QUANTITYoffset, QUANTITYsize;

	string UNAME;
	int BARCODE;
	int QUANTITY;

public:
	Lineitem(string line) {
		UNAME = trimString(line.substr(UNAMEoffset, UNAMEsize));
		BARCODE = stoi(line.substr(BARCODEoffset, BARCODEsize));
		QUANTITY = stoi(line.substr(QUANTITYoffset, QUANTITYsize));
	}
	static void setOffset(int UNAMEo, int UNAMEs, int BARCODEo, int BARCODEs, int QUANTITYo, int QUANTITYs) {
		UNAMEoffset = UNAMEo;
		UNAMEsize = UNAMEs;
		BARCODEoffset = BARCODEo;
		BARCODEsize = BARCODEs;
		QUANTITYoffset = QUANTITYo;
		QUANTITYsize = QUANTITYs;
	}
	string getUNAME(void) { return UNAME; }
	int getBARCODE(void) { return BARCODE; }
	int getQUANTITY(void) { return QUANTITY; }
};

class Product {
private:
	static int BARCODEoffset, BARCODEsize;
	static int PRODDESCoffset, PRODDESCsize;

	int BARCODE;
	string PRODDESC;

public:
	Product(string line) {
		BARCODE = stoi(line.substr(BARCODEoffset, BARCODEsize));
		PRODDESC = trimString(line.substr(PRODDESCoffset, PRODDESCsize));
	}
	static void setOffset(int BARCODEo, int BARCODEs, int PRODDESCo, int PRODDESCs) {
		BARCODEoffset = BARCODEo;
		BARCODEsize = BARCODEs;
		PRODDESCoffset = PRODDESCo;
		PRODDESCsize = PRODDESCs;
	}
	int getBARCODE(void) { return BARCODE; }
	string getPRODDESC(void) { return PRODDESC; }
};

int Customer::LNAMEoffset, Customer::LNAMEsize;
int Customer::ZONEoffset, Customer::ZONEsize;
int Customer::ACTIVEoffset;
int Zonecost::ZONEIDoffset, Zonecost::ZONEIDsize;
int Zonecost::ZONEDESCoffset, Zonecost::ZONEDESCsize;
int Lineitem::UNAMEoffset, Lineitem::UNAMEsize;
int Lineitem::BARCODEoffset, Lineitem::BARCODEsize;
int Lineitem::QUANTITYoffset, Lineitem::QUANTITYsize;
int Product::BARCODEoffset, Product::BARCODEsize;
int Product::PRODDESCoffset, Product::PRODDESCsize;

void query1(string customerFileName, string zonecostFileName);
void query2(string lineitemFileName, string productFileName);

int main(int argc, char* argv[]) {
    switch(argc) {
		case 4:
			if(string(argv[1]) == "q1") {
				// Query 1
				query1(string(argv[2]), string(argv[3]));
				break;
			}
			else if(string(argv[1]) == "q2") {
				// Query 2
				query2(string(argv[2]), string(argv[3]));
				break;
			}
		default:
			cout << "Usage: <executable> <command> <file1> <file2>" << endl;
			cout << "command: \"q1\" or \"q2\"" << endl;
			break;
	}
	return 0;
}

void query1(string customerFileName, string zonecostFileName) {
	ifstream customerFile, zonecostFile;
	try {
		customerFile.open(customerFileName);
		zonecostFile.open(zonecostFileName);
	}
	catch(const ifstream::failure &e) {
		cout << "Some files are missing. Make sure the files exist." << endl;
		return;
	}

	vector<Customer> customerTable;
	vector<Zonecost> zonecostTable;
	string metadata, lengthdata, rowdata;

	// Parse customerFile
	getline(customerFile, metadata); // Metadata row
	getline(customerFile, lengthdata); // Length row
	int LNAMEo = metadata.find("LNAME");
	int ZONEo = metadata.find("ZONE");
	int ACTIVEo = metadata.find("ACTIVE");
	
	Customer::setOffset(
		LNAMEo, getFieldLength(lengthdata, LNAMEo),
		ZONEo, getFieldLength(lengthdata, ZONEo),
		ACTIVEo);
	while(getline(customerFile, rowdata)) {
		customerTable.push_back(Customer(rowdata));
	}

	// Parse zonecostFile
	getline(zonecostFile, metadata); // Metadata row
	getline(zonecostFile, lengthdata); // Length row
	int ZONEIDo = metadata.find("ZONEID");
	int ZONEDESCo = metadata.find("ZONEDESC");

	
	Zonecost::setOffset(
		ZONEIDo, getFieldLength(lengthdata, ZONEIDo),
		ZONEDESCo, getFieldLength(lengthdata, ZONEDESCo));
	while(getline(zonecostFile, rowdata)) {
		zonecostTable.push_back(Zonecost(rowdata));
	}

	// Create set of 'Toronto' ZONEIDs
	set<int> torontoTable;
	for(auto &x : zonecostTable) {
		if(x.getZONEDESC() == "Toronto") {
			torontoTable.insert(x.getZONEID());
		}
	}

	// For each customer, check ACTIVE and ZONEID
	cout << "LNAME               " << endl;
	cout << "--------------------" << endl;
	for(auto &x : customerTable) {
		if(x.getACTIVE() && torontoTable.find(x.getZONE()) != torontoTable.end()) {
			string tmp = x.getLNAME();
			tmp.append(20 - tmp.size(), ' ');
			cout << tmp << endl;
		}
	}
}

void query2(string lineitemFileName, string productFileName) {
	ifstream lineitemFile, productFile;
	try {
		lineitemFile.open(lineitemFileName);
		productFile.open(productFileName);
	}
	catch(const ifstream::failure &e) {
		cout << "Some files are missing. Make sure the files exist." << endl;
		return;
	}

	vector<Lineitem> lineitemTable;
	map<int, Product> productTable;
	string metadata, lengthdata, rowdata;

	// Parse lineitemFile
	getline(lineitemFile, metadata); // Metadata row
	getline(lineitemFile, lengthdata); // Length row
	int UNAMEo = metadata.find("UNAME");
	int BARCODEo = metadata.find("BARCODE");
	int QUANTITYo = metadata.find("QUANTITY");
	
	Lineitem::setOffset(
		UNAMEo, getFieldLength(lengthdata, UNAMEo),
		BARCODEo, getFieldLength(lengthdata, BARCODEo),
		QUANTITYo, getFieldLength(lengthdata, QUANTITYo));
	while(getline(lineitemFile, rowdata)) {
		lineitemTable.push_back(Lineitem(rowdata));
	}

	// Parse productFile
	getline(productFile, metadata); // Metadata row
	getline(productFile, lengthdata); // Length row
	BARCODEo = metadata.find("BARCODE");
	int PRODDESCo = metadata.find("PRODDESC");

	
	Product::setOffset(
		BARCODEo, getFieldLength(lengthdata, BARCODEo),
		PRODDESCo, getFieldLength(lengthdata, PRODDESCo));
	while(getline(productFile, rowdata)) {
		auto newProduct = Product(rowdata);
		productTable.insert(make_pair(newProduct.getBARCODE(), newProduct));
	}

	// Iterate through each lineitemTable to add records
	map<int, set<string>> transactions;
	for(auto &x : lineitemTable) {
		if(transactions.find(x.getBARCODE()) == transactions.end()) {
			// New item
			auto curProduct = productTable.find(x.getBARCODE());
			set<string> newSet;
			newSet.insert(x.getUNAME());
			transactions.insert(make_pair(x.getBARCODE(), newSet));
		}
		else {
			// Transaction already exists with this item
			// Duplicate members will automatically be ignored
			transactions.find(x.getBARCODE())->second.insert(x.getUNAME());
		}
	}

	// Iterate through transactions to answer the query
	cout << "BARCODE              PRODDESC                                          " << endl;
	cout << "-------------------- --------------------------------------------------" << endl;
	for(auto &x : transactions) {
		if(x.second.size() > 1) {
			string tmp1 = to_string(x.first);
			string tmp2 = productTable.find(x.first)->second.getPRODDESC();
			tmp1.append(20 - tmp1.size(), ' ');
			tmp2.append(50 - tmp2.size(), ' ');
			cout << tmp1 << ' ' << tmp2 << endl;
		}
	}

}
