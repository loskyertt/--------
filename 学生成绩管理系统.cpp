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
        cout << "请输入您的选择:" << endl;
        cin >> choice;
        int n = 0; // 班级

        switch (choice)
        {
        case 0: // 退出管理程序
            st.exit_System();
            break;

        case 1: // 查询学生成绩
            st.search_Stu();
            break;

        case 2: // 统计平均分
            while (true)
            {
                cout << "请输入要查询班级（1或2）：" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // 清除错误状态
                cin.ignore(INT_MAX, '\n'); // 清空缓冲区
            }
            cout << n << "班平均成绩是：" << st.search_Avg(n) << endl;
            break;

        case 3: // 统计优秀率
            while (true)
            {
                cout << "请输入要查询班级（1或2）：" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // 清除错误状态
                cin.ignore(INT_MAX, '\n'); // 清空缓冲区
            }
            cout << n << "班优秀率是：" << st.search_Excellent(n) << "%" << endl;
            break;

        case 4: // 统计及格率
            while (true)
            {
                cout << "请输入要查询班级（1或2）：" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // 清除错误状态
                cin.ignore(INT_MAX, '\n'); // 清空缓冲区
            }
            cout << n << "班及格率是：" << st.search_Pass(n) << "%" << endl;
            break;

        case 5: // 统计不及格率
            while (true)
            {
                cout << "请输入要查询班级（1或2）：" << endl;
                cin >> n;
                if (n == 1 || n == 2)
                {
                    break;
                }
                cin.clear();               // 清除错误状态
                cin.ignore(INT_MAX, '\n'); // 清空缓冲区
            }
            cout << n << "班不及格率是：" << st.search_Fail(n) << "%" << endl;
            break;

        case 6: // 导出成绩单
            st.save();
            break;

        case 7: // 绘制直方图
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