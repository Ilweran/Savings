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
  double findValue(double m, double r, double t)
  {
    double res=m;
    for(int i=1; i<=t; i++)
      res=res*(1+r/100);
    return res;
  }
  void showTable(bool style=false)
  {
    cout<<"| Вкладчик\t"<<"| Сумма\t"<<"| Время\t";
    if(style)
    {
      cout<<"| Сумма\t"<<"| Время\t";
    }
    cout<<"| % \t"<<"| Всего |\n";
  }
  void showData(double m, int t)
  {
    cout<<"| "<<name<<"\t";
    cout<<"| "<<money<<"\t";
    cout<<"| "<<time<<"\t";
    cout<<"| "<<m<<"\t";
    cout<<"| "<<time-t<<"\t";
    cout<<"| "<<rate<<"\t";
    cout<<"| "<<result(m,t)<<" |\n";
    cout<<endl;
  }
  void showData()
  {
    cout << "| " << name << "\t";
    cout << "| " << money << "\t";
    cout << "| " << time << "\t";
    cout << "| " << rate << "\t";
    cout << "| " << result() << "\t";
    cout << endl;
  }
  double result()
  {
    return findValue(money, rate, time);
  }
  double result(double m, int t)
  {
    double m1, m2;
    m1=findValue(money,rate,time);
    if(t>time)
      {
	return m1;
      }
    else
      {
	m2=findValue(m,rate,time-t);
	return m1+m2;
      }
  }
public:
  void setAll(string n, double m, double r, int t)
  {
    name=n; money=m; rate=r; time=t;
  }
  void setAll(string n)
  {
    setAll(n, 100, 13, 3);
  }
  void setName(string n)
  {
    name=n;
  }

  void show(double m, int t)
  {
    showTable(true);
    showData(m, t);
  }
  void show(double m)
  {
    show(m, 1);
  }
  void show()
  {
    showTable();
    showData();
  }
  BankAccount(string name)
  {
    setAll(name);
    show();
  }
  // Конструктор класса (с 4 аргументами):
  BankAccount(string name, double m,double r,int t)
  {
    setAll(name, m, r, t);
    show();
  }

};


int main() {
  BankAccount ivanov("Ivanov I. I.");
  ivanov.show(30,2);
  ivanov.show(29);
  BankAccount petrov("Petrov P. P.",90,18,4);
  petrov.setAll("Sidorov S .S.");
  petrov.show();
  petrov.show(50,5);
  return 0;
}
