#pragma once
#include "Factory.h"
//Для машины определено: марка, модель,гос.номер.
class Car : Factory {

private:
	std::string brand;
	std::string model;
	std::string snumber;



public:
	void display() override {
		std::cout << "Car\n";
		std::cout << "bra \t:\t" << brand << '\n';
		std::cout << "mod \t:\t" << model << '\n';
		std::cout << "snu \t:\t" << snumber << '\n';
		
	}
};