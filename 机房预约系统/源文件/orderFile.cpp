#include "orderFile.h"

//构造函数
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);
    
    string date;      //日期
    string interval;  //时间段
    string stuId;     //学生编号
    string stuName;   //学生姓名
    string roomId;    //机房编号
    string status;    //预约状态
    this->m_size = 0;
    while(ifs >> date &&ifs >> interval &&ifs >> stuId &&
          ifs >> stuName &&ifs >> roomId &&ifs >> status)
    {
        //测试代码
//        cout << date << endl;
//        cout << interval << endl;
//        cout << stuId << endl;
//        cout << stuName << endl;
//        cout << roomId << endl;
//        cout << status << endl;
       
        //date:111
        string key;
        string value;
        map<string,string> m;
        
        int pos = (int)date.find(":");//pos == 4
        if(pos != -1)
        {
            key = date.substr(0,pos);
            value = date.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        
        pos = (int)interval.find(":");//pos == 4
        if(pos != -1)
        {
            key = interval.substr(0,pos);
            value = interval.substr(pos+1,interval.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = (int)stuId.find(":");//pos == 4
        if(pos != -1)
        {
            key = stuId.substr(0,pos);
            value = stuId.substr(pos+1,stuId.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = (int)stuName.find(":");//pos == 4
        if(pos != -1)
        {
            key =stuName.substr(0,pos);
            value = stuName.substr(pos+1,stuName.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = (int)roomId.find(":");//pos == 4
        if(pos != -1)
        {
            key = roomId.substr(0,pos);
            value = roomId.substr(pos+1,roomId.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = (int)status.find(":");//pos == 4
        if(pos != -1)
        {
            key =status.substr(0,pos);
            value = status.substr(pos+1,status.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        this->m_orderData.insert(make_pair(this->m_size, m));
        this->m_size++;
    }
    ifs.close();
}

//更新预约信息
void OrderFile::updateData()
{
    if(this->m_size == 0)
    {
        return;
    }
    
    ofstream ofs(ORDER_FILE,ios::out | ios::trunc);
    
    for(int i = 0; i < this->m_size;i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    
    ofs.close(); 
}
