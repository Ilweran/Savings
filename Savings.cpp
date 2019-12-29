//============================================================================
// Name        : Savings.cpp
// Author      : Whoever
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
  string name;
  double money;
  double rate;
  int time;
  double findValue(double m, double r, int t)
  {
    if(t==0)
    {
      return m;
    } 
    else
    {
      return findValue(m, r, t-1)* (1 + r/100);
    }
  }
  double total()
  {
    return findValue(money, rate, time);
  }

public:
  void set(string n,double m,double r,int t)
  {
    name=n; money=m; rate=r; time=t;
  }

  BankAccount(string n,double m,double r,int t)
  {
    set(n, m, r, t);
  }

  BankAccount()
  {
    set("Anonimus",0,0,0);
  }
  void show()
  {
    cout<<"Данные по банковскому счету.\n";
    cout<<"Вкладчик:\t"<<name<<endl;
    cout<<"Сумма:\t"<<money<<endl;
    cout<<"Ставка %:\t"<<rate<<endl;
    cout<<"Время:\t"<<time<<endl;
    cout<<"Всего:\t"<<total()<<endl;
    cout<<endl;
  }
  BankAccount operator+(int t)
  {

    BankAccount tmp;
    tmp.set(name,money,rate,time+t);
    return tmp;
  }
  BankAccount operator+(double m)
  {
    BankAccount tmp;
    tmp.set(name,money+m,rate,time);
    return tmp;
  }
  BankAccount operator*(double x)
  {
    BankAccount tmp;
    tmp.set(name,money,rate+x,time);
    return tmp;
  }
  double operator!()
  {
    return total();
  }
  double operator-(BankAccount tmp)
  {
    return total()-!tmp;
  }
};


int main() {
  BankAccount ivanov("ИвановИ.И.",100,12,3);
  ivanov.show();
  BankAccount fellow;
  fellow=ivanov+2;
  fellow.show();
  ((ivanov+25.0)*4).show();
  double dif=fellow-ivanov;
  cout<<"Разница итоговых сумм:\t"<<dif<<endl;
  return 0;
}
