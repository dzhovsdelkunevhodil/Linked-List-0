#pragma once
#include "Factory.h"
//Для машины определено: марка, модель,гос.номер.
class Car : Factory {

private:
	std::string brand;
	std::string model;
	std::string snumber;



public:

	Car() {
		brand = "";
		model = "";
		snumber = "";
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