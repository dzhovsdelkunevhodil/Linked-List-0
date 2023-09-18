#pragma once
#include "Factory.h"


struct Size {
	int deep;
	int height;
	int width;
};

class Furniture : Factory {



private:
	std::string type;
	Size size;
	std::string color;
	std::string material;
	int cost;

public:
	void display() override {
		std::cout << "Furniture\n";
		std::cout << "typ \t:\t" << type << '\n';
		std::cout << "dee \t:\t" << size.deep << '\n';
		std::cout << "hei \t:\t" << size.height << '\n';
		std::cout << "wid \t:\t" << size.width << '\n';
		std::cout << "col \t:\t" << color << '\n';
		std::cout << "mat \t:\t" << material << '\n';
		std::cout << "cos \t:\t" << cost << '\n';
	}


	Furniture() {
		type = "";
		size.deep = 0;
		size.height = 0;
		size.width = 0;
		color = "";
		material = "";
		cost = 0;
	}

	friend void operator<< (std::ostream& out, Furniture& furn) {
		std::cout << "Furniture\n";
		std::cout << "typ \t:\t" << furn.type << '\n';
		std::cout << "dee \t:\t" << furn.size.deep << '\n';
		std::cout << "hei \t:\t" << furn.size.height << '\n';
		std::cout << "wid \t:\t" << furn.size.width << '\n';
		std::cout << "col \t:\t" << furn.color << '\n';
		std::cout << "mat \t:\t" << furn.material << '\n';
		std::cout << "cos \t:\t" << furn.cost << '\n';

	}


	void setData() {
		std::cout << "typ: ";
		std::cin >> this->type;
		std::cout << '\n';
		std::cout << "dee: ";
		std::cin >> this->size.deep;
		std::cout << '\n';
		std::cout << "hei: ";
		std::cin >> this->size.height;
		std::cout << '\n';
		std::cout << "wid: ";
		std::cin >> this->size.width;
		std::cout << '\n';
		std::cout << "col: ";
		std::cin >> this->color;
		std::cout << '\n';
		std::cout << "mat: ";
		std::cin >> this->material;
		std::cout << '\n';
		std::cout << "cos: ";
		std::cin >> this->cost;
		std::cout << '\n';
	}



	

};