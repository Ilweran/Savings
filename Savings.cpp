//============================================================================
// Name        : Savings.cpp
// Author      : ANVasilyev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
//Pretty silly change
class BankAccount
{
// Открытые члены класса:
private:
  string name;
  double money;
  double rate;
  int time;
public:
  void set(double m=100, double r=13, int t=3)
  {
    money=m; rate=r; time=t;
  }
  void setName(string n)
  {
    name=n;
  }
  double result(){
    double res=money;
    int i;
    for(i=1;i<=time;i++)
      {
        res=res*(1+rate/100);
      }
    return res;
  }
  void show()
  {
    cout<<name;
    cout<<": "<<money<<": "<<rate<<": "<<time;
    cout<<": "<<result()<<endl;
  }
  BankAccount(string name)
  {
    setName(name);
    set();
    show();
  }
  // Конструктор класса (с тремя аргументами): 
  BankAccount(string name, double m,double r,int t)
  {
    setName(name);
    set(m,r,t);
    show();
  }

};


int main() {
  BankAccount ivanov("Ivanov Ivan");
  BankAccount petrov("Petrov Petro",90,18,4);
  return 0;
}
