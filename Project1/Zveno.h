#pragma once

//���� ����� ������������ ����� ������� ������� ������������ ������
//������������ ��� ���������� ��������� ������ �������

class Zveno {
private:
    int info;      // ����������, ���������� � ����.
    Zveno* next;   // ��������� �� ��������� ���� � ����������� ������.

public:
    // ����������� ������ Zveno.
    Zveno(int info = 0) {
        this->info = info;  // ������������� ���������� ���� ���������� ���������.
        next = nullptr;     // ������������� ��������� �� ��������� ���� ������� ���������.
    }

    // ���������� ������ Zveno.
    ~Zveno() {
        next = 0;  // ��������� ��������� �� ��������� ���� � ����.
    }

    // ����������� �����������.
    Zveno(const Zveno& tmp) {
        info = tmp.info;  // ����������� ���������� �� ������� ����.
        next = 0;         // ������������� ��������� �� ��������� ���� ������� ���������.
    }

    // ������������� �������� ������������.
    Zveno& operator=(Zveno tmp) {
        info = tmp.info;  // ������������ ���������� �� ������� ����.
        return *this;
    }

    // ����� ��� ��������� ���������� �� ����.
    int poluchim_information() {
        return info;
    }

    // ����� ��� ��������� ��������� �� ��������� ����.
    Zveno* poluchim_next_uzel() {
        return next;
    }

    // ����� ��� ��������� ������ �������� ���������� � ����.
    void ustanivim_information(int val) {
        info = val;
    }

    // ����� ��� ��������� ��������� �� ��������� ����.
    void ustanovim_next_uzel(Zveno* tmp) {
        next = tmp;
    }
};