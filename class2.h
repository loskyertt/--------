#pragma once
#include <iostream>

using namespace std;

#include "info.h"

class Class_2 : public Info
{
public:
    // ���캯��
    Class_2(string id, int clnum, string name, double score);
};