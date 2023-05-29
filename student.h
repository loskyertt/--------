#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "info.h"

#define FILENAME "成绩单-导入1.txt" // 读文件
#define FILENAME2 "更新后的.txt" // 写文件

class Student
{
public:
    // 构造函数
    Student();

    // 操作信息
    void show_Info();

    // 退出管理系统
    void exit_System();

    // 统计总人数
    int get_StuNum();

    // 初始化学生
    void init_Stu();

    // 查询学生成绩
    void search_Stu();

    // 查询平均成绩
    double search_Avg(int n);

    // 查询优秀率（85分以上比例）
    double search_Excellent(int n);

    // 查询及格率（60分以上比例）
    double search_Pass(int n);

    // 查询不及格率（60分以下比例）
    double search_Fail(int n);

    // 保存文件
    void save();

    // 打印直方图
    void print_Histogram();

    // 析构函数 释放堆区数据
    ~Student();

    // 学生信息数组
    Info **m_StuArray;
};