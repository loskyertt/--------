#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "student.h"
#include "info.h"
#include "class1.h"
#include "class2.h"

int main()
{
    Student st;
    int choice;

    while (true)
    {
        st.show_Info();
        cout << "����������ѡ��:" << endl;
        cin >> choice;
        int n = 0; // �༶

        switch (choice)
        {
        case 0: // �˳��������
            st.exit_System();
            break;

        case 1: // ��ѯѧ���ɼ�
            st.search_Stu();
            break;

        case 2: // ͳ��ƽ����
            while (true)
            {
                cout << "������Ҫ��ѯ�༶��1��2����" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // �������״̬
                cin.ignore(INT_MAX, '\n'); // ��ջ�����
            }
            cout << n << "��ƽ���ɼ��ǣ�" << st.search_Avg(n) << endl;
            break;

        case 3: // ͳ��������
            while (true)
            {
                cout << "������Ҫ��ѯ�༶��1��2����" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // �������״̬
                cin.ignore(INT_MAX, '\n'); // ��ջ�����
            }
            cout << n << "���������ǣ�" << st.search_Excellent(n) << "%" << endl;
            break;

        case 4: // ͳ�Ƽ�����
            while (true)
            {
                cout << "������Ҫ��ѯ�༶��1��2����" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // �������״̬
                cin.ignore(INT_MAX, '\n'); // ��ջ�����
            }
            cout << n << "�༰�����ǣ�" << st.search_Pass(n) << "%" << endl;
            break;

        case 5: // ͳ�Ʋ�������
            while (true)
            {
                cout << "������Ҫ��ѯ�༶��1��2����" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // �������״̬
                cin.ignore(INT_MAX, '\n'); // ��ջ�����
            }
            cout << n << "�಻�������ǣ�" << st.search_Fail(n) << "%" << endl;
            break;

        case 6: // �����ɼ���
            st.save();
            break;

        case 7: // ����ֱ��ͼ
            st.print_Histogram();
            break;

        default:
            system("cls");
            break;
        }
    }

    system("pause");

    return 0;
}