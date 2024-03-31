//#include "Myform.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//void main()
//{
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(true);
//	Project1::MyForm form;
//	Application::Run(% form);
//}


// Тестер для очереди
#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
    setlocale(LC_ALL, "Rus");
    QueueQueue Ochered1; // Создаём очередь

    // Проверяем, пустая ли очередь сейчас 
    // Сейчас она пуста, так как мы ничего не добавляли
    if (Ochered1.pusto()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Очередь не пуста" << endl;
    }

    // Добавляем элемент в конец очереди
    int number;
    cout << "Введите число, которое вы хотите добавить в очередь: ";
    cin >> number;
    Ochered1.add_element_v_konets(number);

    // Проверяем, пустая ли очередь сейчас 
    // Сейчас она НЕ пуста, так как мы добавили число number
    if (Ochered1.pusto()){
        cout << "Очередь пуста" << endl;
    }
    else{
        cout << "Очередь не пуста" << endl;
    }
    cout << endl;

    // Теперь берём число, которое мы ввели из очереди
    cout << "Теперь удаляем число из начала очереди" << endl;
    cout << "Число, которое мы удалили из начала очереди: " << Ochered1.del_element_iz_nachala() << endl;
    // Теперь очередь должна быть пустой.
    if (Ochered1.pusto()){
        cout << "Очередь пуста" << endl;
    }
    else{
        cout << "Очередь не пуста" << endl;
    }
    cout << endl;



    // Вводим элементы в очередь
    cout << "Введите количество элементов в очереди: ";
    int size; cin >> size; cout << endl;
    cout << "Введите " << size << " элементов очереди" << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << "Введите " << i << "-ый элемент очереди: ";
        int element;
        cin >> element;
        Ochered1.add_element_v_konets(element);
    }
    cout << endl;

    QueueQueue Ochered2(Ochered1); // Конструктор копирования
    QueueQueue Ochered3 = Ochered1; // Операция присваивания


    // Выведем нашу очередь
    cout << "Вы ввели очередь:" << endl;
    while (!Ochered1.pusto()) {
        cout << Ochered1.del_element_iz_nachala() << endl;
    }
    cout << endl;

    // Проверка конструктора копирования
    cout << "Проверка конструктора копирования:" << endl;
    while (!Ochered2.pusto()){
        cout << Ochered2.del_element_iz_nachala() << endl;
    }
    cout << endl;

    // Проверка операции присваивания
    cout  << "Проверка операции присваивания:" << endl;
    while (!Ochered3.pusto()){
        cout << Ochered3.del_element_iz_nachala() << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}