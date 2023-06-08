#ifndef LAB6_REALIZATION_H
#define LAB6_REALIZATION_H

#include <iostream>
#include "queue.tpp"
#include <Windows.h>
using namespace std;

void show_menu();
string introduce();
bool toContinue(string sign);
void push_type(string type);

template <typename Type>
void work_with_queue(Type value)
{
    int choose;
    bool flag;
    Queue<Type> structure;
    do{
        flag = true;
        show_menu();
        cout << "\nВиберіть дію: ";
        cin >> choose;
        fflush(stdin);
        switch(choose){
            case 1:
                Type tmp;
                do{
                    cout << "Введіть значення елемента: ";
                    cin >> tmp;
                    structure.append(tmp);
                    fflush(stdin);
                }while(toContinue("Продовжити?(y/n): "));
                break;
            case 2:
                cout << "Вилучений елемент з черги: " << structure.pop() << endl;
                break;
            case 3:
                if(!structure.is_empty())
                {
                    cout << "Черга: \n";
                    for(typename Queue<Type>::Iterator it = structure.begin(); it != structure.end(); it++)
                        cout << *it << " ";
                    cout << endl;
                }
                else{
                    cout << "Черга порожня\n";
                }
                break;
            case 4:
                if(!structure.is_empty())
                {
                    cout << "Інвертована черга: \n";
                    for(typename Queue<Type>::Iterator it = structure.rbegin(); it != structure.rend(); it--)
                        cout << *it << " ";
                    cout << endl;
                    break;
                }
                else{
                    cout << "Черга порожня\n";
                }
                break;
            case 5:
                if(structure.is_empty())
                {
                    cout << "Черга вже порожня\n";
                }
                else{
                    cout << "Черга очистилася\n";
                    structure.clear();
                }
                break;
            case 6:
                if(structure.is_empty())
                    cout << "Черга порожня\n";
                else
                    cout << "Черга не порожня\n";
                break;
            case 7:
                cout << "Розмір черги: " << structure.get_size() << endl;
                break;
            default:
                flag = false;
                break;
        }
    }while(flag);
}

#endif