#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <map>
#include "globalFile.h"

class OrderFile {
public:
    //构造函数
    OrderFile();
    
    //更新预约信息
    void updateData();
    
    //记录预约条数
    int m_size;
    
    map<int,map<string,string>> m_orderData;
};

