#include <iostream>
#include <iomanip>

using namespace std;

#include "ethernet_protocole.h"
#include "file_reader.h"
#include "constants.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �8. GIT\n";
    cout << "������� N5. �������� ������������� ���� ��������\n";
    cout << "�����: ���� ��������\n\n";
    ethernet_protocole* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** �������� ������������� ���� �������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ������ **********/
            cout << "���������: ";
            cout << subscriptions[i]->path;
            cout << '\n';
            cout << "����� �������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->start.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.second;
            cout << '\n';
            cout << "����� ����������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->end.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->end.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->end.second;
            cout << '\n';
            cout << "�������� (������ ��): ";
            cout << subscriptions[i]->received.number << "�\n";
            cout << "���������� (������ ��): ";
            cout << subscriptions[i]->dispatched.number << "�\n\n";
        }
        cout << "����� ��������� ������������� ���� �������� ���������� Skype\n";
        for (int i = 0; i < size; i++)
        {
            string s = subscriptions[i]->path;
            if (s.find("skype") != std::string::npos) {
                cout << "���������: ";
                cout << subscriptions[i]->path;
                cout << '\n';
                cout << "����� �������: ";
                cout << setw(2) << setfill('0') << subscriptions[i]->start.hour << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->start.minute << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->start.second;
                cout << '\n';
                cout << "����� ����������: ";
                cout << setw(2) << setfill('0') << subscriptions[i]->end.hour << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->end.minute << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->end.second;
                cout << '\n';
                cout << "�������� (������ ��): ";
                cout << subscriptions[i]->received.number << "�\n";
                cout << "���������� (������ ��): ";
                cout << subscriptions[i]->dispatched.number << "�\n\n";
            }
        }
        cout << "����� ��������� ������������� ���� �������� ����� 8:00\n";
        for (int i = 0; i < size; i++)
        {
            if (subscriptions[i]->start.hour >= 8) {
                cout << "���������: ";
                cout << subscriptions[i]->path;
                cout << '\n';
                cout << "����� �������: ";
                cout << setw(2) << setfill('0') << subscriptions[i]->start.hour << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->start.minute << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->start.second;
                cout << '\n';
                cout << "����� ����������: ";
                cout << setw(2) << setfill('0') << subscriptions[i]->end.hour << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->end.minute << ':';
                cout << setw(2) << setfill('0') << subscriptions[i]->end.second;
                cout << '\n';
                cout << "�������� (������ ��): ";
                cout << subscriptions[i]->received.number << "�\n";
                cout << "���������� (������ ��): ";
                cout << subscriptions[i]->dispatched.number << "�\n\n";
            }
        }
        cout << "************************* TEST ��������� ********************************\n";
        for (int i = 1; i < size; i++) {
            int sessiontime1 = (subscriptions[i]->end.hour - subscriptions[i]->start.hour) * 3600 + (subscriptions[i]->end.minute - subscriptions[i]->start.minute) * 60 + (subscriptions[i]->end.second - subscriptions[i]->start.second);
            ethernet_protocole* key = subscriptions[i];
            int j = i - 1;
            for (j; j >= 0; j--) {
                int sessiontime2 = (subscriptions[j]->end.hour - subscriptions[j]->start.hour) * 3600 + (subscriptions[j]->end.minute - subscriptions[j]->start.minute) * 60 + (subscriptions[j]->end.second - subscriptions[j]->start.second);
                if (sessiontime2 > sessiontime1) {
                    subscriptions[j + 1] = subscriptions[j];
                    subscriptions[j] = key;
                }
            }

        }
        for (int i = 0; i < size; i++)
        {
            /********** ����� ������ **********/
            cout << "���������: ";
            cout << subscriptions[i]->path;
            cout << '\n';
            cout << "����� �������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->start.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.second;
            cout << '\n';
            cout << "����� ����������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->end.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->end.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->end.second;
            cout << '\n';
            cout << "�������� (������ ��): ";
            cout << subscriptions[i]->received.number << "�\n";
            cout << "���������� (������ ��): ";
            cout << subscriptions[i]->dispatched.number << "�\n\n";
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}