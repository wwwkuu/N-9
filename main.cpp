#include <iostream>
#include <string>
using namespace std;

// Функция для сравнения двух строк, представляющих числа
int compare(const string& a, const string& b) {
  if (a.size() > b.size()) return 1;
  if (a.size() < b.size()) return -1;
  return a.compare(b);
}

// Функция для вычитания двух строк, представляющих числа (предполагается, что a >= b)
string subtract(string a, const string& b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while(i >= 0 || j >= 0 || carry)
    {
        int digitA = (i >= 0) ? (a[i] - '0') : 0;
        int digitB = (j >= 0) ? (b[j] - '0') : 0;
        int sub = digitA - digitB - carry;
        if(sub < 0)
        {
           sub += 10;
           carry = 1;
        }
        else carry = 0;
        result = to_string(sub) + result;
        --i;
        --j;
    }
    // Стирание нулей
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0,1);
    }

    return result;
}

// Функция для вычисления остатка от деления a на b
string modulo(string a, const string& b) {
  if (compare(a, b) < 0) return a;
  if (a == b) return "0";
  string temp = a;

  while(compare(temp, b) >=0 )
  {
    string temp_b = b;
    int diff = temp.size() - temp_b.size();
    if(diff > 0)
    {
      temp_b.insert(temp_b.begin(),diff,'0');
    }
    if(compare(temp, temp_b) < 0)
    {
       temp_b.erase(0,1);
    }
    temp = subtract(temp, temp_b);
  }
  return temp;
}

// Функция для вычисления НОД двух больших чисел, представленных строками
string NOD(string a, string b) {
  while (b != "0") {
    string temp = modulo(a, b);
    a = b;
    b = temp;
  }
  return a;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string num1, num2;
    bool flag = true;
    while (flag) {
        cout << "Введите два целых числа не менее 10¹¹: ";
        cin >> num1 >> num2;
        flag = false;
        if (num1.size()<11 or num2.size()<11) flag = true;
        for (int i = 0; i<num1.size();i++) {
            if (isdigit(num1[i])==0) {
                flag = true;
                break;
            }
        }
        for (int i = 0; i<num2.size();i++) {
            if (isdigit(num2[i])==0) {
                flag = true;
                break;
            }
        }
        while (num1[0]=='0') num1.erase(0,1);
        while (num2[0]=='0') num2.erase(0,1);
        if (num1.size()<11 or num2.size()<11) flag = true;
        if (flag) cout<<"Неверный ввод!\n";
    }
    string result = NOD(num1, num2);
    if (result=="1") cout<<"Числа являются взаимно простыми\n";
    else cout<<"Числа не являются взаимно простыми\n";
    cout << "НОД(" << num1 << ", " << num2 << ") = " << result;
    return 0;
}
