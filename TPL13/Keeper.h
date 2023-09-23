#pragma once
#include <algorithm>
#include "Menu.h"
void MenuAttributesF();
void MenuAttributesW();
void MenuAttributesC();
template <class T>
class Keeper {


private:
    template <class T>
    class Element {        //  один элемент в очереди
    public:
        T* value;          //значение
        Element<T>* prev;
        
        Element(T data /*= T()*/, Element<T>* prev = nullptr) {    //конструктор элемента
            this->value = &data;
            this->prev = prev;
        }
    };
	int count;
    Element<T>* head;      //указатель на первый элемент
    Element<T>* help;

public:
	Keeper() {
		count = 0;
        head = nullptr;
        help = nullptr;
	}

    T& operator[] (const int index) {

        int cnt = getCount();
        Element<T>* cur;

        cur = this->head;
        while (cur != nullptr) {
            if (cnt == index) {
                return  *(cur->value);
            }

            cur = cur->prev;
            cnt--;
        }
        
    }


    void addElement(T& x) {
        if (head == nullptr) {
            head = new Element<T>(x);
            head->value = &x;
            
        }
        else {
            help = new Element<T>(x);
            help->prev = head;
            head = help;
            head->value = &x;
        }
        count++;
    }




    void extractElement(const int index) {	//метод удаления элемента по индексу

        if (getCount() == 1) {	//если в очереди один элемент
            delete this->head;	//удаляем голову, счетчик=0, пишем соощение
            count--;
            //std::cout << "Очередь полностью извлечена" << std::endl;
        }
        else if (index == getCount()) {	//если удаляется последний элемент
            Element<T>* cur = this->head;	//временный указатель на голову
            head = head->prev;	//передвигаем голову
            delete cur;			//удаляем временный, вместе со старой головой
            count--;	//убавляем на один элемент
        }
        else {		//если не последний, и в очереди >одного элемента
            Element<T>* cur = this->head;		//первый временный
            Element<T>* current1 = this->head;		//второй временный
            int c = getCount();	//количество элементов
            bool flag = 0;	//флаг для прекращения
            while (flag != 1) {
                if (c == index) {		//если дошли до нужного элемента
                    int r = getCount();
                    while (r != (c + 1)) {
                        current1 = current1->prev;	//передвигаем второй на один позже первого временного
                        r--;
                    }
                    Element<T>* temp = cur;//указатель на удаляемый элемент		
                    cur = cur->prev;				//настраиваем указатели
                    current1->prev = cur;		//без удаляемого
                    delete temp;
                    flag = 1;	//прекращение работы
                    count--;	//убавляем элемент

                }
                else {	//если не дошли до нужного элемента
                    cur = cur->prev;	//	двигаемся по очереди
                    c--;
                }
            }
        }
    }
    
    void changeElementW(Keeper<Worker>& w, int& a) {
        int ind = 0;
        std::cout << "Выберите номер элемента для редактирования: ";
        std::cin >> ind;
        std::string valuestr = "";
        int value = 0;
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                w[ind].setFIO(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 2:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                w[ind].setPost(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();

                break;
            case 3:
                system("cls");

                std::cout << w[ind];
                value = 0;
                std::cout << "Введите значение: ";
                std::cin >> value;
                w[ind].setSal(value);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 4:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                w[ind].setAdd(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 5:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                w[ind].setNum(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesW();
                break;

            }
        }

    }
   
    void changeElementF(Keeper<Furniture>& k, int& a) {
        int ind = 0;
        std::cout << "Выберите номер элемента для редактирования: ";
        std::cin >> ind;
        std::string valuestr = "";
        int value = 0;
        int b = 0;
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                k[ind].setType(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 2:
                system("cls");

                std::cout << k[ind];
                value = 0;
                std::cout << "Какой размер хотите изменить \n1 - Глубина\n2 - Высота\n3 - Ширина\n Выбор: ";
                std::cin >> b;
                std::cout << "Введите значение: ";
                std::cin >> value;
                k[ind].setSize(value, b);

                system("pause");
                system("cls");
                MenuAttributesF();
              
                break;
            case 3:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                k[ind].setColor(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 4:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                k[ind].setMat(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 5:
                system("cls");

                std::cout << k[ind];
                value = 0;
                std::cout << "Введите значение: ";
                std::cin >> value;
                k[ind].setCost(value);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesF();
                break;

            }
        }

    }
    
    void changeElementC(Keeper<Car>& c, int& a) {
        int ind = 0;
        std::cout << "Выберите номер элемента для редактирования: ";
        std::cin >> ind;
        std::string valuestr = "";
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                c[ind].setBrand(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();
                break;
            case 2:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                c[ind].setModel(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();

                break;
            case 3:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "Введите значение: ";
                std::cin >> valuestr;
                c[ind].setSnum(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesC();
                break;

            }
        }

    }

    void sortirovka(Keeper<Furniture>& k) {
        
        for (int i = 1;i < k.getCount()+1;++i) {
            for (int j = 1;j < k.getCount();++j) {

                if ((k[j].getCost()) > (k[j + 1].getCost())){
                    Furniture b = k[j]; // создали дополнительную переменную
                    k[j] = k[j + 1]; // меняем местами
                    k[j + 1] = b; // значения элементов
                }
            }
        }

    }


    void display(Keeper<T>& k) {
        std::cout << "\nAll Element of " << typeid(T).name() << std::endl;

        if (k.getCount() == 0) {
            std::cout << "Элементов " << typeid(T).name() << " нет\n";

        }
        for (int i = 1;i < k.getCount() + 1;++i) {
            std::cout << k[i];
            std::cout << '\n';

        }
        std::cout << "\nКоличество элементов " << typeid(T).name()<< " : " << k.getCount() << std::endl << std::endl;
    }



   
    int getCount() { return count; }

};