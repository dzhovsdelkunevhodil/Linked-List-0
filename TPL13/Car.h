#pragma once
#include "Factory.h"
#include <iostream>
#include <fstream>
//Для машины определено: марка, модель,гос.номер.
class Car : Factory {

private:
	std::string brand;
	std::string model;
	std::string snumber;

public:

	void setBrand(std::string a) {
		brand = a;
	}

	void setModel(std::string a) {
		model = a;
	}

	void setSnum(std::string a) {
		snumber = a;
	}

	Car() {
#ifdef DEBUG
		std::cout << "Конструктор Car\n";
#endif // DEBUG	
		brand = "";
		model = "";
		snumber = "";
	}

	void getData(std::ofstream& out) override {
		out << "bra: ";
		out << this->brand;
		out << '\n';
		out << "mod: ";
		out << this->model;
		out << '\n';
		out << "snu: ";
		out << this->snumber;
		out << '\n';
	}

	void FsetData(std::ifstream& in) {
		in >> this->brand;
		in >> this->model;
		in >> this->snumber;
	}

	void setData() override {
		std::cout << "bra: ";
		std::cin >> this->brand;
		std::cout << '\n';
		std::cout << "model: ";
		std::cin >> this->model;
		std::cout << '\n';
		std::cout << "snumber: ";
		std::cin >> this->snumber;
		std::cout << '\n';
	}

	friend void operator<< (std::ostream& out, Car& car) {
		std::cout << "Car\n";
		std::cout << "bra \t:\t" << car.brand << '\n';
		std::cout << "mod \t:\t" << car.model << '\n';
		std::cout << "snu \t:\t" << car.snumber << '\n';
	}

};