#include "student.h"
#include "info.h"
#include "class1.h"
#include "class2.h"

Student::Student()
{
    this->m_StuArray = NULL;

    // �ļ����ڣ����Ҽ�¼����
    int num = this->get_StuNum();
    cout << "ѧ��λ����" << num << endl;

    this->m_StuArray = new Info *[num];

    init_Stu();
}

void Student::show_Info()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ѧ���ɼ�����ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.��ѯѧ���ɼ�  *************" << endl;
    cout << "*************  2.ͳ��ƽ����    *************" << endl;
    cout << "*************  3.ͳ��������    *************" << endl;
    cout << "*************  4.ͳ�Ƽ�����  *************" << endl;
    cout << "*************  5.ͳ�Ʋ�������  *************" << endl;
    cout << "*************  6.�����ɼ���  *************" << endl;
    cout << "*************  7.���Ƽ��׳ɼ��ֲ�ֱ��ͼ  *************" << endl;
    cout << "*************  ��������������ˢ�½���  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void Student::exit_System()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

int Student::get_StuNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    string id;
    int clnum;
    string name;
    double score;

    int num = 0;
    string firstLine; // ������һ��
    getline(ifs, firstLine);

    while (ifs >> id >> clnum >> name >> score)
    {
        // ��¼����
        num++;
    }

    ifs.close();

    return num;
}

void Student::init_Stu()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    string id;
    int clnum;
    string name;
    double score;

    string firstLine; // ������һ��
    getline(ifs, firstLine);

    int index = 0;
    while (ifs >> id >> clnum >> name >> score)
    {
        Info *info = NULL;

        // ���ݲ�ͬ�İ༶������ͬ����
        if (clnum == 1) // 1��
        {
            info = new Class_1(id, clnum, name, score);
        }
        else // 2��
        {
            info = new Class_2(id, clnum, name, score);
        }

        this->m_StuArray[index] = info;
        index++;
    }

    // �ر��ļ�
    ifs.close();
}

void Student::search_Stu()
{
    while (true)
    {
        string id_name;
        int test = 0;
        cout << "������Ҫ��ѯѧ������ȷѧ�Ż�����(����q�˳�)��" << endl;
        cin >> id_name;

        for (int i = 0; i < get_StuNum(); i++)
        {
            if (id_name == this->m_StuArray[i]->m_Id || id_name == this->m_StuArray[i]->m_Name)
            {
                cout << "ѧ�ţ�" << this->m_StuArray[i]->m_Id
                     << "\t�༶��" << this->m_StuArray[i]->m_ClassNum
                     << "\t������" << this->m_StuArray[i]->m_Name
                     << "\t�ɼ���" << this->m_StuArray[i]->m_Score
                     << endl;
                cout << endl;
                test++;
            }
        }

        if (test || id_name == "q")
        {
            break;
        }
    }
}

double Student::search_Avg(int n)
{

    int cl = 0;
    double avg = 0.0;
    double sum = 0.0;

    if (n == 1)
    {
        for (int i = 0; i < get_StuNum(); i++)
        {
            if (this->m_StuArray[i]->m_ClassNum == 1)
            {
                sum += this->m_StuArray[i]->m_Score;
                cl++;
            }
        }
    }
    else
    {
        for (int i = 0; i < get_StuNum(); i++)
        {
            if (this->m_StuArray[i]->m_ClassNum == 2)
            {
                sum += this->m_StuArray[i]->m_Score;
                cl++;
            }
        }
    }
    avg = sum / cl;

    return avg;
}

double Student::search_Excellent(int n)
{
    double sum_1 = 0; // ͳ��1��������
    double sum_2 = 0; // ͳ��2��������
    double num_1 = 0; // ͳ��1������ѧ������
    double num_2 = 0; // ͳ��2������ѧ������

    for (int i = 0; i < get_StuNum(); i++)
    {
        if (this->m_StuArray[i]->m_ClassNum == 1)
        {
            sum_1++;
            if (this->m_StuArray[i]->m_Score >= 85)
            {
                num_1++;
            }
        }

        if (this->m_StuArray[i]->m_ClassNum == 2)
        {
            sum_2++;
            if (this->m_StuArray[i]->m_Score >= 85)
            {
                num_2++;
            }
        }
    }

    if (n == 1)
    {
        return num_1 / sum_1 * 100;
    }
    else
    {
        return num_2 / sum_2 * 100;
    }
}

double Student::search_Pass(int n)
{
    double sum_1 = 0; // ͳ��1��������
    double sum_2 = 0; // ͳ��2��������
    double num_1 = 0; // ͳ��1�༰��ѧ������
    double num_2 = 0; // ͳ��2�༰��ѧ������

    for (int i = 0; i < get_StuNum(); i++)
    {
        if (this->m_StuArray[i]->m_ClassNum == 1)
        {
            sum_1++;
            if (this->m_StuArray[i]->m_Score >= 60)
            {
                num_1++;
            }
        }

        if (this->m_StuArray[i]->m_ClassNum == 2)
        {
            sum_2++;
            if (this->m_StuArray[i]->m_Score >= 60)
            {
                num_2++;
            }
        }
    }

    if (n == 1)
    {
        return num_1 / sum_1 * 100;
    }
    else
    {
        return num_2 / sum_2 * 100;
    }
}

double Student::search_Fail(int n)
{
    double sum_1 = 0; // ͳ��1��������
    double sum_2 = 0; // ͳ��2��������
    double num_1 = 0; // ͳ��1�಻����ѧ������
    double num_2 = 0; // ͳ��2�಻����ѧ������

    for (int i = 0; i < get_StuNum(); i++)
    {
        if (this->m_StuArray[i]->m_ClassNum == 1)
        {
            sum_1++;
            if (this->m_StuArray[i]->m_Score < 60)
            {
                num_1++;
            }
        }

        if (this->m_StuArray[i]->m_ClassNum == 2)
        {
            sum_2++;
            if (this->m_StuArray[i]->m_Score < 60)
            {
                num_2++;
            }
        }
    }

    if (n == 1)
    {
        return num_1 / sum_1 * 100;
    }
    else
    {
        return num_2 / sum_2 * 100;
    }
}

void Student::save()
{
    ofstream ofs;
    ofs.open(FILENAME2, ios::out);

    ofs << "ѧ��"
        << "\t�༶"
        << "\t����"
        << "\t�ɼ�"
        << "\t�ȼ�" << endl;

    for (int i = 0; i < get_StuNum(); i++)
    {
        ofs << this->m_StuArray[i]->m_Id << " \t"
            << this->m_StuArray[i]->m_ClassNum << " \t"
            << this->m_StuArray[i]->m_Name << " \t"
            << this->m_StuArray[i]->m_Score << " \t";

        if (this->m_StuArray[i]->m_Score >= 90)
        {
            ofs << "A" << endl;
        }

        else if (this->m_StuArray[i]->m_Score >= 80)
        {
            ofs << "B" << endl;
        }

        else if (this->m_StuArray[i]->m_Score >= 70)
        {
            ofs << "C" << endl;
        }

        else if (this->m_StuArray[i]->m_Score >= 60)
        {
            ofs << "D" << endl;
        }

        else
        {
            ofs << "E" << endl;
        }
    }
    ofs << endl;
    ofs << "------------------------------------------------" << endl;
    ofs << "1��ƽ���֣�" << this->search_Avg(1) << endl;
    ofs << "1�������ʣ�" << this->search_Excellent(1) << "%" << endl;
    ofs << "1�༰���ʣ�" << this->search_Pass(1) << "%" << endl;
    ofs << "1�಻�����ʣ�" << this->search_Fail(1) << "%" << endl;
    ofs << "------------------------------------------------" << endl;
    ofs << "2��ƽ���֣�" << this->search_Avg(2) << endl;
    ofs << "2�������ʣ�" << this->search_Excellent(2) << "%" << endl;
    ofs << "2�༰���ʣ�" << this->search_Pass(2) << "%" << endl;
    ofs << "2�಻�����ʣ�" << this->search_Fail(2) << "%" << endl;

    ofs.close();
}

void Student::print_Histogram()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    for (int i = 0; i < this->get_StuNum(); i++)
    {
        switch (int(this->m_StuArray[i]->m_Score / 10))
        {
        case 2:
            a++;
            break;

        case 3:
            b++;
            break;
        case 4:
            c++;
            break;

        case 5:
            d++;
            break;

        case 6:
            e++;
            break;

        case 7:
            f++;
            break;

        case 8:
            g++;
            break;

        case 9:
            h++;
            break;

        default:
            break;
        }
    }

    cout << "\n20-30��";
    for (int i = 0; i < a; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "30-40��";
    for (int i = 0; i < b; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "40-50��";
    for (int i = 0; i < c; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "50-60��";
    for (int i = 0; i < d; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "60-70��";
    for (int i = 0; i < e; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "70-80��";
    for (int i = 0; i < f; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "80-90��";
    for (int i = 0; i < g; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "90-100��";
    for (int i = 0; i < h; i++)
    {
        cout << "*";
    }
    cout << "\n"
         << endl;
}

Student::~Student()
{
    if (this->m_StuArray != NULL)
    {
        delete[] this->m_StuArray;
    }
}