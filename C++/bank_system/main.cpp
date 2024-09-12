#include <iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <vector>
using namespace std;
using namespace chrono;
time_point<system_clock> now = system_clock::now();

struct StockShare {
    int quantity;
    float fullPrice;
    string nameOfCompany;
};

struct Transaction {
  string type;
  float amount;
  string timestamp;
};

struct User {
    string name;
    bool isLogged;
    int cpf;
    int password;
    float saldo;
    float saldoInvested;
    vector<StockShare> stockShare;
    vector<Transaction> transactions;
};

struct CompanyStockMarket {
    string name;
    float pricePerStockShare;
    int quantityOfStockShare;
};

string timePointToString(const time_point<system_clock> &time_point) {
    // Converte o time_point para time_t
    time_t t = system_clock::to_time_t(time_point);

    // Converte time_t para tm struct
    tm* tm_ptr = localtime(&t);

    // Usa um stringstream para formatar a data e a hora
    ostringstream oss;
    oss << put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

bool checkPassword(int password) {
  if(password > 9999 || password < 999 ) {
    (void)system("cls");
    cout<<"THE PASSWORD MUST HAVE 4 DIGITS"<<endl;
    return true;
  }
  return false;
}

void createAccount(vector<User>& usuarios) {
    bool checkinPassword = true;
    cout << "WRITE YOUR NAME: ";
    User newUser;
    cin >> newUser.name;

    cout << "WRITE YOUR CPF: ";
    cin >> newUser.cpf;
    while(checkinPassword) {
      cout << "WRITE YOUR PASSWORD: ";
      cin >> newUser.password;
      checkinPassword = checkPassword(newUser.password);
    }
    cout << "PUT YOUR INITIAL AMOUNT OF MONEY: ";
    cin >> newUser.saldo;

    // Initialize other attributes
    newUser.saldoInvested = 0;
    newUser.isLogged = false;

    // Add the new user to the vector
    usuarios.push_back(newUser);
}

bool checkIsLogged(int cpf, vector<User>& usuarios) {
  int password = 0, tries = 4;
  bool logging = true;
  bool found = false;
  
  for(int i = 0; i < usuarios.size(); i++) {
    if(usuarios.at(i).cpf == cpf) {
      while(logging) {
        cout<<"WRITE YOUR PASSWORD: ";
        cin>>password;
        if(usuarios.at(i).password != password) {
          cout<<"THIS PASSWORD IS WRONG"<<endl;
          if(tries == 1) {
            return false;
          }
          tries--;
          cout<<"YOU HAVE MORE "<<tries<<" TRIES"<<endl;
          
        }
        if(usuarios.at(i).password == password) {
          usuarios.at(i).isLogged = true;
          return true;
        }
      }
    }
    cout<<"CPF NOT FOUND";
  }
}

void depositMoney(int cpf, vector<User>& usuarios) {
  (void)system("cls");
  Transaction transaction;
  bool isLogged = checkIsLogged(cpf, usuarios);
  if(!isLogged) return;
  
    float money = 0;
    for(int i = 0; i < usuarios.size(); i++) {
        if(usuarios.at(i).cpf == cpf) {
            cout<<"WRITE HOW MUCH MONEY DO YOU WANT TO DEPOSIT: ";
            cin>>money;
            usuarios.at(i).saldo += money;
            cout<<endl<<usuarios.at(i).name<<", YOUR BALANCE IS NOW: "<<usuarios.at(i).saldo<<endl<<endl;
            transaction.amount = money;
            transaction.type = "DEPOSIT";
            transaction.timestamp = timePointToString(now);
            usuarios.at(i).transactions.push_back(transaction);
        }    
    }
}

void withdrawMoney(int cpf, vector<User>& usuarios) {
  (void)system("cls");
  Transaction transaction;
  bool isLogged = checkIsLogged(cpf, usuarios);
  if(!isLogged) return;
    float money = 0;
    for(int i = 0; i < usuarios.size(); i++) {
        if(usuarios.at(i).cpf == cpf) {
            cout<<"WRITE HOW MUCH MONEY DO YOU WANT TO WITHDRAW: ";
            cin>>money;
            if(money > usuarios.at(i).saldo) {
                cout<<"THIS QUANTITY IS MORE THAN YOUR BALANCE"<<endl<<endl;
                break;
            } else {
                usuarios.at(i).saldo -= money;
                cout<<endl<<usuarios.at(i).name<<", YOUR BALANCE IS NOW: "<<usuarios.at(i).saldo<<endl<<endl;
                transaction.amount = money;
                transaction.type = "WITHDRAW";
                transaction.timestamp = timePointToString(now);
                usuarios.at(i).transactions.push_back(transaction);
            }
        }
    }
}

float investInCompany(float &balance, float &saldoInvested, int companyIndex, vector<CompanyStockMarket>& companies) {
  (void)system("cls");
    int quantity = 0;
    float totalMoney = 0;
    bool isRunning = true;
    while(isRunning) {
        cout<<"THE PRICE PER STOCK SHARE OF THE COMPANY: "<<companies[companyIndex].name<<" IS: "<<companies[companyIndex].pricePerStockShare<<endl;
        cout<<"HOW MUCH DO YOU WANT TO BUY? "<<endl;
        cin>>quantity;
        if(quantity > companies[companyIndex].quantityOfStockShare) {
            cout<<"YOU CAN'T BUY MORE STOCK SHARES THAN THE COMPANY HAS"<<endl;
            break;
        }
        totalMoney = quantity * companies[companyIndex].pricePerStockShare;
        if(totalMoney > balance) {
            cout<<"YOU CAN'T BUY MORE STOCK SHARES THAN YOUR BALANCE"<<endl;
            break;
        }
        balance -= totalMoney;
        saldoInvested += totalMoney;
        return totalMoney;
    }
    return 0;
}

void updateInformations(int indexUsuario, int indexCompany, int quantity, float moneySpended, vector<User>& usuarios,  vector<CompanyStockMarket>& companies) {
    StockShare stockShares;
    stockShares.quantity = quantity;
    stockShares.fullPrice = moneySpended;
    stockShares.nameOfCompany = companies.at(indexCompany).name;
    usuarios.at(indexUsuario).stockShare.push_back(stockShares);
    companies.at(indexCompany).quantityOfStockShare -= quantity;
}

void investMoney(int cpf, vector<User>& usuarios, vector<CompanyStockMarket>& companies) {
  (void)system("cls");
  Transaction transaction;
  bool isLogged = checkIsLogged(cpf, usuarios);
  if(!isLogged) return;
    int indexCompany = 0;
    float moneySpended = 0;
    int quantity = 0;
    for(int indexUsuario = 0; indexUsuario < usuarios.size(); indexUsuario++) {
        if(usuarios.at(indexUsuario).cpf == cpf) {
                cout<<"WHICH COMPANY DO YOU WANT TO INVEST IN: "<<endl<<endl;
                for(int indexCompany = 0; indexCompany < companies.size(); indexCompany++) {
                    cout<<"DIGIT "<<indexCompany<<" TO INVEST IN: "<<companies.at(indexCompany).name<<endl;
                }
                cin>>indexCompany;
                moneySpended = investInCompany(usuarios.at(indexUsuario).saldo, usuarios.at(indexUsuario).saldoInvested, indexCompany, companies);
                quantity = moneySpended / companies.at(indexCompany).pricePerStockShare;
                updateInformations(indexUsuario, indexCompany, quantity, moneySpended, usuarios, companies);
                
                cout<<"YOU BOUGHT: "<<moneySpended<<" US$ IN ACTIONS OF THE: "<<companies.at(indexCompany).name<<endl;
                cout<<"NOW YOUR BALANCE IS: "<<usuarios.at(indexUsuario).saldo<<" US$"<<endl<<endl;
                transaction.amount = moneySpended;
                transaction.type = "INVESTMENT";
                transaction.timestamp = timePointToString(now);
                usuarios.at(indexUsuario).transactions.push_back(transaction);
        }
    }
}

void seeYourInvestments(int cpf, vector<User>& usuarios) {
  (void)system("cls");
  bool isLogged = checkIsLogged(cpf, usuarios);
  if(!isLogged) return;
    for(int i = 0; i < usuarios.size(); i++) {
        if(usuarios.at(i).cpf == cpf) {
            cout<<"YOU HAVE: "<<usuarios.at(i).saldoInvested<<"US$ IN STOCK SHARE MARKET"<<endl;
            cout<<"LIST OF INVESTMENTS: "<<endl;
            cout<<"-------------------------------------------"<<endl;
            for(int j = 0; j < usuarios.at(i).stockShare.size(); j++) {
                cout<<"NAME OF COMPANY: "<<usuarios.at(i).stockShare.at(j).nameOfCompany<<endl;
                cout<<"QUANTITY OF STOCK SHARES: "<<usuarios.at(i).stockShare.at(j).quantity<<endl;
                cout<<"MONEY SPENDED: "<<usuarios.at(i).stockShare.at(j).fullPrice<<endl;
                cout<<"-------------------------------------------"<<endl;
            }
            break;
        }
    }
}

void seeYourTransactions(int cpf, vector<User>& usuarios) {
  (void)system("cls");
  bool isLogged = checkIsLogged(cpf, usuarios);
  if(!isLogged) return;
  
  for(int i = 0; i < usuarios.size(); i++) {
        if(usuarios.at(i).cpf == cpf) {
            cout<<"LIST OF TRANSACTIONS: "<<endl;
            cout<<"-------------------------------------------"<<endl;
            for(int j = 0; j < usuarios.at(i).transactions.size(); j++) {
                cout<<"TYPE: "<<usuarios.at(i).transactions.at(j).type<<endl;
                cout<<"MONEY: "<<usuarios.at(i).transactions.at(j).amount<<endl;
                cout<<"DATE: "<<usuarios.at(i).transactions.at(j).timestamp<<endl;
                cout<<"-------------------------------------------"<<endl;
            }
            break;
        }
    }
}

int main() {
    bool isRunning = true;
    int opt = 0, cpf = 0;
    vector<CompanyStockMarket> companies = {
        {"BANK", 5.5, 200},
        {"ENERGY", 15, 200},
        {"INTEL", 30, 200},
        {"APPLE", 25, 200},
        {"NVIDIA", 10, 200},
    };
    vector<User> usuarios;
    
    while(isRunning) {
        cout<<"OPTION 0 - CREATE ACCOUNT"<<endl;
        cout<<"OPTION 1 - DEPOSIT MONEY"<<endl;
        cout<<"OPTION 2 - WITHDRAW MONEY"<<endl;
        cout<<"OPTION 3 - INVEST MONEY"<<endl;
        cout<<"OPTION 4 - SEE YOUR INVESTMENTS"<<endl;
        cout<<"OPTION 5 - SEE YOUR TRANSACTIONS"<<endl;
        cout<<"OPTION 6 - LEAVE"<<endl;
        cin>>opt;
        
        switch(opt) {
            case 0:
                createAccount(usuarios);
            break;
            case 1:
                cout<<"WRITE YOUR CPF: ";
                cin>>cpf;
                depositMoney(cpf, usuarios);
            break;
            case 2:
                cout<<"WRITE YOUR CPF: ";
                cin>>cpf;
                withdrawMoney(cpf, usuarios);
            break;
            case 3:
                cout<<"WRITE YOUR CPF: ";
                cin>>cpf;
                investMoney(cpf, usuarios, companies);
            break;
            case 4: 
                cout<<"WRITE YOUR CPF: ";
                cin>>cpf;
                seeYourInvestments(cpf, usuarios);
            break;
            case 5:
              cout<<"WRITE YOUR CPF: ";
                cin>>cpf;
                seeYourTransactions(cpf, usuarios);
            break;
            case 6:
                cout<<"LEAVING...";
                isRunning = false;
            break;
        }
    }
    return 0;
}