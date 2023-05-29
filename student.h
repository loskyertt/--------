#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "info.h"

#define FILENAME "�ɼ���-����1.txt" // ���ļ�
#define FILENAME2 "���º��.txt" // д�ļ�

class Student
{
public:
    // ���캯��
    Student();

    // ������Ϣ
    void show_Info();

    // �˳�����ϵͳ
    void exit_System();

    // ͳ��������
    int get_StuNum();

    // ��ʼ��ѧ��
    void init_Stu();

    // ��ѯѧ���ɼ�
    void search_Stu();

    // ��ѯƽ���ɼ�
    double search_Avg(int n);

    // ��ѯ�����ʣ�85�����ϱ�����
    double search_Excellent(int n);

    // ��ѯ�����ʣ�60�����ϱ�����
    double search_Pass(int n);

    // ��ѯ�������ʣ�60�����±�����
    double search_Fail(int n);

    // �����ļ�
    void save();

    // ��ӡֱ��ͼ
    void print_Histogram();

    // �������� �ͷŶ�������
    ~Student();

    // ѧ����Ϣ����
    Info **m_StuArray;
};