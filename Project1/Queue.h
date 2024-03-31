#pragma once
#include "Zveno.h"
class QueueQueue{
private:
    Zveno* first;  // Указатель на первый элемент в очереди
    Zveno* last;   // Указатель на последний элемент в очереди

public:
    QueueQueue(){
        first = 0;  // Инициализация указателя на первый элемент нулевым значением
        last = 0;   // Инициализация указателя на последний элемент нулевым значением
    }

    ~QueueQueue(){
        delete first;  // Освобождение памяти, занятой первым элементом
    }

    QueueQueue(const QueueQueue& tmp){ // Конструктор копирования. Создает копию переданной очереди tmp

        if (tmp.first == 0){
            first = 0;
            last = 0;
        }
        else{
            Zveno* current = tmp.first;
            first = new Zveno(*current);  // Создание нового узла с копией информации из первого узла tmp
            last = first;

            // Копирование остальных узлов из tmp в текущую очередь.
            while (current->poluchim_next_uzel() != 0){
                current = current->poluchim_next_uzel();
                Zveno* A = new Zveno(current->poluchim_information());
                last->ustanovim_next_uzel(A);
                last = A;
            }
        }
    }

    QueueQueue& operator=(QueueQueue tmp) {  // Перегруженный оператор присваивания

        if (first != 0){
            delete first;  // Освобождение памяти, занятой текущей очередью
        }

        if (tmp.first == 0){
            first = 0;
            last = 0;
        }
        else{
            Zveno* current = tmp.first;
            first = new Zveno(*current);
            last = first;

            // Копирование остальных узлов из tmp в текущую очередь
            while (current->poluchim_next_uzel() != 0) {
                current = current->poluchim_next_uzel();
                Zveno* A = new Zveno(current->poluchim_information());
                last->ustanovim_next_uzel(A);
                last = A;
            }
        }

        return *this;
    }

    void add_element_v_konets(int tmp){  // Добавление нового элемента в конец очереди
        Zveno* A = new Zveno(tmp);
        if (first == 0) {
            first = A;
            last = A;
        }
        else {
            last->ustanovim_next_uzel(A);
            last = A;
        }
    }

    int del_element_iz_nachala(){       // Удаление и возвращение значения из начала очереди
        if (first != 0) {
            int a = first->poluchim_information();
            Zveno* q = first;
            first = first->poluchim_next_uzel();
            q->ustanovim_next_uzel(0);
            delete q;

            if (first == 0) {
                last = 0;
            }

            return a;
        }

        return -1;  // Возвращение -1 в случае попытки извлечения из пустой очереди
    }

    int pusto(){ // Проверка, является ли очередь пустой

        if (first == 0){
            return 1;  // Возвращение 1, если очередь пуста
        }
        return 0;  // Возвращение 0, если очередь не пуста
    }
};
