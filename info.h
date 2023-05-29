#pragma once
#include <iostream>
#include <string>

using namespace std;

// 信息抽象类
class Info
{
public:
    // 显示个人信息

    string m_Id;    // 学号
    int m_ClassNum; // 班级号
    string m_Name;  // 姓名
    double m_Score; // 成绩
};