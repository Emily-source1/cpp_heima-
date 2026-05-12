#include "teacher.h"

//构造函数
Teacher::Teacher()
{}

//有参的构造函数 职工编号，姓名,密码
Teacher::Teacher(int empId,string name,string psw)
{
    //初始化属性
    this->m_empId = empId;
    this->m_Name = name;
    this->m_Psw = psw;
    
}
//显示教师操作的菜单界面
void Teacher::openMenu()
{
    cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
        cout << "\t\t ----------------------------------\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          1.查看所有预约          |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          2.审核预约              |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          0.注销登录              |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t ----------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
//查看所有预约
void Teacher::showAllMenu()
{
    OrderFile of;
    if(of.m_size == 0)
    {
        cout << "无预约记录" << endl;
        cout << "请按任意键继续..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
        return;
    }
    for(int i = 0; i < of.m_size;i++)
    {
        
        cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
        cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" :"下午") << " ";
        cout << " 机房：" << of.m_orderData[i]["roomId"] << " ";
        cout << " 学号：" << of.m_orderData[i]["stuId"] << " ";
        cout << " 姓名：" << of.m_orderData[i]["stuName"] << " ";
        string status = "状态:";
        if(of.m_orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (of.m_orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (of.m_orderData[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        else
        {
            status += "预约已取消";
        }
        cout << status << endl;
    }
    
    cout << "请按任意键继续..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
}
//审核预约
void Teacher::validOrder()
{
    OrderFile of;
    if(of.m_size == 0)
    {
        cout << "无预约记录" << endl;
        cout << "请按任意键继续..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
        return;
    }
    
    cout << "待审核预约如下：" << endl;
    
    int index = 1;
    vector<int> v;
    for(int i = 0; i < of.m_size;i++)
    {
        if(of.m_orderData[i]["status"] == "1" )
        {
            v.push_back(i);
            cout << index ++ << "、";
            cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
            cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" :"下午") << " ";
            string status = "状态:";
            if(of.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            cout << status << endl;
        }
    }
    
    cout << "请输入审核的预约记录,0代表返回" << endl;
    int select = 0;
    int ret = 0;
    while(true)
    {
        cin >> select;
        if(select >= 0 || select <= v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                cout << "请输入审核结果" << endl;
                cout << "1、通过" << endl;
                cout << "2、不通过" << endl;
                cin >> ret;
                    if(ret == 1)
                    {
                        of.m_orderData[select - 1]["status"] = "2";
                    }
                    else
                    {
                        of.m_orderData[select - 1]["status"] = "-1";
                    }
                of.updateData();
                cout << "审核完毕！" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请按任意键继续..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
}

