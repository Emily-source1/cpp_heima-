#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include "fstream"
#include "globalFile.h"

class Student: public Identity
{
public:
    //默认构造
    Student();
    //有参构造（姓名、学号、密码）
    Student(int id,string name,string psd);
    //学生操作的菜单界面
    virtual void openMenu();
    //申请预约
    void applyOder();
    //查看自身预约
    void showMyOder();
    //查看所有预约
    void shouAllOder();
    //取消预约
    void cancelOder();

    int m_Id;
    
    vector<ComputerRoom> v_com;
};
