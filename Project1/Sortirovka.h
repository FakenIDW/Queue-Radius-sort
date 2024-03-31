#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

//Реализация алгоритма поразрядной сортировки для массива чисел
//Класс Sort использует объекты класса Queue для организации очередей чисел на каждом шаге сортировки

class Sort {
private:
    QueueQueue* Och;        // Указатель на массив очередей.
    int size,          // Размер массива mem.
        max_num_dig,   // Максимальное количество цифр в числах массива mem.
        val,           // Вспомогательная переменная для подсчета количества цифр в числе.
        flag;          // Вспомогательная переменная для хранения значения числа и индексации массива Och.
    int* mem;          // Массив для хранения исходных чисел.
    string mark;       // Строка для хранения отдельной цифры числа.

public:
    // Конструктор класса Sort.
    Sort(int* mas, int size) {
        Och = new QueueQueue[10];  // Создание массива из 10 очередей.
        this->size = size;    // Инициализация размера массива mem.
        mem = new int[size];  // Выделение памяти под массив mem.
        max_num_dig = 0;      // Инициализация максимального количества цифр в числах массива mem.

        // Заполнение массива mem и определение max_num_dig.
        for (int i = 0; i < size; i++) {
            flag = mas[i];
            val = 0;

            // Подсчет количества цифр в числе.
            while (flag) {
                flag /= 10;
                val++;
            }

            // Определение максимального количества цифр в числах массива mem.
            if (val > max_num_dig) {
                max_num_dig = val;
            }

            mem[i] = mas[i];
        }
    }

    // Деструктор класса Sort.
    ~Sort() {
        delete[] mem;  // Освобождение памяти, занятой массивом mem.
        delete[] Och;  // Освобождение памяти, занятой массивом Och.
    }

    // Перегруженный оператор присваивания.
    Sort& operator=(Sort tmp) {
        if (size != 0) {
            delete[] mem;  // Освобождение памяти, занятой текущим массивом mem.
        }

        Och = new QueueQueue[10];  // Создание нового массива из 10 очередей.
        size = tmp.size;      // Копирование размера массива mem.
        mem = new int[tmp.size];  // Выделение памяти под новый массив mem.
        max_num_dig = tmp.max_num_dig;

        // Копирование значений из массива tmp.mem в текущий массив mem.
        for (int i = 0; i < size; i++) {
            mem[i] = tmp.mem[i];
        }

        return *this;
    }

    // Шаг 1 алгоритма сортировки.
    void FirstStep(int k) {
        if (k < max_num_dig) {
            for (int i = 0; i < size; i++) {
                flag = mem[i];
                val = 0;

                // Подсчет количества цифр в числе.
                while (flag) {
                    flag /= 10;
                    val++;
                }

                if (val <= k) {
                    Och[0].add_element_v_konets(mem[i]);  // Добавление числа в нулевую очередь.
                }
                else {
                    // Получение k-той цифры числа и добавление числа в соответствующую очередь.
                    mark = to_string(mem[i])[val - k - 1];
                    flag = stoi(mark);
                    Och[flag].add_element_v_konets(mem[i]);
                }
            }
        }
    }

    // Шаг 2 алгоритма сортировки.
    void SecondStep() {
        flag = 0;

        // Обход всех очередей и извлечение чисел.
        for (int i = 0; i < 10; i++) {
            while (!Och[i].pusto()) {
                mem[flag++] = Och[i].del_element_iz_nachala();  // Извлечение числа из очереди и добавление в массив mem.
            }
        }
    }

    // Выполнение всех шагов алгоритма сортировки.
    void allStep() {
        for (int i = 0; i < max_num_dig; i++) {
            FirstStep(i);
            SecondStep();
        }
    }

    // Возвращает указатель на массив mem.
    int* GetMem() {
        return mem;
    }

    // Возвращает k-тую очередь.
    QueueQueue GetOchered(int k) {
        return Och[k];
    }
};
