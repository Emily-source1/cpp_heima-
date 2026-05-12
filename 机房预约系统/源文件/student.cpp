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
    cout << "机房开放时间为周一至周五！" << endl;
        cout << "请输入申请预约的时间：" << endl;
        cout << "1、周一" << endl;
        cout << "2、周二" << endl;
        cout << "3、周三" << endl;
        cout << "4、周四" << endl;
        cout << "5、周五" << endl;
    int date = 0;
    while (true)
        {
            cin >> date;
            if (date >= 1 && date <= 5)
            {
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
    
    cout << "请输入申请预约的时间段：" << endl;
        cout << "1、上午" << endl;
        cout << "2、下午" << endl;
    
    int interval = 0;
    while (true)
        {
            cin >> interval;
            if (interval >= 1 && interval <= 2)
            {
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
    
    cout << "请选择机房：" << endl;
        cout << "1号机房容量：" << v_com[0].m_Size<< endl;
        cout << "2号机房容量：" << v_com[1].m_Size << endl;
        cout << "3号机房容量：" << v_com[2].m_Size<< endl;

    int room = 0;
        while (true)
        {
            cin >> room;
            if (room >= 1 && room <= 3)
            {
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
    
    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE,ios::app);
        ofs << "date:" << date << " ";
        ofs << "interval:" << interval << " ";
        ofs << "stuId:" << this->m_Id << " ";
        ofs << "stuName:" << this->m_Name << " ";
        ofs << "roomId:" << room << " ";
        ofs << "status:" << 1 << endl;
    ofs.close();
    
}
//查看自身预约
void Student::showMyOder()
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
        if(atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
        {
            cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
            cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" :"下午") << " ";
            cout << " 机房：" << of.m_orderData[i]["roomId"] << " ";
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
    }
    cout << "请按任意键继续..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
}
//查看所有预约
void Student::shouAllOder()
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
//取消预约
void Student::cancelOder()
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
    
    cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
    int index = 1;
    vector<int> v;
    
    for(int i = 0; i < of.m_size;i++)
    {
        if(atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
        {
            if(of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
                else if (of.m_orderData[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }
    cout << "请输入取消的记录,0代表返回" << endl;
    int select = 0;
    cin >> select;
    
    while(true)
    {
        if(select >= 0 || select <= v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                of.m_orderData[v[select-1]]["status"] = "0";
                of.updateData();
                cout << "预约已取消" << endl;
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
    



