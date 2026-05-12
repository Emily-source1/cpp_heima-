#include <iostream>
using namespace std;
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"
#include "fstream"

void teacherMenu(Identity * &teacher)
{
    while(true)
    {
        //显示学生子菜单
        teacher->openMenu();
        
        Teacher* tea = (Teacher*)teacher;
        
        int select;
        cin >> select;

        if(select == 1)
        {
            //查看所有预约
            tea->showAllMenu();
        }
        else if(select == 2)
        {
            //审核预约
            tea->validOrder(); 
        }
        else
        {
            //注销登录
            delete teacher;
            cout << "已注销登录" << endl;
            
            cout << "请按任意键继续..." << endl;
            cin.ignore();
            cin.get();
            system("clear");
            
            return;
        }
    }
}
void studentMenu(Identity * &student)
{
    while(true)
    {
        //显示学生子菜单
        student->openMenu();
        
        Student* stu = (Student*)student;
        
        int select;
        cin >> select;

        if(select == 1)
        {
            //申请预约
           stu->applyOder();
        }
        else if(select == 2)
        {
            //查看自身预约
            stu->showMyOder();
        }
        else if (select == 3)
        {
            //查看所有预约
            stu-> shouAllOder();
        }
        else if (select == 4)
        {
            //取消预约
            stu-> cancelOder();

        }
        else
        {
            //注销登录
            delete student;
            cout << "已注销登录" << endl;
            
            cout << "请按任意键继续..." << endl;
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
}
void managerMenu(Identity * &manager)
{
    while(true)
    {
        //显示管理员子菜单
        manager->openMenu();
        Manager* men = (Manager*)manager;
        int select;
        cin >> select;
    //    * 添加账号
        if(select == 1)
        {
            men->addPerson();
        }
    //    * 查看账号
        else if(select == 2)
        {
            men->showPerson();
        }
    //    * 查看机房
        else if (select == 3)
        {
            men->showComputer();
        }
    //    * 清空预约
        else if (select == 4)
        {
            men->cleanFile();
        }
    //    * 注销登录
        else
        {
            delete manager;
            cout << "已注销登录" << endl;
            cout << "请按任意键继续..." << endl;
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
    
}
void Login(string fildname,int type)
{
    Identity *person = NULL;
    //创建文件
    ifstream ifs;
    //打开文件
    ifs.open(fildname,ios::in);
    //打开文件失败
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        ifs.close();
    }
    
    int id = 0;
    string name;
    string pwd;
   //登录信息的输入
    if(type == 1)
    {
        cout << "请输入你的的学号:" << endl;
        cin >> id;
    }
    else if(type == 2)
    {
        cout << "请输入你的职工号:" << endl;
        cin >> id;
    }
    
    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;
    
    
    if(type == 1)
    {
        string fname;
        int fid;
        string fpwd;
        //学生验证
        //把文件中的学生信息拿出来，与用户输入的登录信息比较，相同->验证通过
        while(ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if(fname == name && fid == id && fpwd == pwd)
            {
                cout << "登录验证通过" << endl;
                 
                person = new Student(id,name,pwd);
               
                //进入学生菜单
                studentMenu(person);
                
                return;
            }
        }
        
    }
    else if (type == 2)
    {
        //职工验证
        string fname;
        int fid;
        string fpwd;
        while(ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if(fname == name && fid == id && fpwd == pwd)
            {
                cout << "登录验证通过" << endl;
                cout << "请按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                
                person = new Teacher(id,name,pwd);
                //进入教师子菜单
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        //管理员验证
        string fname;
        string fpwd;
        while(ifs >> fname && ifs >> fpwd)
        {
            if(fname == name && fpwd == pwd)
            {
                cout << "登录验证通过" << endl;
                cout << "请按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                
                person = new Manager(name,pwd);
                
                //调用管理员子菜单
                managerMenu(person);
                
                return;
            }
        }
    }
    
    cout << "验证失败" << endl;
    cout << "请按任意键继续... " << endl;
    cin.ignore();
    cin.get();
    system("clear");
    
    return;
}

int main(int argc, const char * argv[]) {
   
    int select;
    while(true)
    {
        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
        << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";
        
        cin >> select;
        
        switch(select)
        {
            case 1://学生身份
                Login(STUDENT_FILE, 1);
                break;
            case 2://老师身份
                Login(TEACHER_FILE, 2);
                break;
            case 3://管理员身份
                Login(ADMIN_FILE, 3);
                break;
            case 0://退出系统
                cout << "欢迎下次使用" << endl;
                cout << "请按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                return 0; 
                break;
            default:
                cout << "输入有误，请重新选择" << endl;
                cout << "请按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                break;
        }
        
    }
    
    return EXIT_SUCCESS;
}
