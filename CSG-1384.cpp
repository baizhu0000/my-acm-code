#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 中缀转后缀（逆波兰式）
string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";
    int i = 0;

    while (i < s.length())
    {
        char c = s[i];

        if (isdigit(c))
        {
            // 处理多位数
            while (i < s.length() && isdigit(s[i]))
            {
                result += s[i];
                i++;
            }
            result += ' '; // 空格分隔
            continue;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop(); // 弹出 '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!st.empty() && priority(st.top()) >= priority(c))
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
        i++;
    }

    while (!st.empty())
    {
        result += st.top();
        result += ' ';
        st.pop();
    }

    return result;
}

// 中缀转前缀（波兰式）
string infixToPrefix(string s)
{
    // 反转字符串
    reverse(s.begin(), s.end());

    // 交换括号
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    // 得到反转后的后缀表达式
    string postfix = infixToPostfix(s);

    // 反转得到前缀
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string expr;
        cin >> expr;

        string prefix = infixToPrefix(expr);
        string postfix = infixToPostfix(expr);

        cout << prefix << endl;
        cout << postfix << endl;
        if (t != T - 1)
            cout << endl;
    }

    return 0;
}