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
	void display() override {
		std::cout << "Worker\n";
		std::cout << "fio \t:\t" << fio << '\n';
		std::cout << "pos \t:\t" << post << '\n';
		std::cout << "sal \t:\t" << salary << '\n';
		std::cout << "add \t:\t" << address << '\n';
		std::cout << "num \t:\t" << number << '\n';
		
	}
};