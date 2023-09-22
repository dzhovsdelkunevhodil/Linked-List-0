#pragma once


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
    

   
    int getCount() { return count; }

};

/*

template<typename T>
class Deque {
private:

    template<typename T>
    class Element {        //  один элемент в очереди
    public:
        T value;          //значение
        Element* next;
        Element* prev;

        Element(T data = T(), Element* next = nullptr, Element* prev = nullptr) {    //конструктор элемента
            this->value = data;
            this->next = next;
            this->prev = prev;
        }
    };

    int count;          //количество элементов в очереди
    Element<T>* left;      //указатель на первый элемент
    Element<T>* right;     //указатель на последний элемент
    Element<T>* help;

public:


    Deque(Deque<T>& dq) {

        count = dq.count;
        for (int i = 0; i < count; i++) {
            addElement(dq[i]);
        }
    }

    int getCount() { return count; }
    virtual ~Deque() {};

    Deque() {

        count = 0;
        left = nullptr;
        right = nullptr;
        help = nullptr;

        //чисто мое задание, заполнение рандомно
        srand(time(0));

        count = rand() % 30;



        for (int i = 0; i < count; i++) {

            if (left == nullptr) {
                left = new Element<T>(rand() % 10);
                help = right = left;
                left->prev = right->prev = nullptr;
            }
            else {
                help = new Element<T>(rand() % 10);
                help->prev = right;
                right->next = help;
                right = help;
                right->prev = help->prev;

            }

        }
        right->next = nullptr;

    }

    void addElement(T x) {
        if (left == nullptr) {
            left = new Element<T>(x);
            left->value = x;
            right = left = help;
        }
        else {
            help = new Element<T>(x);
            help->prev = right;
            right->next = help;
            right = help;
        }
        count++;
    }


    T& operator[] (const int index) {

        int cnt = 0;
        Element<T>* cur;

        cur = this->left;
        while (cur->next != nullptr) {
            if (cnt == index) {
                return  cur->value;
            }

            cur = cur->next;
            cnt++;
        }

    }



    Deque(int size) {
        try {

            if (size == 0) {
                throw 0;
            }

            count = size;
            left = nullptr;
            right = nullptr;
            help = nullptr;


            srand(time(0));




            for (int i = 0; i < count; i++) {

                if (left == nullptr) {
                    left = new Element<T>(rand() % 10);
                    help = right = left;
                    left->prev = right->prev = nullptr;
                }
                else {
                    help = new Element<T>(rand() % 10);
                    help->prev = right;
                    right->next = help;
                    right = help;
                    right->prev = help->prev;

                }
            }
            right->next = nullptr;
        }
        catch (...) {
            //std::cout << "555\n";
            count = 0;
            left = nullptr;
            right = nullptr;
            help = nullptr;


            srand(time(0));

            count = rand() % 30;

            for (int i = 0; i < count; i++) {

                if (left == nullptr) {
                    left = new Element<T>(rand() % 10);
                    help = right = left;
                    left->prev = right->prev = nullptr;
                }
                else {
                    help = new Element<T>(rand() % 10);
                    help->prev = right;
                    right->next = help;
                    right = help;
                    right->prev = help->prev;

                }
            }
            right->next = nullptr;
        }

    }
    friend void operator<< (std::ostream& out, Deque<T>& dq) {
        dq.extractElement(1);

    }

    friend void operator>> (std::ostream& out, Deque<T>& dq) {
        dq.extractElement(0);

    }

    void extractElement(bool b) {
        if (b == 1) {
            help = left;
            left = left->next;
            left->prev = nullptr;
            count--;
            delete help;
        }
        else {
            help = right;
            right = right->prev;
            right->next = nullptr;
            count--;
            delete help;
        }
    }

    friend void operator+ (Deque<T>& fq, Deque<T>& dq) {
        int i;
        if (fq.count <= dq.count) {
            i = 0;
            while (i < fq.count) {
                fq[i] += dq[i];
                i++;
            }

            while (i < dq.count) {
                fq.addElement(dq[i]);
                i++;
            }

        }

        else {
            i = 0;
            while (i < dq.count) {
                fq[i] += dq[i];
                i++;
            }
        }
    }

    friend bool operator> (Deque<T>& fq, Deque<T>& dq) {
        if (fq.count > dq.count) {

            return true;
        }
        else if (fq.count < dq.count) {

            return false;
        }

    }

};*/