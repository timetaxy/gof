#include <iostream>
#include <list>
#include <string>
using namespace std;

class Account {
  public :
    Account(string n) { 
      customerName_ = n; 
      netMoney_ = 0;
    }
    virtual int GetTotalSum() = 0;
    list<int> GetHistory() { return history_; }
    string GetCustomerName() { return customerName_; }
    void Deposit(int inMoney) { 
      netMoney_ += inMoney; 
      history_.push_back(inMoney);
    }
    void Withdraw(int outMoney) { 
      netMoney_ -= outMoney; 
      history_.push_back(-outMoney);
    }

    virtual void TotalSumReport() = 0;
    virtual void HistoryReport() = 0;
  protected :
    int netMoney_;
    list<int> history_; // -- ����� �Ա�, ������ ����� �ǹ�
    string customerName_;
};

class PassbookAccount : public Account {
  public :
    PassbookAccount(string n) : Account(n) {}
    int GetTotalSum() { 
      return netMoney_; // -- ���� ���� ����.
    }

    void TotalSumReport() {
      cout << GetCustomerName() 
            << "���� PassbookAccount Total Sum : " 
            << GetTotalSum() << endl;
    }
    void HistoryReport() {
      cout << GetCustomerName() 
            << "���� PassbookAccount ����� ���� : " << endl;
      list<int>::iterator iter;
      for (iter=history_.begin(); iter != history_.end(); iter++) 
        cout << *iter << endl;
      cout << endl;
    }
};

class CheckingAccount : public Account {
  public :
    CheckingAccount(string n) : Account(n) {}
    int GetTotalSum() {
      return netMoney_ + lround(netMoney_ * 0.1); // -- 10% ����
    }

    void TotalSumReport() {
      cout << GetCustomerName() 
            << "���� CheckingAccount Total Sum : " 
            << GetTotalSum() << endl;
    }
    void HistoryReport() {
      cout << GetCustomerName() 
            << "���� CheckingAccount ����� ���� : " << endl;
      list<int>::iterator iter;
      for (iter=history_.begin(); iter != history_.end(); iter++) 
        cout << *iter << endl;
      cout << endl;
    }
};

// ----------------------------------------------

void DoTotalSumReport(list<Account *>& accountList) {
  list<Account *>::iterator iter;
  for (iter=accountList.begin(); iter != accountList.end(); iter++)
    (*iter)->TotalSumReport();
}

void DoHistoryReport(list<Account *>& accountList) {
  list<Account *>::iterator iter;
  for (iter=accountList.begin(); iter != accountList.end(); iter++)
    (*iter)->HistoryReport();
}

int 
main()
{
  PassbookAccount a("����"), b("ö��");
  CheckingAccount c("�ƺ�"), d("����");

  list<Account *> accountList;
  accountList.push_front(&a);
  accountList.push_front(&b);
  accountList.push_front(&c);
  accountList.push_front(&d);

  a.Deposit(1000); 
  b.Deposit(2000);
  c.Deposit(3000);
  d.Deposit(4000);

  DoTotalSumReport(accountList);
  cout << endl;

  a.Withdraw(500);
  c.Withdraw(1000);

  DoHistoryReport(accountList);
  cout << endl;
  DoTotalSumReport(accountList);
}