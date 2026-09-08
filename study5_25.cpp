#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}
    bool check()
    {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (isLeap()) daysInMonth[1] = 29;
        return day <= daysInMonth[month-1];
    }
    bool isLeap()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    void print()
    {
        cout << year << "年" << month << "月" << day << "日";
    }
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

class COldId
{
protected:
    string pId15, pName;
    CDate birthday;
public:
    COldId(string pIdVal, string pNameVal, CDate& day) : birthday(day), pId15(pIdVal), pName(pNameVal) {}
    virtual bool check()
    {
        if (pId15.length() != 15) return false;
        for (char c : pId15)
            if (!isdigit(c)) return false;
        if (!birthday.check()) return false;
        // 15位身份证年份前两位必须为合法（这里只检查年份范围，实际由扩展规则保证）
        int y = birthday.getYear();
        if (y < 1900 || y > 1999) return false;
        return true;
    }
    virtual void print()
    {
        cout << pName << endl;
        cout << pId15 << endl;
        birthday.print();
    }
    virtual ~COldId() {}
    string getId15() const { return pId15; }
    string getName() const { return pName; }
    CDate getBirthday() const { return birthday; }
};

class CNewId : public COldId
{
private:
    string pId18;
    CDate issueDay;
    int validYear;
public:
    CNewId(string pIdVal, string pNameVal, CDate& day, string pId18Val, CDate& issue, int valid)
        : COldId(pIdVal, pNameVal, day), pId18(pId18Val), issueDay(issue), validYear(valid) {}

    // 根据15位号码生成正确的18位号码（含校验码）
    string generate18From15(const string& id15)
    {
        string base = id15.substr(0, 6) + "19" + id15.substr(6, 9); // 前6+19+后9，共17位
        int sum = 0;
        int weights[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        for (int i = 0; i < 17; i++)
            sum += (base[i] - '0') * weights[i];
        int remain = sum % 11;
        char checkCode[] = {'1','0','X','9','8','7','6','5','4','3','2'};
        return base + checkCode[remain];
    }

    bool check() override
    {
        // 1. 长度正确
        if (pId18.length() != 18) return false;

        // 2. 前17位为数字，第18位为数字或X
        for (int i = 0; i < 17; i++)
            if (!isdigit(pId18[i])) return false;
        char last = pId18[17];
        if (!(isdigit(last) || last == 'X')) return false;

        // 3. 验证18位校验码
        int sum = 0;
        int weights[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        for (int i = 0; i < 17; i++)
            sum += (pId18[i] - '0') * weights[i];
        int remain = sum % 11;
        char checkCode[] = {'1','0','X','9','8','7','6','5','4','3','2'};
        if (last != checkCode[remain]) return false;

        // 4. 检查15位身份证是否合法（基类check已经检查长度、数字、出生日期等）
        if (!COldId::check()) return false;

        // 5. 确认18位是从15位扩展而来
        string correct18 = generate18From15(pId15);
        if (correct18 != pId18) return false;

        // 6. 身份证中的出生日期合法（从18位中提取并检查）
        int birthYear = (pId18[6]-'0')*1000 + (pId18[7]-'0')*100 + (pId18[8]-'0')*10 + (pId18[9]-'0');
        int birthMonth = (pId18[10]-'0')*10 + (pId18[11]-'0');
        int birthDay = (pId18[12]-'0')*10 + (pId18[13]-'0');
        CDate birthFromId(birthYear, birthMonth, birthDay);
        if (!birthFromId.check()) return false;

        // 7. 身份证中的出生日期必须与输入给的birthday一致
        if (birthYear != birthday.getYear() || birthMonth != birthday.getMonth() || birthDay != birthday.getDay())
            return false;

        // 8. 签发日期合法
        if (!issueDay.check()) return false;

        // 9. 有效期判断（当前日期2021年11月9日）
        int curYear = 2021, curMonth = 11, curDay = 9;
        CDate cur(curYear, curMonth, curDay);
        if (!cur.check()) return false;

        if (validYear == 100)  // 长期
        {
            // 签发日期不能晚于当前日期
            if (issueDay.getYear() > curYear) return false;
            if (issueDay.getYear() == curYear && issueDay.getMonth() > curMonth) return false;
            if (issueDay.getYear() == curYear && issueDay.getMonth() == curMonth && issueDay.getDay() > curDay)
                return false;
        }
        else
        {
            int expireYear = issueDay.getYear() + validYear;
            // 当前日期必须在 [签发日期, 过期日期] 区间内
            // 先检查是否小于签发日期
            if (curYear < issueDay.getYear()) return false;
            if (curYear == issueDay.getYear() && curMonth < issueDay.getMonth()) return false;
            if (curYear == issueDay.getYear() && curMonth == issueDay.getMonth() && curDay < issueDay.getDay())
                return false;
            // 再检查是否大于过期日期
            if (curYear > expireYear) return false;
            if (curYear == expireYear && curMonth > issueDay.getMonth()) return false;
            if (curYear == expireYear && curMonth == issueDay.getMonth() && curDay > issueDay.getDay())
                return false;
        }

        return true;
    }

    void print() override
    {
        cout << pName << endl;
        if (check())
        {
            cout << pId18 << " ";
            issueDay.print();
            cout << " ";
            if (validYear == 100)
                cout << "长期";
            else
                cout << validYear << "年";
            cout << endl;
        }
        else
        {
            cout << "illegal id" << endl;
        }
    }

    ~CNewId() {}
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string name;
        int year, month, day;
        string id15, id18;
        int iy, im, id;
        int valid;

        cin >> name >> year >> month >> day >> id15 >> id18 >> iy >> im >> id >> valid;

        CDate birth(year, month, day);
        CDate issue(iy, im, id);

        CNewId obj(id15, name, birth, id18, issue, valid);
        obj.print();
    }
    return 0;
}