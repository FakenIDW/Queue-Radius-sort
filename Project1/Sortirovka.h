#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

//���������� ��������� ����������� ���������� ��� ������� �����
//����� Sort ���������� ������� ������ Queue ��� ����������� �������� ����� �� ������ ���� ����������

class Sort {
private:
    QueueQueue* Och;        // ��������� �� ������ ��������.
    int size,          // ������ ������� mem.
        max_num_dig,   // ������������ ���������� ���� � ������ ������� mem.
        val,           // ��������������� ���������� ��� �������� ���������� ���� � �����.
        flag;          // ��������������� ���������� ��� �������� �������� ����� � ���������� ������� Och.
    int* mem;          // ������ ��� �������� �������� �����.
    string mark;       // ������ ��� �������� ��������� ����� �����.

public:
    // ����������� ������ Sort.
    Sort(int* mas, int size) {
        Och = new QueueQueue[10];  // �������� ������� �� 10 ��������.
        this->size = size;    // ������������� ������� ������� mem.
        mem = new int[size];  // ��������� ������ ��� ������ mem.
        max_num_dig = 0;      // ������������� ������������� ���������� ���� � ������ ������� mem.

        // ���������� ������� mem � ����������� max_num_dig.
        for (int i = 0; i < size; i++) {
            flag = mas[i];
            val = 0;

            // ������� ���������� ���� � �����.
            while (flag) {
                flag /= 10;
                val++;
            }

            // ����������� ������������� ���������� ���� � ������ ������� mem.
            if (val > max_num_dig) {
                max_num_dig = val;
            }

            mem[i] = mas[i];
        }
    }

    // ���������� ������ Sort.
    ~Sort() {
        delete[] mem;  // ������������ ������, ������� �������� mem.
        delete[] Och;  // ������������ ������, ������� �������� Och.
    }

    // ������������� �������� ������������.
    Sort& operator=(Sort tmp) {
        if (size != 0) {
            delete[] mem;  // ������������ ������, ������� ������� �������� mem.
        }

        Och = new QueueQueue[10];  // �������� ������ ������� �� 10 ��������.
        size = tmp.size;      // ����������� ������� ������� mem.
        mem = new int[tmp.size];  // ��������� ������ ��� ����� ������ mem.
        max_num_dig = tmp.max_num_dig;

        // ����������� �������� �� ������� tmp.mem � ������� ������ mem.
        for (int i = 0; i < size; i++) {
            mem[i] = tmp.mem[i];
        }

        return *this;
    }

    // ��� 1 ��������� ����������.
    void FirstStep(int k) {
        if (k < max_num_dig) {
            for (int i = 0; i < size; i++) {
                flag = mem[i];
                val = 0;

                // ������� ���������� ���� � �����.
                while (flag) {
                    flag /= 10;
                    val++;
                }

                if (val <= k) {
                    Och[0].add_element_v_konets(mem[i]);  // ���������� ����� � ������� �������.
                }
                else {
                    // ��������� k-��� ����� ����� � ���������� ����� � ��������������� �������.
                    mark = to_string(mem[i])[val - k - 1];
                    flag = stoi(mark);
                    Och[flag].add_element_v_konets(mem[i]);
                }
            }
        }
    }

    // ��� 2 ��������� ����������.
    void SecondStep() {
        flag = 0;

        // ����� ���� �������� � ���������� �����.
        for (int i = 0; i < 10; i++) {
            while (!Och[i].pusto()) {
                mem[flag++] = Och[i].del_element_iz_nachala();  // ���������� ����� �� ������� � ���������� � ������ mem.
            }
        }
    }

    // ���������� ���� ����� ��������� ����������.
    void allStep() {
        for (int i = 0; i < max_num_dig; i++) {
            FirstStep(i);
            SecondStep();
        }
    }

    // ���������� ��������� �� ������ mem.
    int* GetMem() {
        return mem;
    }

    // ���������� k-��� �������.
    QueueQueue GetOchered(int k) {
        return Och[k];
    }
};
