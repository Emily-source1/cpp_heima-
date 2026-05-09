#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalFile.h"
#include "fstream"
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager:public Identity
{
public:
    //构造函数
    Manager();
    //有参构造函数
    Manager(string name,string psw);
    //显示管理员操作的菜单界面
    virtual void openMenu();
    //添加账号
    void addPerson();
    //查看账号
    void showPerson();
    //查看机房信息
    void showComputer();
    //清空预约记录
    void cleanFile();
    
    //初始化容器
    void initVector();
    
    vector<Student> v_stu;
    vector<Teacher> v_tea;
    
    //检查ID是否重复
    bool cheekRepeat(int id,int type);
    
    vector<ComputerRoom> v_com;
};
