//
//  main.cpp
//  BracketMatching
//
//  Created by 彭 on 2017/10/11.
//  Copyright © 2017年 彭. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
// 1  表示 Yes
// 0  表示 No
// -1 表示 UnKnown

int main(){
    int i = 0;
    int num = 0;
    bool IsNoMatch = false;
    string str;
    struct stack
    {
        int len;
        string element;
    } SysmStack;  // 栈 后进先出  i 记录 栈顶元素
    
    SysmStack.len = 0;
    cout << "请输入实验次数: " ;
    cin >> num;
    
    
    for (int j = 0; j < num; ++j)
    {
        i = 0;
        SysmStack.len = 0;
        IsNoMatch = true;
        
        cout << "第 " << j+1 << " 次实验，请输入一串字符: ";
        cin >> str;
        
        while (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}'){
            
            IsNoMatch = true;
            
            switch (str[i])
            {
                case '[':  // 入栈
                case '(':
                case '{':
                    SysmStack.element[SysmStack.len] = str[i];
                    SysmStack.len ++;
                    break;
                case ']':
                    if (SysmStack.element[SysmStack.len-1] == '[') {
                        // 出栈
                        SysmStack.element[SysmStack.len-1] = '\0';
                        SysmStack.len--;
                    }
                    else {
                        // 输出 No
                        IsNoMatch = false;
                        break;
                    }
                    break;
                case ')':
                    if (SysmStack.element[SysmStack.len-1] == '(') {
                        // 出栈
                        SysmStack.element[SysmStack.len-1] = '\0';
                        SysmStack.len--;
                    }
                    else {
                        // 输出 No
                        IsNoMatch = false;
                        break;
                    }
                    break;
                case '}':
                    if (SysmStack.element[SysmStack.len-1] == '{') {
                        // 出栈
                        SysmStack.element[SysmStack.len-1] = '\0';
                        SysmStack.len--;
                    }
                    else {
                        // 输出 No
                        IsNoMatch = false;
                        break;
                    }
                    break;
            }
            i++;
            
            if (!IsNoMatch) {
                break;
            }
        }
        if (IsNoMatch && SysmStack.len == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

