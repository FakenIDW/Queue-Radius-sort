#pragma once
#include "Zveno.h"
class QueueQueue{
private:
    Zveno* first;  // ��������� �� ������ ������� � �������
    Zveno* last;   // ��������� �� ��������� ������� � �������

public:
    QueueQueue(){
        first = 0;  // ������������� ��������� �� ������ ������� ������� ���������
        last = 0;   // ������������� ��������� �� ��������� ������� ������� ���������
    }

    ~QueueQueue(){
        delete first;  // ������������ ������, ������� ������ ���������
    }

    QueueQueue(const QueueQueue& tmp){ // ����������� �����������. ������� ����� ���������� ������� tmp

        if (tmp.first == 0){
            first = 0;
            last = 0;
        }
        else{
            Zveno* current = tmp.first;
            first = new Zveno(*current);  // �������� ������ ���� � ������ ���������� �� ������� ���� tmp
            last = first;

            // ����������� ��������� ����� �� tmp � ������� �������.
            while (current->poluchim_next_uzel() != 0){
                current = current->poluchim_next_uzel();
                Zveno* A = new Zveno(current->poluchim_information());
                last->ustanovim_next_uzel(A);
                last = A;
            }
        }
    }

    QueueQueue& operator=(QueueQueue tmp) {  // ������������� �������� ������������

        if (first != 0){
            delete first;  // ������������ ������, ������� ������� ��������
        }

        if (tmp.first == 0){
            first = 0;
            last = 0;
        }
        else{
            Zveno* current = tmp.first;
            first = new Zveno(*current);
            last = first;

            // ����������� ��������� ����� �� tmp � ������� �������
            while (current->poluchim_next_uzel() != 0) {
                current = current->poluchim_next_uzel();
                Zveno* A = new Zveno(current->poluchim_information());
                last->ustanovim_next_uzel(A);
                last = A;
            }
        }

        return *this;
    }

    void add_element_v_konets(int tmp){  // ���������� ������ �������� � ����� �������
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

    int del_element_iz_nachala(){       // �������� � ����������� �������� �� ������ �������
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

        return -1;  // ����������� -1 � ������ ������� ���������� �� ������ �������
    }

    int pusto(){ // ��������, �������� �� ������� ������

        if (first == 0){
            return 1;  // ����������� 1, ���� ������� �����
        }
        return 0;  // ����������� 0, ���� ������� �� �����
    }
};
