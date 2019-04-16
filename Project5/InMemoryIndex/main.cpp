#include <stdio.h>
#include "timer.hpp"
#include "util.hpp"
#include <assert.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define INSERT 0
#define READ 1
#define UPDATE 2
#define SCAN 3
 

class InMemoryIndex {
public:
	std::map<uint64_t, int8_t> index;
	
	void insert(uint64_t key, int8_t value) {
		index[key] = value;
		// Impleent this function
	}

	void update(uint64_t key, int8_t value) {
		index[key] = value;
		// Impleent this function
	}

	int8_t read(uint64_t key) {
		return index[key];
		// Impleent this function
	}

	uint64_t scan(uint64_t key, int8_t num) {
		auto it = index.lower_bound(key);
		uint64_t result = 0;
		for (int8_t i = 0; i < num; ++i) {
			if (it == index.end()) break;
			result += it->second;
			++it;
		}
		// Impleent this function
		return result;
	}
};

struct Operation {
	int type;
	uint64_t key;
	int num;

	Operation() {
		type = -1; key = 0; num = 0;
	}
	Operation(int t, uint64_t k, int n) {
		type = t; key = k; num = n;
	}
};

InMemoryIndex tree;
std::vector<Operation> inits;
std::vector<Operation> txns;

double load (std::string &fname, std::vector<Operation> &ops, uint64_t limit) {
	Timer timer;
	timer.start();
	ops.reserve(limit);
	std::ifstream infile(fname);
	std::string op;
	uint64_t key;
	int num;
	for (uint64_t count = 0; count < limit && infile.good(); ++count) {
		infile >> op >> key;
		if (op.compare("INSERT") == 0) {
			ops.emplace_back(INSERT, key, 0); 
		} else if (op.compare("READ") == 0) {
			ops.emplace_back(READ, key, 0); 
		} else if (op.compare("UPDATE") == 0) {
			ops.emplace_back(UPDATE, key, 0); 
		} else if (op.compare("SCAN") == 0) {
			infile >> num;
			ops.emplace_back(SCAN, key, num); 
		}
	}
	infile.close();
	return timer.get_elapsed_time();
}

double exec_loads (std::vector<Operation> &ops) {
	Timer timer;
	timer.start();
	for (auto op = ops.begin(); op != ops.end(); ++op) {
		if (op->type == INSERT) {
			tree.insert(op->key, 1);
		} 
	}
	return timer.get_elapsed_time();
}

uint64_t read_result = 0;
uint64_t scan_result = 0;

double exec_txns (std::vector<Operation> &ops) {
	Timer timer;
	timer.start();
	for (auto op = ops.begin(); op != ops.end(); ++op) {
		if (op->type == INSERT) {
			tree.insert(op->key, 1);
		} else if (op->type == READ) {
			read_result += tree.read(op->key);
		} else if (op->type == UPDATE) {
			tree.update(op->key, 2);
		} else if (op->type == SCAN) {
			scan_result += tree.scan(op->key, op->num);
		}
	}
	return timer.get_elapsed_time();
}

int main(int argc, char* argv[]) {
	std::string load_fname(argv[1]);
	std::string txns_fname(argv[2]);
	size_t load_size = stoi(argv[3]);
	size_t txns_size = stoi(argv[4]);

	std::cout << "load_fname: " << load_fname << "\n";
	std::cout << "txns_fname: " << txns_fname << "\n";

	load(load_fname, inits, load_size);
	std::cout << "Execute " << load_size << " operations\n";
	double load_time = exec_loads(inits);
	std::cout << "load time(ms): " << load_time << "\n";
	inits.clear();

	load(txns_fname, txns, txns_size);
	std::cout << "Execute " << txns_size << " operations\n";
	double txns_time = exec_txns(txns);
	std::cout << "txns time(ms): " << txns_time << "\n";
	std::cout << "sum of values of read entries: " << read_result << "\n";
	std::cout << "sum of values of scanned entries: " << scan_result << "\n";
	return 1;
}
