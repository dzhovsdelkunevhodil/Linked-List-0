#pragma once

#include "Factory.h"
#include <iostream>
#include <fstream>


struct Size {
	int deep;
	int height;
	int width;
};

class Furniture : public Factory {

private:
	std::string type;
	Size size;
	std::string color;
	std::string material;
	int cost;

public:

	void setType(std::string& a) {
		type = a;
	}

	void setSize(int& a, int& b) {

		if (b == 1) {
			size.deep = a;
		}
		if (b == 2) {
			size.height = a;
		}
		if (b == 3) {
			size.width = a;
		}
	}

	void setColor(std::string a) {
		color = a;
	}

	void setMat(std::string a) {
		material = a;
	}

	void setCost(int a) {
		cost = a;
	}

	Furniture() {
#ifdef DEBUG
		std::cout << "Конструктор Furniture\n";
#endif // DEBUG	
		type = "";
		size.deep = 0;
		size.height = 0;
		size.width = 0;
		color = "";
		material = "";
		cost = 0;

	}

	Furniture(Furniture& f) {
		type = f.type;
		size.deep = f.size.deep;
		size.height = f.size.height;
		size.width = f.size.width;
		color = f.color;
		material = f.material;
		cost = f.cost;
	}

	void operator<< (std::ostream& out) override {
		std::cout << "Furniture\n";
		std::cout << "typ \t:\t" << type << '\n';
		std::cout << "dee \t:\t" << size.deep << '\n';
		std::cout << "hei \t:\t" << size.height << '\n';
		std::cout << "wid \t:\t" << size.width << '\n';
		std::cout << "col \t:\t" << color << '\n';
		std::cout << "mat \t:\t" << material << '\n';
		std::cout << "cos \t:\t" << cost << '\n';

	}

	void getData() override {
		std::cout << "typ: ";
		std::cout << this->type;
		std::cout << '\n';
		std::cout << "dee: ";
		std::cout << this->size.deep;
		std::cout << '\n';
		std::cout << "hei: ";
		std::cout << this->size.height;
		std::cout << '\n';
		std::cout << "wid: ";
		std::cout << this->size.width;
		std::cout << '\n';
		std::cout << "col: ";
		std::cout << this->color;
		std::cout << '\n';
		std::cout << "mat: ";
		std::cout << this->material;
		std::cout << '\n';
		std::cout << "cos: ";
		std::cout << this->cost;
		std::cout << '\n';

	}

	void FsetData(std::ifstream& in) override {

		in >> this->type;
		in >> this->size.deep;
		in >> this->size.height;
		in >> this->size.width;
		in >> this->color;
		in >> this->material;
		in >> this->cost;
	}


	void setData() override {

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

	std::string getType() {
		return type;
	}

	int getDeep() {
		return size.deep;
	}

	int getHeight() {
		return size.height;
	}

	int getWidth() {
		return size.width;
	}

	std::string getCol() {
		return color;
	}

	std::string getMat() {
		return material;
	}

	int getCost() {
		return cost;
	}

};