#include <iostream>
#include <cmath>
using namespace std;
void vvod(long long int& M, long long int& N) {
    while (true){                       //ввод чисел
        cin>>M>>N;
        if (M > pow(10,11) and N > pow(10,11)) {
            break;
        }
        else cout<<"Ошибка ввода! Введите числа m и n больше 10¹¹: ";
    }
}

void NOD(long long int& M, long long int& N) {
    while (M != 0 and N != 0) {       //нахождение НОД
        if (M > N)
            M %= N;
        else
            N %= M;
        }   
}


int main()
{
    setlocale(LC_ALL, "Russian");
    long long int m,n,m1,n1;
    cout<<"Введите m и n: ";
    vvod(m,n);
    m1=m;
    n1=n;
    NOD(m1,n1);
    if (n1 + m1 == 1) cout<<"Числа "<<m<<" и "<<n<<" являются взаимно простыми\nНОД = "<<(n1+m1);
    else cout<<"Числа "<<m<<" и "<<n<<" не являются взаимно простыми\nНОД = "<<(n1+m1);
    return 0;
}