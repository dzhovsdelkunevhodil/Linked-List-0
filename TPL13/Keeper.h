#pragma once


template <class T>
class Keeper {


private:
    template<class T>
    class Element {        //  один элемент в очереди
    public:
        T value;          //значение
        Element<T>* prev;

        Element(T data = T(), Element* prev = nullptr) {    //конструктор элемента
            this->value = data;
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

	}

    void addElement(T x) {
        if (head == nullptr) {
            head = new Element<T>(x);
            head->value = x;
            
        }
        else {
            help = new Element<T>(x);
            help->prev = head;
            head = help;
        }
        count++;
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