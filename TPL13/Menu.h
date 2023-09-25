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

	std::cout << "Выберите действие\n";
	std::cout << "1 - Работа с Furniture\n";
	std::cout << "2 - Работа с Worker\n";
	std::cout << "3 - Работа с Car\n";
	std::cout << "4 - Вывести все содержимое\n";
	std::cout << "5 - Сохранить в файл все содержимое\n";
	std::cout << "6 - Извлечь из файла\n";
	std::cout << "0 - Выход\n";
	std::cout << "Ваше действие: \n";
	std::cin >> action;

}

void MenuInClass() {
	std::cout << "Выберите действие\n";
	std::cout << "1 - Добавление элемента\n";
	std::cout << "2 - Удаление элемента\n";
	std::cout << "3 - Редактирование элемента\n";
	std::cout << "4 - Вывести все элементы одной категории\n";
	std::cout << "0 - Выход\n";
	std::cout << "Ваше действие: \n";
	std::cin >> actionF;
}

void MenuAttributesF() {
	std::cout << "Выберите что хотите изменить\n";
	std::cout << "1 - Тип мебели\n";
	std::cout << "2 - Размеры\n";
	std::cout << "3 - Цвет\n";
	std::cout << "4 - Материал\n";
	std::cout << "5 - Стоимость\n";
	std::cout << "0 - Выход\n";
	std::cout << "Ваш выбор: \n";
	std::cin >> actionAttribute;
}

void MenuAttributesW() {
	std::cout << "Выберите что хотите изменить\n";
	std::cout << "1 - ФИО\n";
	std::cout << "2 - Должность\n";
	std::cout << "3 - Зар. плата\n";
	std::cout << "4 - Адрес\n";
	std::cout << "5 - Номер телефона\n";
	std::cout << "0 - Выход\n";
	std::cout << "Ваш выбор: \n";
	std::cin >> actionAttribute;
}

void MenuAttributesC() {
	std::cout << "Выберите что хотите изменить\n";
	std::cout << "1 - Марка\n";
	std::cout << "2 - Модель\n";
	std::cout << "3 - Гос. номер\n";
	std::cout << "0 - Выход\n";
	std::cout << "Ваш выбор: \n";
	std::cin >> actionAttribute;
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
				if (f.getCount() == 0) throw std::exception("В Keeper нет элементов");
				
				val = 0;
				std::cout << "Введите номер элемента для извлечения из очереди: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Номер элемента не может быть отрицательным или равным нулю");
				if (f.getCount() < val)  throw std::exception("Такого элемента не существует");
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
				if (w.getCount() == 0) throw std::exception("В Keeper нет элементов");
				val = 0;
				std::cout << "Введите номер элемента для извлечения из очереди: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Номер элемента не может быть отрицательным или равным нулю");
				if (w.getCount() < val )  throw std::exception("Такого элемента не существует");
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
				if (c.getCount() == 0) throw std::exception("В Keeper нет элементов");
				val = 0;
				std::cout << "Введите номер элемента для извлечения из очереди: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("Номер элемента не может быть отрицательным или равным нулю");
				if (c.getCount() < val)  throw std::exception("Такого элемента не существует");
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




