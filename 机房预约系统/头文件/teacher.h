#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

class Teacher:public Identity
{
public:
    //构造函数
    Teacher();
    //有参的构造函数 职工编号，姓名,密码
    Teacher(int empId,string name,string psw);
    //显示教师操作的菜单界面
    virtual void openMenu();
    //查看所有预约
    void showAllMenu();
    //审核预约
    void validOrder();
    
    int m_empId;
};
