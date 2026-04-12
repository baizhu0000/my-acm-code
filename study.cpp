#include <iostream>
#include <vector>
#include <algorithm>  // 用于 reverse
using namespace std;

// 定义大整数结构体
struct Bigint {
    vector<int> digits;  // 从低位到高位存储数字，digits[0] 是个位
    
    // 构造函数：从整数初始化
    Bigint(int x = 0) {
        if (x == 0) {
            digits.push_back(0);
        } else {
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
        }
    }
    
    // 构造函数：从字符串初始化（可选）
    Bigint(string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            digits.push_back(s[i] - '0');
        }
        // 去除前导零（除了数字0本身）
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }
    
    // 加法运算符重载
    Bigint operator+(const Bigint& other) const {
        Bigint result;
        result.digits.clear();
        
        int carry = 0;
        int max_len = max(digits.size(), other.digits.size());
        
        for (int i = 0; i < max_len; i++) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        
        if (carry > 0) {
            result.digits.push_back(carry);
        }
        
        return result;
    }
    
    // 打印函数
    void print() const {
        for (int i = digits.size() - 1; i >= 0; i--) {
            cout << digits[i];
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    // 特殊情况处理
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }
    if (n == 2) {
        cout << "2" << endl;
        return 0;
    }
    
    // 动态分配数组，避免栈溢出（如果 n 很大）
    Bigint* f = new Bigint[n + 10];
    
    f[1] = Bigint(1);
    f[2] = Bigint(2);
    
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 1];
    }
    
    f[n].print();
    cout << endl;
    
    delete[] f;  // 释放内存
    return 0;
}