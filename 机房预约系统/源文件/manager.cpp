#include "manager.h"

//构造函数
Manager::Manager()
{
    
}
//有参构造函数
Manager::Manager(string name,string psw)
{
    this->m_Name = name;
    this->m_Psw = psw;
    
    this->initVector();
    
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    
    ComputerRoom c;
    while(ifs >> c.m_Comid && ifs >> c.m_Size)
    {
        v_com.push_back(c);
    }
    cout << "当前机房数量为： " << v_com.size() << endl;
    
    ifs.close();
}

//显示管理员操作的菜单界面
void Manager::openMenu()
{
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
        cout << "\t\t ---------------------------------\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          1.添加账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          2.查看账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          3.查看机房            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          4.清空预约            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          0.注销登录            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t ---------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addPerson()
{
    //错误提示
    string errortip;
    cout << "请选择你要添加的账号类型" << endl;
    cout << "1、学生:" << endl;
    cout << "2、老师:" << endl;
    
    int select = 0;
    cin >> select;
    string fileName;
    string tip;
    
    if(select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号";
        errortip = "学号输入重复，请重新输入" ;
    }
    else if(select == 2)
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工号";
        errortip = "职工号输入重复，请重新输入" ;
    }
    
    string fname;
    int fid;
    string fpwd;
    
    cout << tip << endl;
    while(true)
    {
        cin >> fid;
        bool ret = cheekRepeat(fid,select);
        if(ret == true)
        {
            cout << errortip << endl;
        }
        else
        {
            break;
        }
    }
    cout << "请输入姓名：" << endl;
    cin >> fname;
    cout << "请输入密码：" << endl;
    cin >> fpwd;
    
    ofstream ofs;
    ofs.open(fileName, ios::out | ios::app);
    ofs << fid << " " << fname << " " << fpwd << endl;
    cout << "已添加成功" << endl;
    ofs.close();
    this->initVector();
    
    cout << "请按任意键继续..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
}

//初始化容器
void Manager::initVector()
{
    //读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //清空容器
    v_stu.clear();
    v_tea.clear();
    //把文件中的内容搬到容器中
    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Psw)
    {
        v_stu.push_back(s);
    }
    cout << "当前学生数量为： " << v_stu.size() << endl;
    //关闭文件
    ifs.close();
    
    //读取老师文件中信息
    ifs.open(TEACHER_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    
    //把文件中的内容搬到容器中
    Teacher t;
    while(ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Psw)
    {
        v_tea.push_back(t);
    }
    cout << "当前教师数量为： " << v_tea.size() << endl;
    //关闭文件
    ifs.close();
}

//检查ID是否重复
bool Manager::cheekRepeat(int id,int type)
{
    //有相同，返回true
    if(type == 1)
    {
        for(vector<Student>::iterator it = v_stu.begin();it != v_stu.end();it++)
        {
            if(id == it->m_Id) return true;
        }
    }
    else if(type == 2)
    {
        for(vector<Teacher>::iterator it = v_tea.begin();it != v_tea.end();it++)
        {
            if(id == it->m_empId) return true;
        }
    }
    
    return false;
}
void printStudent(Student &s)
{
    cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Psw << endl;
}
void printTeacher(Teacher &t)
{
    cout << "职工号： " << t.m_empId << " 姓名： " << t.m_Name<< " 密码：" << t.m_Psw << endl;
}
//查看账号
void Manager::showPerson()
{
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;
    
    int select;
    cin >> select;
    
    if(select == 1)
    {
        cout << "所有学生信息如下" << endl;
        for_each(v_stu.begin(),v_stu.end(),printStudent);
    }
    else if (select == 2)
    {
        cout << "所有老师信息如下" << endl;
        for_each(v_tea.begin(),v_tea.end(),printTeacher);
    }
    
    cout << "请按任意键继续... " << endl;
    cin.ignore();
    cin.get();
}

//查看机房信息
void Manager::showComputer()
{
    cout << "机房信息如下： " << endl;
    for(vector<ComputerRoom>::iterator it = v_com.begin();it != v_com.end();it++)
    {
        cout << "机房的数量为：" << it->m_Comid<<" 机房的最大容量为：" << it->m_Size << endl;
    }
    
    cout << "请按任意键继续... " << endl;
    cin.get();
    cin.ignore();
    system("clear");
}
//清空预约记录
void Manager::cleanFile()
{
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::trunc);
    ofs.close();
    
    cout << "清空成功！" << endl;
    
    cout << "请按任意键继续... " << endl;
    cin.get();
    cin.ignore();
    system("clear");
}

