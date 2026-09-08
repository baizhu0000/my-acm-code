#include <cstring>
#include <iostream>
using namespace std;

class CN;  // 提前声明
class EN;  // 提前声明

// 抽象类
class Weight {
   protected:
    string kind;  // 计重类型
    int gram;     // 克
   public:
    Weight(string t = "no name", int tg = 0) {
        kind = t;
        gram = tg;
    }
    virtual void print(ostream& out) = 0;  // 输出不同类型的计重信息
    virtual ~Weight() {}
};

// 中国计重
class CN : public Weight {
   private:
    int jin, liang, qian, ke;  // 斤、两、钱、剩余克

   public:
    // 构造函数：斤、两、钱、克、类型
    CN(int j = 0, int l = 0, int q = 0, int k = 0, string t = "中国计重")
        : Weight(t, k), jin(j), liang(l), qian(q), ke(k) {}

    // 计重转换：将克数转成中国计重
    void Convert(int grams) {
        gram = grams;
        int temp = grams;
        jin = temp / 500;
        temp %= 500;
        liang = temp / 50;
        temp %= 50;
        qian = temp / 5;
        ke = temp % 5;
    }

    // 设置中国计重（用于从英国计重转换）
    void setWeight(int j, int l, int q, int k) {
        jin = j;
        liang = l;
        qian = q;
        ke = k;
        gram = jin * 500 + liang * 50 + qian * 5 + ke;
    }

    // 重载赋值运算符：从英国计重转换
    CN& operator=(const EN& en);

    virtual void print(ostream& out) {
        out << kind << ":" << jin << "斤" << liang << "两"
            << qian << "钱" << ke << "克";
    }
};

// 英国计重
class EN : public Weight {
   private:
    int pound, ounce, dram, ke;  // 磅、盎司、打兰、剩余克

   public:
    // 构造函数：磅、盎司、打兰、克、类型
    EN(int p = 0, int o = 0, int d = 0, int k = 0, string t = "英国计重")
        : Weight(t, k), pound(p), ounce(o), dram(d), ke(k) {}

    // 计重转换：将克数转成英国计重
    void Convert(int grams) {
        gram = grams;
        int temp = grams;
        pound = temp / 512;
        temp %= 512;
        ounce = temp / 32;
        temp %= 32;
        dram = temp / 2;
        ke = temp % 2;
    }

    // 获取英国计重属性（供CN访问）
    int getPound() const { return pound; }
    int getOunce() const { return ounce; }
    int getDram() const { return dram; }
    int getKe() const { return ke; }

    virtual void print(ostream& out) {
        out << kind << ":" << pound << "磅" << ounce << "盎司"
            << dram << "打兰" << ke << "克";
    }

    // 声明CN为友元，以便CN可以访问EN的私有成员
    friend class CN;
};

// 中国计重的赋值运算符重载：从英国计重转换
CN& CN::operator=(const EN& en) {
    // 先将英国计重转换为总克数
    int totalGrams = en.pound * 512 + en.ounce * 32 + en.dram * 2 + en.ke;

    // 再转换为中国计重
    int temp = totalGrams;
    jin = temp / 500;
    temp %= 500;
    liang = temp / 50;
    temp %= 50;
    qian = temp / 5;
    ke = temp % 5;
    gram = totalGrams;
    kind = "中国计重";

    return *this;
}

// 以全局函数方式重载输出运算符
ostream& operator<<(ostream& out, Weight& w) {
    w.print(out);
    return out;
}

// 主函数
int main() {
    int tw;

    // 创建一个中国计重类对象cn
    CN cn(0, 0, 0, 0, "中国计重");
    cin >> tw;
    cn.Convert(tw);  // 把输入的克数转成中国计重
    cout << cn << endl;

    // 创建英国计重类对象en
    EN en(0, 0, 0, 0, "英国计重");
    cin >> tw;
    en.Convert(tw);  // 把输入的克数转成英国计重
    cout << en << endl;

    cn = en;  // 把英国计重转成中国计重
    cout << cn << endl;

    return 0;
}