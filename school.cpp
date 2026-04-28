#include <iostream>
#include <string>

class Date
{
private:
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void print() const { std::cout << year << "." << month << "." << day; }
};

class Phone
{
private:
    char type;
    std::string number;
    int state;
    bool isStopped; // 用一个布尔值来标记是否停机
    Date stopDate;  // 直接包含一个Date对象，而不是指针

    std::string getTypeStr() const
    {
        switch (type)
        {
        case 'A':
            return "机构";
        case 'B':
            return "企业";
        case 'C':
            return "个人";
        case 'D':
            return "备份";
        default:
            return "";
        }
    }
    std::string getStateStr() const
    {
        switch (state)
        {
        case 1:
            return "在用";
        case 2:
            return "未用";
        case 3:
            return "停用";
        default:
            return "";
        }
    }

public:
    Phone(char t, std::string n, int s, int y, int m, int d)
        : type(t), number(n), state(s), isStopped(s == 3), stopDate(y, m, d)
    {
        std::cout << "Construct a new phone " << number << std::endl;
    }

    Phone(const Phone &other)
        : type('D'), number(other.number + "X"), state(other.state),
          isStopped(other.isStopped), stopDate(other.stopDate)
    { // 直接拷贝Date对象
        std::cout << "Construct a copy of phone " << other.number << std::endl;
    }

    void stop(int y, int m, int d)
    {
        state = 3;
        isStopped = true;
        stopDate = Date(y, m, d); // 直接赋值一个新的Date对象
        std::cout << "Stop the phone " << number << std::endl;
    }

    void print() const
    {
        std::cout << "类型=" << getTypeStr()
                  << "||号码=" << number
                  << "||State=" << getStateStr();
        if (isStopped)
        {
            std::cout << "||停机日期=";
            stopDate.print();
        }
        std::cout << std::endl;
    }
};

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        char type;
        std::string num;
        int state, y, m, d;
        std::cin >> type >> num >> state >> y >> m >> d;
        Phone p1(type, num, state, y, m, d);
        p1.print();
        Phone p2(p1);
        p2.print();
        p1.stop(y, m, d);
        p1.print();
        std::cout << "----" << std::endl;
    }
    return 0;
}