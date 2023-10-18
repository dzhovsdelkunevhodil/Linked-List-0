#pragma once
#include "Factory.h"
#include <iostream>
#include <fstream>

class Worker : Factory {
private:
	std::string fio;
	std::string post;
	int salary;
	std::string address;
	std::string number;
public:

	void setFIO(std::string& a) {
		fio = a;
	}

	void setPost(std::string& a) {
		post = a;
	}

	void setSal(int& a) {
		salary = a;
	}

	void setAdd(std::string& a) {
		address = a;
	}

	void setNum(std::string& a) {
		number = a;
	}

	Worker() {
#ifdef DEBUG
		std::cout << "Constructor Worker\n";
#endif // DEBUG	
		fio = "";
		post = "";
		salary = 0;
		address = "";
		number = "";
	}

	std::string getFIO() {
		return fio;
	}
	
	std::string getPos() {
		return post;
	}
	int getSal() {
		return salary;
	}
	std::string getAdd() {
		return address;
	}
	std::string getNum() {
		return number;
	}


	void getData(std::ofstream& out) override {
		out << "fio: ";
		out << this->fio;
		out << '\n';
		out << "pos: ";
		out << this->post;
		out << '\n';
		out << "sal: ";
		out << this->salary;
		out << '\n';
		out << "add: ";
		out << this->address;
		out << '\n';
		out << "num: ";
		out << this->number;
		out << '\n';
	}

	void FsetData(std::ifstream& in) override {
		in >> this->fio;
		in >> this->post;
		in >> this->salary;
		in >> this->address;
		in >> this->number;
	}

	void setData() override {
		
			std::cout << "fio: ";
			std::cin >> this->fio;
			std::cout << '\n';
			std::cout << "pos: ";
			std::cin >> this->post;
			std::cout << '\n';
			std::cout << "sal: ";
			std::cin >> this->salary;
			
			std::cout << '\n';
			std::cout << "add: ";
			std::cin >> this->address;
			std::cout << '\n';
			std::cout << "num: ";
			std::cin >> this->number;
			std::cout << '\n';
		
		
	}

	friend void operator<< (std::ostream& out, Worker& work) {
		std::cout << "Worker\n";
		std::cout << "fio \t:\t" << work.fio << '\n';
		std::cout << "pos \t:\t" << work.post << '\n';
		std::cout << "sal \t:\t" << work.salary << '\n';
		std::cout << "add \t:\t" << work.address << '\n';
		std::cout << "num \t:\t" << work.number << '\n';
	}

};