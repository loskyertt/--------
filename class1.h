#pragma once
#include <iostream>

using namespace std;

#include "info.h"

class Class_1 : public Info
{
public:
    // ���캯��
    Class_1(string id, int clnum, string name, double score);
};