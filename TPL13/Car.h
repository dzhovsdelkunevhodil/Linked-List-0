#pragma once


#include "Factory.h"
#include <iostream>
#include <fstream>
//
class Car : public Factory {

private:
	std::string brand;
	std::string model;
	std::string snumber;

public:

	void setBrand(std::string& a) {
		brand = a;
	}

	void setModel(std::string& a) {
		model = a;
	}

	void setSnum(std::string& a) {
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

	std::string getBra() {
		return brand;
	}

	std::string getMod() {
		return model;
	}

	std::string getSnu() {
		return snumber;
	}

	void getDataFile(std::ofstream& out) {
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
	void getData() override {
		std::cout << "bra: ";
		std::cout << this->brand;
		std::cout << '\n';
		std::cout << "mod: ";
		std::cout << this->model;
		std::cout << '\n';
		std::cout << "snu: ";
		std::cout << this->snumber;
		std::cout << '\n';
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

	void operator<< (std::ostream& out) override {
		std::cout << "Car\n";
		std::cout << "bra \t:\t" << brand << '\n';
		std::cout << "mod \t:\t" << model << '\n';
		std::cout << "snu \t:\t" << snumber << '\n';
	}

};