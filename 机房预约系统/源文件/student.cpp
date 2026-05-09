#include "student.h"


//默认构造
Student::Student()
{
    
}

//有参构造（姓名、学号、密码）
Student::Student(int id,string name,string psd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Psw = psd;
    
    //初始化
    ComputerRoom c;
    ifstream ifs(COMPUTER_FILE,ios::in);
    
    while(ifs >> c.m_Comid && ifs >> c.m_Size)
    {
        v_com.push_back(c);
    }
    cout << "当前机房数量为： " << v_com.size() << endl;
}

//学生操作的菜单界面
void Student::openMenu()
{
    cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
        cout << "\t\t ----------------------------------\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          1.申请预约              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          2.查看我的预约          |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          3.查看所有预约          |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          4.取消预约              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          0.注销登录              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t ----------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
//申请预约
void Student::applyOder()
{
    
}
//查看自身预约
void Student::showMyOder()
{
    
}
//查看所有预约
void Student::shouAllOder()
{
    
}
//取消预约
void Student::cancelOder()
{
    
}



