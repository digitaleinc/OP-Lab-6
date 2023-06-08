#include "realization.h"

void show_menu()
{
    cout << "\nОберіть операцію над чергою:\n";
    cout << "[1] - Вставити елемент у чергу\n";
    cout << "[2] - Вилучити елемент з черги\n";
    cout << "[3] - Вивести чергу у консоль\n";
    cout << "[4] - Вивести інвертовану чергу у консоль\n";
    cout << "[5] - Очистити чергу\n";
    cout << "[6] - Перевірити чи є черга порожньою\n";
    cout << "[7] - Отримати розмір черги\n";
}

string introduce() {
    string type;
    cout << "Оберіть тип даних для роботи з чергою:\n";
    cout << "Введіть назву типу даних (int, double, float, char): ";
    getline(cin, type);
    return type;
}

bool toContinue(string sign) {
    bool flag;
    bool result;
    char ch;
    do{
        cout << sign;
        cin >> ch;
        if(ch == 'y' || ch == 'Y')
        {
            fflush(stdin);
            result = true;
            flag = true;
        }
        else if(ch == 'n' || ch == 'N')
        {
            fflush(stdin);
            result = false;
            flag = true;
        }
        else{
            fflush(stdin);
            cout << "Incorrect input\n";
            flag = false;
        }
    }while(!flag);
    return result;
}

void push_type(string type) {
    if(type == "int")
        work_with_queue<int>(0);
    else if(type == "double")
        work_with_queue<double>(0.0);
    else if(type == "char")
        work_with_queue<char>('0');
    else if(type == "float")
        work_with_queue<float>((float)(0));
}
