#pragma once
#include "Furniture.h"
#include "Worker.h"
#include "Keeper.h"
#include "Car.h"
int action;
int actionF;
int val = 0;
int actionAttribute;

void MenuMain() {

	std::cout << "Select command\n";
	std::cout << "1 - Working with Furniture\n";
	std::cout << "2 - Working with Worker\n";
	std::cout << "3 - Working with Car\n";
	std::cout << "4 - Display all\n";
	std::cout << "5 - Save to file\n";
	std::cout << "6 - Extract from file\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: \n";
	//std::cin >> action;

	while (!(std::cin >> action)) {
		std::cout << "Trouble maaaann. Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> action)
			break;
	}

}

void MenuInClass() {
	std::cout << "Select command\n";
	std::cout << "1 - Add element\n";
	std::cout << "2 - Delete Element\n";
	std::cout << "3 - Edit Element\n";
	std::cout << "4 - Display category\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: \n";
	while (!(std::cin >> actionF)) {
		std::cout << "Trouble maaaann. Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		
		if (std::cin >> actionF)
			break;
	}
}

void MenuAttributesF() {
	std::cout << "Select attributes to change\n";
	std::cout << "1 - type\n";
	std::cout << "2 - size\n";
	std::cout << "3 - color\n";
	std::cout << "4 - material\n";
	std::cout << "5 - cost\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: \n";
	while (!(std::cin >> actionAttribute)) {
		std::cout << "Trouble maaaann. Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		
		if (std::cin >> actionAttribute)
			break;
	}
}

void MenuAttributesW() {
	std::cout << "Select attributes to change\n";
	std::cout << "1 - FIO\n";
	std::cout << "2 - post\n";
	std::cout << "3 - salary\n";
	std::cout << "4 - address\n";
	std::cout << "5 - number\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: \n";
	while (!(std::cin >> actionAttribute)) {
		std::cout << "Trouble maaaann. Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		
		if (std::cin >> actionAttribute)
			break;
	}
}

void MenuAttributesC() {
	std::cout << "Select attributes to change\n";
	std::cout << "1 - mark\n";
	std::cout << "2 - model\n";
	std::cout << "3 - snumber\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: \n";
	while (!(std::cin >> actionAttribute)) {
		std::cout << "Trouble maaaann. Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		
		if (std::cin >> actionAttribute)
			break;
	}
}

void MenuFurniture(Keeper<Furniture>& f) {

	setlocale(LC_ALL, "Russian");
	
	Furniture* fu;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {

		switch (actionF) {
		case 1:
			system("cls");
			
			fu = new Furniture;
			fu->setData();
			f.addElement(*fu);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");

			try {
				if (f.getCount() == 0) throw std::exception("Keeper is empty\n");
				
				val = 0;
				std::cout << "Index of element to delete: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Index of element cannot <0 or =0\n");
				if (f.getCount() < val)  throw std::exception("This element don't exist\n");
				std::cout << f[val];
				f.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");
			actionAttribute = 0;
			MenuAttributesF();
			//std::cout<<(f[1].getCost());
			f.changeElementF(f, actionAttribute);

			//f.sortirovka(f);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			f.display(f);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}

void MenuWorker(Keeper<Worker>& w) {

	setlocale(LC_ALL, "Russian");

	Worker* wo;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {
		//MenuInClass();

		switch (actionF) {
		case 1:
			system("cls");

			wo = new Worker;
			wo->setData();
			w.addElement(*wo);


			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");
			try {
				if (w.getCount() == 0) throw std::exception("Keeper is empty\n");

				val = 0;
				std::cout << "Index of element to delete: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Index of element cannot <0 or =0\n");
				if (w.getCount() < val)  throw std::exception("This element don't exist\n");
				std::cout << w[val];
				w.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");

			actionAttribute = 0;
			MenuAttributesW();
			try {
				w.changeElementW(w, actionAttribute);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			w.display(w);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}

void MenuCar(Keeper<Car>& c) {

	setlocale(LC_ALL, "Russian");

	Car* ca;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {

		switch (actionF) {
		case 1:
			system("cls");

			ca = new Car;
			ca->setData();
			c.addElement(*ca);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");
			try {
				if (c.getCount() == 0) throw std::exception("Keeper is empty\n");

				val = 0;
				std::cout << "Index of element to delete: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Index of element cannot <0 or =0\n");
				if (c.getCount() < val)  throw std::exception("This element don't exist\n");
				std::cout << c[val];
				c.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");

			actionAttribute = 0;
			MenuAttributesC();
			c.changeElementC(c, actionAttribute);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			c.display(c);
			
			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}

void Menu() {
	setlocale(LC_ALL, "Russian");
	Keeper<Furniture> fur;
	Keeper<Worker> wor;
	Keeper<Car> car;


	action = 0;
	MenuMain();

	while (action != 0) {
		//MenuMain();

		switch (action) {
		case 1:
			system("cls");

			MenuFurniture(fur);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 2:
			system("cls");

			MenuWorker(wor);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 3:
			system("cls");

			MenuCar(car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 4:
			system("cls");

			fur.display(fur);
			wor.display(wor);
			car.display(car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 5:
			system("cls");

			fur.fileDisplay(fur);
			wor.fileDisplayT(wor);
			car.fileDisplayT(car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 6:
			system("cls");

			fur.fileSetData(fur, wor, car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuMain();
			break;
		}
	}
}

