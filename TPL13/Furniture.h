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


};