#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define fflush while (getchar() != '\n')
#define AMOUNTCAR 3 

class car {
private:
    std::string marka; //Марка
    std::string model; //Модель
    float engine; //Объём двигателя
    int power; //Кол-во л.с.
    std::string transmission; //Коробка передач
    std::string color; //Цвет машины
    int year; //Год автомобиля
    int price; //Цена:
    static int count;
public:
    void Init() {
        marka = " ";
        model = " ";
        engine = 0;
        power = 0;
        transmission = " ";
        color = " ";
        year = 0;
        price = 0;
        count++;
    }
    void Init(std::string _marka, std::string _model, float _engine, int _power, std::string _transmission, std::string _color, int _year, int _price) {
        marka = " ";
        model = " ";
        marka = _marka;
        model = _model;
        engine = _engine;
        power = _power;
        transmission = " ";
        color = " ";
        transmission = _transmission;
        color = _color;
        year = _year;
        price = _price;
        count++;
    }
    void Read() {
        printf("Введите марку машины: ");
        std::cin >> marka;
        printf("Введите модель машины: ");
        std::cin >> model;
        printf("Введите объём двигателя: ");
        scanf_s("%f", &engine);
        fflush;
        printf("Введите кол-во л.с.: ");
        scanf_s("%d", &power);
        fflush;
        printf("Введите тип трансмиссии(коробка передач): ");
        std::cin >> transmission;
        printf("Введите цвет автомобиля: ");
        std::cin >> color;
        printf("Введите год автомобиля: ");
        scanf_s("%d", &year);
        fflush;
        printf("Введите цену за данный автомобиль: ");
        scanf_s("%d", &price);
        fflush;
        printf("\n");
    }
    void Display() {
        std::cout << marka << std::endl;
        std::cout << model << std::endl;
        std::cout << engine << std::endl;
        std::cout << power << std::endl;
        std::cout << transmission << std::endl;
        std::cout << color << std::endl;
        std::cout << year << std::endl;
        std::cout << price << std::endl << std::endl;

    }
    void Add(car object) {
        int sum = price + object.price;
        if (sum > 350000) {
            marka = "Ferrari"; model = "F430"; engine = 5.0; power = 440; transmission = "Автомат", color = "Красный", year = 2018; price = 350000;
        }
        else if (sum > 250000) {
            marka = "Nissan"; model = "Skyline"; engine = 3.0; power = 270; transmission = "Автомат", color = "Серебристый", year = 2004; price = 250000;
        }
        else if (sum > 150000) {
            marka = "ВАЗ"; model = "2101"; engine = 1.0; power = 60; transmission = "Механика", color = "Красный", year = 1988; price = 150000;
        }
        else {
            marka = "ЗАЗ"; model = "966"; engine = 0.8; power = 40; transmission = "Механика", color = "Синий", year = 1966; price = 0;
        }
    }
    void Sale(int& _balance) {
        _balance += price;
    }
    void Paint() {
        std::string newColor;
        std::cout << "\nСтарый цвет: " << color << "\tНовый цвет: ";
        std::cin >> newColor;
        color = newColor;
    }
    int* getPrice() {
        return &price;
    }
    int setPrice(int* price) {
        return *price;
    }
    int* getPower() {
        return &power;
    }
    int& setPower(int* power) {
        return *power;
    }

    //Дружественная функция
    friend int getYear(car& CAR);
    //Перегрузка операторов '+', '++'
    car& operator++(); // версия префикс
    car operator++(int); // версия постфикс

    static void RemoveItem() {
        count--;
    }

    static int infoCount() {
        return count;
    }
};

car& car::operator++() {
    power++;
    return *this;
}

car car::operator++(int) {
    engine++;
    return *this;
}

car operator+(car& a, car& b) {
    car c = a;
    c.Add(b);
    return c;
}

int getYear(car& CAR) {
    return CAR.year;
}

int balance = 0;
int car::count = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("color 70");

    int balance = 0;

    car toyota;
    toyota.Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    car bmw;

    //Указатель
    int* power = toyota.getPower();
    /*(*power)++;*/
    toyota.Display();
    //Ссылка
    toyota.setPower(power) = 300;
    toyota++;
    ++toyota;
    ++toyota;
    toyota.Display();

    printf("Год: %d", getYear(toyota));

   /* car::infoCount();
    car* Cars = new car[5];
    for (int i = 0; i < 5; i++) {
        Cars[i].Init();
    }
    printf("%d\n", Cars->infoCount());
    Cars->RemoveItem();
    printf("%d\n", Cars->infoCount());
   
    car toyota;
    toyota.Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    car bmw;
    bmw.Init("bmw", "m5", 2.0, 200, "автомат", "чёрный", 2020, 300000);
    
    car ferrari = toyota + bmw;
    ferrari.Display();*/
}
  

    //system("pause");

    //toyota.Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    //bmw.Init("bmw", "m5", 2.0, 200, "автомат", "чёрный", 2020, 300000);
    //toyota.Add(bmw);
    //toyota.Display();
    //system("pause");
    //system("cls");

    ////Динамические обьекты класса
    //car* lamba;
    //lamba = (car*)calloc(AMOUNTCAR, sizeof(car));
    //lamba = (car*)realloc(lamba, sizeof(car) * AMOUNTCAR * 2);
    //lamba = (car*)calloc(AMOUNTCAR, sizeof(car) * 2);
    //(lamba)->Init();
    //(lamba + 1)->Init("lamba", "veneno", 4.6, 400, "автомат", "красный", 2019, 400000);
    //(lamba + 2)->Init();
    //(lamba + 2)->Read();
    //for (int i = 1; i < AMOUNTCAR; i++)
    //    (lamba + i)->Display();
    //free(lamba);
    //system("pause");
    //system("cls");

    ////Применение new, delete, delete[]
    //car* Cars = new car[AMOUNTCAR];
    //Cars[0].Init();
    //Cars[1].Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    //Cars[2].Init();
    //Cars[2].Read();
    //Cars[2].Paint();
    //Cars[2].Sale(balance);
    //Cars[1].Sale(balance);
    //std::cout << "Баланс: " << balance << std::endl;


    //for (int i = 1; i < AMOUNTCAR; i++)
    //    Cars[i].Display();
    //system("pause");
    //system("cls");
    //delete[] Cars;


