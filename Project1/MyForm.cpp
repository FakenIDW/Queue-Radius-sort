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


// ������ ��� �������
#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
    setlocale(LC_ALL, "Rus");
    QueueQueue Ochered1; // ������ �������

    // ���������, ������ �� ������� ������ 
    // ������ ��� �����, ��� ��� �� ������ �� ���������
    if (Ochered1.pusto()) {
        cout << "������� �����" << endl;
    }
    else {
        cout << "������� �� �����" << endl;
    }

    // ��������� ������� � ����� �������
    int number;
    cout << "������� �����, ������� �� ������ �������� � �������: ";
    cin >> number;
    Ochered1.add_element_v_konets(number);

    // ���������, ������ �� ������� ������ 
    // ������ ��� �� �����, ��� ��� �� �������� ����� number
    if (Ochered1.pusto()){
        cout << "������� �����" << endl;
    }
    else{
        cout << "������� �� �����" << endl;
    }
    cout << endl;

    // ������ ���� �����, ������� �� ����� �� �������
    cout << "������ ������� ����� �� ������ �������" << endl;
    cout << "�����, ������� �� ������� �� ������ �������: " << Ochered1.del_element_iz_nachala() << endl;
    // ������ ������� ������ ���� ������.
    if (Ochered1.pusto()){
        cout << "������� �����" << endl;
    }
    else{
        cout << "������� �� �����" << endl;
    }
    cout << endl;



    // ������ �������� � �������
    cout << "������� ���������� ��������� � �������: ";
    int size; cin >> size; cout << endl;
    cout << "������� " << size << " ��������� �������" << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << "������� " << i << "-�� ������� �������: ";
        int element;
        cin >> element;
        Ochered1.add_element_v_konets(element);
    }
    cout << endl;

    QueueQueue Ochered2(Ochered1); // ����������� �����������
    QueueQueue Ochered3 = Ochered1; // �������� ������������


    // ������� ���� �������
    cout << "�� ����� �������:" << endl;
    while (!Ochered1.pusto()) {
        cout << Ochered1.del_element_iz_nachala() << endl;
    }
    cout << endl;

    // �������� ������������ �����������
    cout << "�������� ������������ �����������:" << endl;
    while (!Ochered2.pusto()){
        cout << Ochered2.del_element_iz_nachala() << endl;
    }
    cout << endl;

    // �������� �������� ������������
    cout  << "�������� �������� ������������:" << endl;
    while (!Ochered3.pusto()){
        cout << Ochered3.del_element_iz_nachala() << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}