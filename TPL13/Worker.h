#pragma once
#include "Factory.h"
//Для работника определено: ФИО, должность, заработная плата,адрес проживания, телефон.
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
		fio = "";
		post = "";
		salary = 0;
		address = "";
		number = "";
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