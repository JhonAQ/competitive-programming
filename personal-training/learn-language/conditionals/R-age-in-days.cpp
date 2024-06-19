#include <iostream>

using namespace std;

int main()
{
  int days;
  cin >> days;

  int years = days / 365;
  days %= 365;
  int months = days / 30;
  days %= 30;
  cout << years << " years" << endl;
  cout << months << " months" << endl;
  cout << days << " days";
}