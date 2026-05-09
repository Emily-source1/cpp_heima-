#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:
    virtual void openMenu() = 0;
    //虚析构函数
    virtual ~Identity(){};
    //用户名
    string m_Name;
    //密码
    string m_Psw;
};
